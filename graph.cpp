#include "Graph.h"
#include<stack>
Node::Node() {}

Node::Node(string s, int& nxtid)
{
    this->name = s;
    this->id = nxtid++;
}

Edge::Edge(Node* from, Node* to, long long weight)
{
    this->from = from;
    this->to = to;
    this->weight = weight;
}

int Graph::get_node_id(string u)
{
    if (!is_city_exist(u))
        return -1;
    return namesAndNodes[u].id;
}

bool Graph::is_city_exist(string s)
{
    return (namesAndNodes.find(s) != namesAndNodes.end());
}

void Graph::add_city(string s)
{
    Node node = Node(s, this->nxt_id);
    this->namesAndNodes[s] = node;
    this->idsAndNodes[node.id] = &this->namesAndNodes[s];
    this->adj[namesAndNodes[s].id] = multiset<Edge>();
}


void Graph::add_edge(string u, string v, int weight)
{
    int id_u = get_node_id(u);
    int id_v = get_node_id(v);
    Node* node_u = idsAndNodes[id_u];
    Node* node_v = idsAndNodes[id_v];
    adj[id_u].insert(Edge(node_u, node_v, weight));
}

int Graph::getNodeOutDegree(string city)
{
	int city_id = namesAndNodes[city].id;
	return adj[city_id].size();
}

void Graph::delete_city(string city)
{
    int city_id = namesAndNodes[city].id;
    Node* node = idsAndNodes[city_id];
    // Remove It If Directed
    for (auto& edg : adj[city_id])
    {
        // It Is Saved There As From (V), To (U), W
        Edge edg_v_u = Edge(edg.to, node, edg.weight);
        adj[edg.to->id].erase(edg_v_u);
    }
    adj.erase(city_id);
    idsAndNodes.erase(city_id);
    namesAndNodes.erase(city);
}

void Graph::delete_edge(string u, string v, int weight)
{
    int id_u = get_node_id(u);
    int id_v = get_node_id(v);
    Node* node_u = &namesAndNodes[u];
    Node* node_v = &namesAndNodes[v];
    Edge edg_u_v = Edge(node_u, node_v, weight);
    adj[id_u].extract(edg_u_v);//deletes one occurence
}

vector<string> Graph::dfs(string source) {
    stack<int> stack;
    stack.push(namesAndNodes[source].id);
    vector<string>path;
    map<int, bool>vis;
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (vis[node]) {
            continue;
        }

        vis[node] = true;
        path.push_back(idsAndNodes[node]->name);

        for (auto it = adj[node].begin(); it != adj[node].end(); ++it) {
            if (!vis[it->to->id]) {
                stack.push(it->to->id);
            }
        }
    }
    return path;
}

vector<string> Graph::bfs(string node)
{
    int start = namesAndNodes[node].id;
    map<int, bool> vis;
    queue<int> q;
    vector<string> path;

    vis[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int city = q.front();
        q.pop();

        path.push_back(idsAndNodes[city]->name);

        for (auto& edg : adj[city])
        {
            if (!vis[edg.to->id])
            {
                q.push(edg.to->id);
                vis[edg.to->id] = true;
            }
        }
    }
    return path;
}

pair<deque<string>, long long> Graph::dijkstra(string source, string destination)
{
    
    int start = namesAndNodes[source].id;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({ 0, start });
    unordered_map<int, long long> dis;
    unordered_map<int, int> parent;
    for (auto& it : adj)
        dis[it.first] = LLONG_MAX;

    parent[start] = -1;
    dis[start] = 0;

    while (pq.size())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        if (dis[node] < cost)
            continue;
        for (auto& edg : adj[node])
        {
            if (dis[edg.to->id] > cost + edg.weight)
            {
                parent[edg.to->id] = node;
                dis[edg.to->id] = cost + edg.weight;
                pq.push({ dis[edg.to->id], edg.to->id });
            }
        }
    }
    int cur = namesAndNodes[destination].id;
    // No Path From U To V
    if (dis[cur] == LLONG_MAX)
        return { {},dis[cur]};

    deque<string> path;
    while (cur != -1)
    {
        path.push_front(idsAndNodes[cur]->name);
        cur = parent[cur];
    }
    return make_pair(path, dis[namesAndNodes[destination].id]);
}

vector<vector<long long>> Graph::floyd_warshall()
{
    const long long INF = LLONG_MAX;
    vector<vector<long long>> distance(nxt_id+1,vector<long long>(nxt_id+1,INF));
    for (auto& u : adj) {
        for (auto& v : adj) {
            distance[u.first][v.first] = INF;
        }
        distance[u.first][u.first] = 0;
    }
    for (auto& [u, ms] : adj) {
        for (auto& edg : ms) {
            distance[u][edg.to->id] = min(distance[u][edg.to->id], edg.weight);
        }
    }
    for (auto& [pivot, ms] : adj) {
        for (auto& [u, ms] : adj) {
            for (auto& [v, ms] : adj) {
                if (distance[u][pivot] != INF && distance[pivot][v] != INF) {
                    long long next = distance[u][pivot] + distance[pivot][v];
                    distance[u][v] = min(distance[u][v], next);
                }
            }
        }
    }
    return distance;
}


