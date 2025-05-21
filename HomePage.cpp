#include "HomePage.h"
#include "ui_HomePage.h"
#include "ui_loginPage.h"
#include <iostream>
#include <QWidget>
#include <QStackedWidget>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QRandomGenerator>
#include <QPushButton>
#include <QMouseEvent>
#include <QList>
#include <QLineEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QLineF>
#include <QString>
#include <QTimer>
#include <QEventLoop>
#include "UserManager.h"
#define g  UserManager::user->g

HomePage::HomePage(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.addnode, &QPushButton::clicked, this, &HomePage::addCity);
    connect(ui.pushButton, &QPushButton::clicked, this, &HomePage::addEdge);
    connect(ui.dfs, &QPushButton::clicked, this, &HomePage::dfs);
    connect(ui.bfs, &QPushButton::clicked, this, &HomePage::bfs);
    connect(ui.deleteNode, &QPushButton::clicked, this, &HomePage::deleteCity);
    connect(ui.deleteEdge, &QPushButton::clicked, this, &HomePage::deleteEdge);
    connect(ui.dijkstra, &QPushButton::clicked, this, &HomePage::dijkstra);
    connect(ui.floyd_warshall, &QPushButton::clicked, this, &HomePage::floyd_warshall);



    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        for (auto& [name, node] : g.namesAndNodes) {
            auto it = nodeGroups.find(node.id);
            if (it == nodeGroups.end() || !it->second) continue;

            QPointF currentPos = it->second->pos();
            auto pos_it = nodePositions.find(node.id);
            if (pos_it == nodePositions.end() || currentPos != pos_it->second) {
                updateEdges(&node);
                nodePositions[node.id] = currentPos;
            }
        }
        });
    timer->start(10);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 500, 500);
    ui.graph->setScene(scene);
    ui.graph->setRenderHint(QPainter::Antialiasing);
    ui.graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    initialization();
}

HomePage::~HomePage() {
    for (auto& [id, group] : nodeGroups) {
        delete group;
    }
    for (auto& edge : guiEdges) {
        delete edge.line;
        delete edge.weightLabel;
        delete edge.arrowHead;
    }
}

void HomePage::resetLineEdit(QLineEdit* lineEdit , const QString text)
{
    lineEdit->clear();
    lineEdit->setStyleSheet(
        "QLineEdit { background-color: white; color: black; } "
        "QLineEdit::placeholder { color: #555555; }"
    );
    lineEdit->setPlaceholderText(text);
}

void HomePage::setLineEditError(QLineEdit* lineEdit, const QString& errorMessage)
{
    lineEdit->clear();
    lineEdit->setStyleSheet(
        "QLineEdit { background-color: white; color: black; border: 1px solid red; border-radius: 5px; } "
        "QLineEdit::placeholder { color: #555555; }"
    );
    lineEdit->setPlaceholderText(errorMessage);
}

void HomePage::initialization() {
    for (auto& node : g.adj) {
        createNode(*g.idsAndNodes[node.first]);
    }

    scene->update();
    QApplication::processEvents();

    for (auto& node : g.adj) {
        for (auto& edg : node.second) {
            createEdge(g.idsAndNodes[node.first], g.idsAndNodes[edg.to->id], edg.weight);
        }
    }

    for (auto& [name, node] : g.namesAndNodes) {
        updateEdges(&node);
    }
}

void HomePage::createNode(Node& node) {
    int radius = 25;
    double mult = (node.name.size() >= 4) ? (node.name.size() / 5.0) : 1;
    double diameter = mult * radius * 2;

    int x = QRandomGenerator::global()->bounded(0, 400);
    int y = QRandomGenerator::global()->bounded(0, 400);

    QColor customBlue("#003FFF");
    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(0, 0, diameter, diameter);
    ellipse->setBrush(QBrush(customBlue));
    ellipse->setPen(QPen(customBlue));

    QString qstr = QString::fromStdString(node.name);
    QGraphicsTextItem* text = new QGraphicsTextItem(qstr);
    QFont font;
    font.setPointSize(11);
    text->setFont(font);
    text->setDefaultTextColor(Qt::white);

    QRectF textRect = text->boundingRect();
    text->setPos((diameter - textRect.width()) / 2, (diameter - textRect.height()) / 2);

    QGraphicsItemGroup* group = new QGraphicsItemGroup();
    group->addToGroup(ellipse);
    group->addToGroup(text);
    group->setPos(x, y);
    group->setFlag(QGraphicsItem::ItemIsMovable);
    group->setFlag(QGraphicsItem::ItemIsSelectable, false);

    group->setZValue(1);
    scene->addItem(group);
    nodeGroups[node.id] = group;
    nodePositions[node.id] = group->pos();
}

