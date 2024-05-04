#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& paths) {
    if (node == NULL) {
        return;
    }
    path.push_back(node->val);
    if (node->left == NULL && node->right == NULL) {
        paths.push_back(path);
    }
    dfs(node->left, path, paths);
    dfs(node->right, path, paths);
    path.pop_back();
}

vector<vector<int>> binaryTreePaths(TreeNode* root) {
    vector<vector<int>> paths;
    vector<int> path;
    dfs(root, path, paths);
    return paths;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tree(n);
        for (int i = 0; i < n; i++) {
            cin >> tree[i];
        }
        // Build the binary tree from the input array
        TreeNode* root = NULL;
        vector<TreeNode*> nodes(n);
        for (int i = 0; i < n; i++) {
            if (tree[i] != -1) {
                nodes[i] = new TreeNode(tree[i]);
                if (i > 0) {
                    int parent = (i - 1) / 2;
                    if (i % 2 == 1) {
                        nodes[parent]->left = nodes[i];
                    } else {
                        nodes[parent]->right = nodes[i];
                    }
                } else {
                    root = nodes[i];
                }
            }
        }
        // Get all the binary tree paths
        vector<vector<int>> paths = binaryTreePaths(root);
        // Print the paths
        for (const auto& path : paths) {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) {
                    cout << "->";
                }
            }
            cout << endl;
        }
    }
    return 0;
}