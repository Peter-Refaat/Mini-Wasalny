#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPointF>
#include "Graph.h"
#include "ui_HomePage.h"
#include "UserManager.h"

struct GuiEdge {
    Node* from;
    Node* to;
    long long weight;
    int multiEdgeIndex;

    QGraphicsPathItem* line;
    QGraphicsPolygonItem* arrowHead;
    QGraphicsTextItem* weightLabel;
};

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    HomePage(QWidget* parent = nullptr);
    static void setLineEditError(QLineEdit* lineEdit, const QString& errorMessage = "Input required");
    static void resetLineEdit(QLineEdit* lineEdit ,const QString = "Enter City Name");
    QPushButton* getLogOut();
    ~HomePage();
private slots:
    void addCity();
    void addEdge();
    void deleteCity();
    void deleteEdge();
    void dfs();
    void bfs();
    void dijkstra();
    void floyd_warshall();
private:
    Ui::HomePageClass ui;
    Graph g;
    QGraphicsScene* scene;

    map<int, QGraphicsItemGroup*> nodeGroups;
    vector<GuiEdge> guiEdges;
    map<int, QPointF> nodePositions;

    void initialization();
    void createNode(Node& node);
    void createEdge(Node* node1, Node* node2, int weight);
    void updateEdges(Node* movedNode);
    void changeColor(Node& node, QString s);
    void resetColor();
    void updateEdgeVisibility(int fromId, int toId); // ADDED: Helper to manage edge visibility
};