void HomePage::addCity() {
    QString inputText = ui.nodename->text().trimmed().toLower();
    string node = inputText.toStdString();

    if (inputText.isEmpty())
    {
        setLineEditError(ui.nodename, "Input required");
        return;
    }
    if (g.is_city_exist(node))
    {
        setLineEditError(ui.nodename, "City Exist");
        return;
    }

    resetLineEdit(ui.nodename);
    g.add_city(node);
    Node& currentnode = g.namesAndNodes[node];
    createNode(currentnode);
}

void HomePage::deleteCity() {
    QString inputText = ui.nodename->text().trimmed().toLower();
    string node = inputText.toStdString();

    if (inputText.isEmpty())
    {
        setLineEditError(ui.nodename, "Input required");
        return;
    }
    if (!g.is_city_exist(node))
    {
        setLineEditError(ui.nodename, "City Doesn't Exist");
        return;
    }

    int city_id = g.namesAndNodes[node].id;
    for (auto it = guiEdges.begin(); it != guiEdges.end();) {
        if (it->from->id == city_id || it->to->id == city_id) {
            scene->removeItem(it->line);
            scene->removeItem(it->weightLabel);
            scene->removeItem(it->arrowHead);
            delete it->line;
            delete it->weightLabel;
            delete it->arrowHead;
            it = guiEdges.erase(it);
        }
        else {
            ++it;
        }
    }

    auto group_it = nodeGroups.find(city_id);
    if (group_it != nodeGroups.end()) {
        scene->removeItem(group_it->second);
        delete group_it->second;
        nodeGroups.erase(group_it);
    }

    nodePositions.erase(city_id);
    g.delete_city(node);
    resetLineEdit(ui.nodename);
}

void HomePage::createEdge(Node* from, Node* to, int weight) {
    int multiEdgeCount = 0;
    for (const GuiEdge& e : guiEdges) {
        if ((e.from == from && e.to == to) || (e.from == to && e.to == from)) {
            multiEdgeCount++;
        }
    }

    GuiEdge newEdge;
    newEdge.from = from;
    newEdge.to = to;
    newEdge.weight = weight;
    newEdge.multiEdgeIndex = multiEdgeCount;

    QPointF p1 = nodeGroups[from->id]->scenePos() + QPointF(25, 25);
    QPointF p2 = nodeGroups[to->id]->scenePos() + QPointF(25, 25);

    // Adjust offset to support more than two edges
    const double baseOffset = 30;
    double offset = baseOffset * (multiEdgeCount + 1) * (multiEdgeCount % 2 == 0 ? 1 : -1);
    QPointF controlPoint = (p1 + p2) / 2 + QPointF(0, offset);

    QPainterPath path;
    path.moveTo(p1);
    path.quadTo(controlPoint, p2);

    newEdge.line = new QGraphicsPathItem(path);
    newEdge.line->setPen(QPen(Qt::black, 2));

    double angle = atan2(p2.y() - controlPoint.y(), p2.x() - controlPoint.x());
    const double arrowSize = 15;
    QPointF tip = p2 - QPointF(cos(angle) * 25, sin(angle) * 25);

    QPointF arrowP1 = tip - QPointF(cos(angle) * arrowSize - sin(angle) * arrowSize / 2,
        sin(angle) * arrowSize + cos(angle) * arrowSize / 2);
    QPointF arrowP2 = tip - QPointF(cos(angle) * arrowSize + sin(angle) * arrowSize / 2,
        sin(angle) * arrowSize - cos(angle) * arrowSize / 2);
    QPolygonF arrowHead;
    arrowHead << tip << arrowP1 << arrowP2;

    newEdge.arrowHead = scene->addPolygon(arrowHead, QPen(Qt::black), QBrush(Qt::black));

    newEdge.weightLabel = scene->addText(QString::number(weight));
    QPointF midPoint = path.pointAtPercent(0.4);
    int offsetDirection = (multiEdgeCount % 2 == 0) ? 1 : -4;
    int offsetDirection2 = ((p1.x() - p2.x() > 0 && p1.y() - p2.y() > 0) || (p2.x() - p1.x() > 0 && p2.y() - p1.y() > 0)) ? -3 : 1;
    if (offsetDirection == -4 && offsetDirection2 == -3)
        offsetDirection = -1;
    newEdge.weightLabel->setPos(midPoint.x() + 10 * offsetDirection * offsetDirection2, midPoint.y());
    newEdge.weightLabel->setDefaultTextColor(Qt::black);

    scene->addItem(newEdge.line);

    guiEdges.push_back(newEdge);
}

