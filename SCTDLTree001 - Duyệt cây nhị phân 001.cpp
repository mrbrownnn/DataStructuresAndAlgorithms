#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelValues;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            levelValues.push_back(node->val);

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        result.push_back(levelValues);
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<TreeNode*> nodes(n);
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;

            if (val != -1) {
                nodes[i] = new TreeNode(val);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nodes[i] != NULL) {
                int leftIndex = 2 * i + 1;
                int rightIndex = 2 * i + 2;

                if (leftIndex < n) {
                    nodes[i]->left = nodes[leftIndex];
                }
                if (rightIndex < n) {
                    nodes[i]->right = nodes[rightIndex];
                }
            }
        }

        vector<vector<int>> result = levelOrder(nodes[0]);

        for (const auto& level : result) {
            for (int val : level) {
                cout << val << " ";
            }
            cout << endl;
        }

        // Clean up memory
        for (TreeNode* node : nodes) {
            delete node;
        }
    }

    return 0;
}