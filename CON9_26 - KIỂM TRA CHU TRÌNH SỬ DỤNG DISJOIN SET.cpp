#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

bool hasCycle(int V, vector<pair<int, int>>& edges) {
    DisjointSet ds(V);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        int rootU = ds.find(u);
        int rootV = ds.find(v);

        if (rootU == rootV) {
            return true;
        }

        ds.unionSets(rootU, rootV);
    }

    return false;
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

        if (hasCycle(V, edges)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}