void HomePage::addEdge() {
    QString firstcity = ui.firstcity->text().trimmed().toLower();
    QString secondcity = ui.secondcity->text().trimmed().toLower();
    if (firstcity == secondcity)
    {
        setLineEditError(ui.firstcity, "Invalid Node");
        setLineEditError(ui.secondcity, "Invalid Node");
        setLineEditError(ui.distance);
        return;
    }
    QString distance = ui.distance->text().trimmed();

    string first = firstcity.toStdString();
    string second = secondcity.toStdString();
    int weight = distance.toInt();

    bool dontContinue = 0;
    if (firstcity.isEmpty()) 
    {
        setLineEditError(ui.firstcity, "Input required");
        dontContinue = 1;
    }
    if (secondcity.isEmpty()) 
    {
        setLineEditError(ui.secondcity, "Input required");
        dontContinue = 1;
    }
    if (distance.isEmpty()) 
    {
        setLineEditError(ui.distance, "Input required");
        dontContinue = 1;
    }
    if (dontContinue) {
        return;
    }

    if (!g.is_city_exist(first)) 
    {
        setLineEditError(ui.firstcity, "City does not exist");
        dontContinue = 1;
    }
    if (!g.is_city_exist(second)) 
    {
        setLineEditError(ui.secondcity, "City does not exist");
        dontContinue = 1;
    }
    if (dontContinue)
        return;
    
    if (weight <= 0) {
        setLineEditError(ui.distance, "Invalid weight");
        return;
    }

    g.add_edge(first, second, weight);
	int id_u = g.get_node_id(first);
	int id_v = g.get_node_id(second);
    createEdge(&g.namesAndNodes[first], &g.namesAndNodes[second], weight);
    resetLineEdit(ui.firstcity);
    resetLineEdit(ui.secondcity);
    resetLineEdit(ui.distance,"Distance");
}

void HomePage::deleteEdge() {
    QString firstcity = ui.firstcity->text().trimmed().toLower();
    QString secondcity = ui.secondcity->text().trimmed().toLower();
    QString distance = ui.distance->text().trimmed();

    string first = firstcity.toStdString();
    string second = secondcity.toStdString();
    int weight = distance.toInt();

    bool dontContinue = 0;
    if (firstcity.isEmpty())
    {
        setLineEditError(ui.firstcity, "Input required");
        dontContinue = 1;
    }
    if (secondcity.isEmpty())
    {
        setLineEditError(ui.secondcity, "Input required");
        dontContinue = 1;
    }
    if (distance.isEmpty())
    {
        setLineEditError(ui.distance, "Input required");
        dontContinue = 1;
    }
    if (dontContinue) {
        return;
    }

    if (!g.is_city_exist(first))
    {
        setLineEditError(ui.firstcity, "City does not exist");
        dontContinue = 1;
    }
    if (!g.is_city_exist(second))
    {
        setLineEditError(ui.secondcity, "City does not exist");
        dontContinue = 1;
    }
    if (dontContinue)
        return;

    if (weight <= 0) {
        setLineEditError(ui.distance, "Invalid weight");
        return;
    }

    int id_u = g.get_node_id(first);
    int id_v = g.get_node_id(second);
    bool found = false;
    for (auto it = guiEdges.begin(); it != guiEdges.end();) {
        if ((it->from->id == id_u && it->to->id == id_v && it->weight == weight)) {
            scene->removeItem(it->line);
            scene->removeItem(it->weightLabel);
            scene->removeItem(it->arrowHead);
            delete it->line;
            delete it->weightLabel;
            delete it->arrowHead;
            it = guiEdges.erase(it);
            found = true;
            break;
        }
        else {
            ++it;
        }
    }

    if (!found)
    {
		setLineEditError(ui.firstcity, "Edge does not exist");
		setLineEditError(ui.secondcity, "Edge does not exist");
		setLineEditError(ui.distance,"Distance");
		return;
    }

    g.delete_edge(first, second, weight);
    resetLineEdit(ui.firstcity);
    resetLineEdit(ui.secondcity);
    resetLineEdit(ui.distance,"Distance");
}