void to_json(json& j, const Edge& edge) {
    if (!edge.from || !edge.to) { // Safety check
        throw runtime_error("Attempting to serialize an edge with null node pointers.");
    }
    j = json{
        {"from_name", edge.from->name}, // Use distinct key if "from" node is also key in adj map
        {"to_name", edge.to->name},
        {"weight", edge.weight}
    };
}

// This from_json for Edge is problematic for direct use in containers by nlohmann::json
// because it cannot resolve Node pointers from names without context.
// We will NOT rely on this for deserializing g.adj.
void from_json(const json& j, Edge& edge) {
    j.at("weight").get_to(edge.weight); // Corrected from j.at("from")
    // edge.from and edge.to remain unresolved here.
}



void to_json(json& j, const Node& n) {
    j = json{
        {"name", n.name},
        {"id", n.id}
    };
}

void from_json(const json& j, Node& n) {
    j.at("name").get_to(n.name);
    j.at("id").get_to(n.id);

}


void to_json(json& j, const Graph& g) {
    j = json{
        {"nxt_id", g.nxt_id},
        {"namesAndNodes", g.namesAndNodes} // Serializes map<string, Node>
    };

    // Manual serialization for adj to control Edge format precisely
    json adj_json = json::object();
    for (const auto& pair : g.adj) {
        int from_node_id = pair.first;
        json edges_array = json::array();
        if (pair.second.empty()) {
            edges_array.push_back({});
        }
        for (const Edge& edge : pair.second) {
            if (!edge.to) continue; // Skip invalid edges
            edges_array.push_back({
                // from_node is implicit by adj_json's key
                {"to_node_id", edge.to->id}, // Store ID for robust lookup
                {"to_node_name", edge.to->name}, // Can also store name for readability/validation
                {"weight", edge.weight}
                });
        }
        if (!edges_array.empty()) {
            adj_json[to_string(from_node_id)] = edges_array;
        }
    }
    j["adj"] = adj_json;
}

void from_json(const json& j, Graph& g) {

    j.at("nxt_id").get_to(g.nxt_id);

    // 1. Deserialize Nodes first
    // This uses Node::from_json, which is fine.
    if (j.contains("namesAndNodes")) {
        j.at("namesAndNodes").get_to(g.namesAndNodes);
    }

    // 2. CRITICAL: Rebuild idsAndNodes map after namesAndNodes is populated
    g.idsAndNodes.clear();
    for (auto& pair_name_node : g.namesAndNodes) {
        g.idsAndNodes[pair_name_node.second.id] = &pair_name_node.second;
    }

    // 3. Manually deserialize adjacency list (adj)
    if (j.contains("adj")) {
        const json& adj_json_map = j.at("adj");
        for (auto& item : adj_json_map.items()) { // item.key() is from_node_id as string
            int from_node_id = stoi(item.key());
            const json& edges_array_json = item.value();

            Node* from_node_ptr = nullptr;
            if (g.idsAndNodes.count(from_node_id)) {
                from_node_ptr = g.idsAndNodes.at(from_node_id);
            }
            else {
                continue; // Skip this entry or throw
            }

            for (const auto& edge_data_json : edges_array_json) {
                // Assuming Edge::to_json stored to_node_id (preferred) or to_node_name
                Node* to_node_ptr = nullptr;
                if (edge_data_json.contains("to_node_id")) {
                    int to_node_id = edge_data_json.at("to_node_id").get<int>();
                    if (g.idsAndNodes.count(to_node_id)) {
                        to_node_ptr = g.idsAndNodes.at(to_node_id);
                    }
                    else {
                        //cerr << "Error in from_json(Graph): to_node_id " << to_node_id << " not found." << endl;
                        continue;
                    }
                }
                else if (edge_data_json.contains("to_node_name")) { // Fallback if only name stored
                    string to_node_name = edge_data_json.at("to_node_name").get<string>();
                    if (g.namesAndNodes.count(to_node_name)) {
                        to_node_ptr = &g.namesAndNodes.at(to_node_name);
                    }
                    else {
                        //cerr << "Error in from_json(Graph): to_node_name '" << to_node_name << "' not found." << endl;
                        continue;
                    }
                }
                else {
                    g.adj[from_node_id] = multiset<Edge>();
                    continue;
                }

                long long weight = edge_data_json.at("weight").get<long long>();

                if (from_node_ptr && to_node_ptr) {
                    g.adj[from_node_id].emplace(from_node_ptr, to_node_ptr, weight);
                }
            }
        }
    }
}