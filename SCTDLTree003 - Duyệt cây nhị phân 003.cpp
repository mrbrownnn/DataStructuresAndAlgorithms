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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            level.push_back(node->val);
            
            if (node->left != NULL) {
                q.push(node->left);
            }
            
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        
        result.insert(result.begin(), level);
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
        
        TreeNode* root = NULL;
        queue<TreeNode*> q;
        
        if (nums[0] != -1) {
            root = new TreeNode(nums[0]);
            q.push(root);
        }
        
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
        
        vector<vector<int>> result = levelOrderBottom(root);
        
        for (vector<int> level : result) {
            for (int num : level) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}