void HomePage::dfs() {
    QString inputText = ui.firstcity->text().trimmed();
    string node = inputText.toStdString();
    if (inputText.isEmpty()) {
        setLineEditError(ui.firstcity, "Input required");
        return;
    }
    if (!g.is_city_exist(node)) {
        setLineEditError(ui.firstcity, "City does not exist");
        return;
    }
    vector<string> q = g.dfs(node);
    for (const auto& city : q) {
        changeColor(g.namesAndNodes[city], "#29C4F8");
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
    }
    resetColor();
}

void HomePage::bfs() {
    QString inputText = ui.firstcity->text().trimmed();
    string node = inputText.toStdString();
    if (inputText.isEmpty()) {
        setLineEditError(ui.firstcity, "Input required");
        return;
    }
    if (!g.is_city_exist(node)) {
        setLineEditError(ui.firstcity, "City does not exist");
        return;
    }

    vector<string> q = g.bfs(node);
    for (const auto& city : q) {
        changeColor(g.namesAndNodes[city], "#29C4F8");
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
    }
    resetColor();
}

void HomePage::dijkstra() {
    QString firstcity = ui.firstcity->text().trimmed().toLower();
    QString secondcity = ui.secondcity->text().trimmed().toLower();
    
    string first = firstcity.toStdString();
    string second = secondcity.toStdString();

    bool two_cities_exist = true;
    if (firstcity.isEmpty()) {
        setLineEditError(ui.firstcity, "Input required");
        two_cities_exist = false;
    }
    else if (!g.is_city_exist(first)) {
        setLineEditError(ui.firstcity, "City does not exist");
        two_cities_exist = false;
    }

    if (secondcity.isEmpty()) {
        setLineEditError(ui.secondcity, "Input required");
        two_cities_exist = false;
    }
    else if (!g.is_city_exist(second)) {
        setLineEditError(ui.secondcity, "City does not exist");
        two_cities_exist = false;
    }

    if (!two_cities_exist) {
        return;
    }

    auto [path,shortest_path_distance] = g.dijkstra(first, second);

    if (shortest_path_distance == LLONG_MAX)
    {
        ui.shortestPath->setText("No path exist!");
        return;
    }

    string output = "Shortest path: " + QString::number(shortest_path_distance).toStdString() + "\n";

	for (int i = 0; i < path.size(); i++)
		output += (i) ? " => " + path[i] : path[i];

    ui.shortestPath->setText(QString::fromStdString(output));

    for (int i = 0; i < path.size(); i++) {
        changeColor(g.namesAndNodes[path[i]], "#29C4F8");
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
    }

    resetColor();
}

void HomePage::changeColor(Node& node, QString s) {
    auto it = nodeGroups.find(node.id);
    if (it == nodeGroups.end() || !it->second) {
        qDebug() << "Group not found for node" << QString::fromStdString(node.name);
        return;
    }
    for (auto* item : it->second->childItems()) {
        if (item->type() == QGraphicsEllipseItem::Type) {
            QGraphicsEllipseItem* circle = static_cast<QGraphicsEllipseItem*>(item);
            circle->setBrush(QBrush(QColor(s)));
            circle->setPen(QPen(QColor(s)));
            break;
        }
    }
}

void HomePage::resetColor() {
    for (auto& [name, node] : g.namesAndNodes) {
        changeColor(node, "#003FFF");
    }
}

