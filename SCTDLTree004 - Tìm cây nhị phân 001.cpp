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

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (i == size - 1) {
                result.push_back(node->val);
            }
            
            if (node->left != NULL) {
                q.push(node->left);
            }
            
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> q;
        q.push(root);
        
        int i = 1;
        while (!q.empty() && i < n) {
            TreeNode* node = q.front();
            q.pop();
            
            if (nums[i] != -1) {
                node->left = new TreeNode(nums[i]);
                q.push(node->left);
            }
            
            i++;
            
            if (i < n && nums[i] != -1) {
                node->right = new TreeNode(nums[i]);
                q.push(node->right);
            }
            
            i++;
        }
        
        vector<int> result = rightSideView(root);
        
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}