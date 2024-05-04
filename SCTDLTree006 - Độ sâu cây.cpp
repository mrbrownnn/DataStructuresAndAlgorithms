#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left != NULL) {
                q.push(node->left);
            }
            
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        
        depth++;
    }
    
    return depth;
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
        
        int result = maxDepth(nodes[0]);
        cout << result << endl;
    }
    
    return 0;
}