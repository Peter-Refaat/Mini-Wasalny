#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

struct Node {
    string name;
    int id;
    Node();
    Node(string s, int& nxtid);
};

struct Edge {
    Node* from;
    Node* to;
    long long weight;
    Edge(Node* from, Node* to, long long weight);
    bool operator==(const Edge& other) const {
        return from == other.from && to == other.to && weight == other.weight;
    }
    bool operator<(const Edge& other) const {
		if (from->id != other.from->id) {
			return from->id < other.from->id;
		}
        return weight < other.weight;
    }
};

class Graph {
public:
    int nxt_id = 0;

    map<int, multiset<Edge>> adj;
    map<string, Node> namesAndNodes;
    map<int, Node*> idsAndNodes;
    
    int get_node_id(string u);
    bool is_city_exist(string s);
    
    void add_city(string s);
    void add_edge(string u, string v, int weight);
    void delete_city(string city);
    void delete_edge(string u, string v, int weight);
    
    vector<string> dfs(string source);
    vector<string> bfs(string node);
    pair<deque<string>,long long> dijkstra(string source, string destination);
    vector<vector<long long>> floyd_warshall();
    int getNodeOutDegree(string s);
};

// for edge

void to_json(json& j, const Edge& edge);
void from_json(const json& j, Edge& edge);



// for node
void to_json(json& j, const Node& node);
void from_json(const json& j, Node& node);

// For Graph
void to_json(json& j, const Graph& g);
void from_json(const json& j, Graph& g);