void HomePage::updateEdges(Node* movedNode)
{
    for (GuiEdge& e : guiEdges) {
        if (e.from == movedNode || e.to == movedNode) {
            QPointF p1 = nodeGroups[e.from->id]->scenePos() + QPointF(25, 25);
            QPointF p2 = nodeGroups[e.to->id]->scenePos() + QPointF(25, 25);

            const double baseOffset = 30;
            double offset = baseOffset * (e.multiEdgeIndex + 1) * (e.multiEdgeIndex % 2 == 0 ? 1 : -1);
            QPointF controlPoint = (p1 + p2) / 2 + QPointF(0, offset);

            QPainterPath path;
            path.moveTo(p1);
            path.quadTo(controlPoint, p2);
            e.line->setPath(path);

            double angle = atan2(p2.y() - controlPoint.y(), p2.x() - controlPoint.x());
            const double arrowSize = 15;
            QPointF tip = p2 - QPointF(cos(angle) * 25, sin(angle) * 25);
            QPointF arrowP1 = tip - QPointF(cos(angle) * arrowSize - sin(angle) * arrowSize / 2,
                sin(angle) * arrowSize + cos(angle) * arrowSize / 2);
            QPointF arrowP2 = tip - QPointF(cos(angle) * arrowSize + sin(angle) * arrowSize / 2,
                sin(angle) * arrowSize - cos(angle) * arrowSize / 2);

            QPolygonF arrowHead;
            arrowHead << tip << arrowP1 << arrowP2;
            e.arrowHead->setPolygon(arrowHead);

            QPointF midPoint = path.pointAtPercent(0.4);
            int offsetDirection = (e.multiEdgeIndex % 2 == 0) ? 1 : -4;
            int offsetDirection2 = ((p1.x() - p2.x() > 0 && p1.y() - p2.y() > 0) || (p2.x() - p1.x() > 0 && p2.y() - p1.y() > 0)) ? -3 : 1;
            if (offsetDirection == -4 && offsetDirection2 == -3)
                offsetDirection = -1;
            e.weightLabel->setPos(midPoint.x() + 10 * offsetDirection * offsetDirection2, midPoint.y());
        }
    }
}


void HomePage::floyd_warshall() {
   vector<vector<long long>> distance = g.floyd_warshall();

    QString output = "<html><body><p><span style=\"font-size:14pt; font-weight:700; color:black;\">Shortest Path Between All Pairs of Cities:</span></p>";


    vector<Node*> nodes;
    for (auto& [id, node] : g.idsAndNodes) {
        nodes.push_back(node);
    }

    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) { return a->name < b->name; });

    const long long INF = LLONG_MAX;

    output += "<table style=\"font-size:25pt; border-collapse: collapse; color: #000000; width: 150%;\">";

    output += "<tr><th style=\"border: 1px solid blue; padding: 10px; color: #000000;\"></th>";
    for (auto* node : nodes) {
        output += "<th style=\"border: 1px solid blue; padding: 10px; color: #000000;\">" + QString::fromStdString(node->name) + "</th>";
    }
    output += "</tr>";

    for (auto* u : nodes) {
        output += "<tr><td style=\"border: 1px solid blue; padding: 10px; color: #000000; font-weight: bold;\">" + QString::fromStdString(u->name) + "</td>";
        for (auto* v : nodes) {
            long long dist = distance[u->id][v->id];
            QString distStr = (dist == INF) ? "∞" : QString::number(dist);
            output += "<td style=\"border: 1px solid blue; padding: 10px; text-align: center; color: #000000;\">" + distStr + "</td>";
        }
        output += "</tr>";
    }
    output += "</table></body></html>";


    QLabel* tableLabel = new QLabel();
    tableLabel->setText(output);
    tableLabel->setWordWrap(false);
    tableLabel->setStyleSheet("QLabel { background-color: rgba(255, 255, 255, 160); border: 1px solid #cccccc; border-radius: 10px; padding: 10px; }");

    ui.scrollArea->setWidget(tableLabel);
    ui.scrollArea->setWidgetResizable(false);
    ui.scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    for (auto* node : nodes) {
        changeColor(*node, "#29C4F8");
        QEventLoop loop;
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
    }
    resetColor();
}

QPushButton* HomePage::getLogOut()
{
    return ui.logOut;
}