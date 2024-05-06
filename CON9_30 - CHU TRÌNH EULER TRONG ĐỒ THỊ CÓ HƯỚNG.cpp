#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& path) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, path);
        }
    }
    path.push(node);
}

bool hasEulerCycle(int V, int E, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(V + 1);
    vector<bool> visited(V + 1, false);
    stack<int> path;

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, path);
        }
    }

    if (path.size() != E + 1) {
        return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<pair<int, int>> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> edges[i].first >> edges[i].second;
        }

        bool hasCycle = hasEulerCycle(V, E, edges);
        cout << (hasCycle ? 1 : 0) << endl;
    }

    return 0;
}