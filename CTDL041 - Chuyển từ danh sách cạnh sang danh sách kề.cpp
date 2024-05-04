#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printAdjacencyList(vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();
    for (int i = 0; i < numVertices; i++) {
        cout << "D" << i + 1 << ": ";
        for (int j = 0; j < adjacencyList[i].size(); j++) {
            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adjacencyList(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adjacencyList[u - 1].push_back(v);
            adjacencyList[v - 1].push_back(u);
        }

        printAdjacencyList(adjacencyList);
    }

    return 0;
}