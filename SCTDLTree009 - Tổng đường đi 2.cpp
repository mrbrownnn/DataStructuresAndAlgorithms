#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node, int targetSum, std::vector<int>& path, std::vector<std::vector<int>>& result) {
    if (node == nullptr) {
        return;
    }
    
    path.push_back(node->val);
    
    if (node->left == nullptr && node->right == nullptr && node->val == targetSum) {
        result.push_back(path);
    }
    
    dfs(node->left, targetSum - node->val, path, result);
    dfs(node->right, targetSum - node->val, path, result);
    
    path.pop_back();
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(root, targetSum, path, result);
    return result;
}

int main() {
    // Test case input
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<TreeNode*> nodes(n);
        for (int i = 0; i < n; i++) {
            int val;
            std::cin >> val;
            
            if (val != -1) {
                nodes[i] = new TreeNode(val);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nodes[i] == nullptr) {
                continue;
            }
            
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            
            if (leftIndex < n) {
                nodes[i]->left = nodes[leftIndex];
            }
            
            if (rightIndex < n) {
                nodes[i]->right = nodes[rightIndex];
            }
        }
        
        int targetSum;
        std::cin >> targetSum;
        
        std::vector<std::vector<int>> result = pathSum(nodes[0], targetSum);
        
        // Test case output
        if (result.empty()) {
            std::cout << "0" << std::endl;
        } else {
            for (const auto& path : result) {
                std::cout << "[";
                for (int i = 0; i < path.size(); i++) {
                    std::cout << path[i];
                    if (i != path.size() - 1) {
                        std::cout << ",";
                    }
                }
                std::cout << "]";
            }
            std::cout << std::endl;
        }
        
        // Clean up memory
        for (int i = 0; i < n; i++) {
            delete nodes[i];
        }
    }
    
    return 0;
}