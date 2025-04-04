// 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Difficulty: Medium
// Strategy: DFS with helper function.
#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int maxVal) {
        if (node == nullptr) {
            return 0;
        }
        
        int left = dfs(node->left, max(node->val, maxVal));
        int right = dfs(node->right, max(node->val, maxVal));
        int ans = left + right;
        if (node->val >= maxVal) {
            ans++;
        }
        
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* n0 = new TreeNode(1);
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(5);

    root->left = n0;
    root->right = n2;
    n0->left = n1;
    n2->left = n3;
    n2->right = n4;
    
    Solution sol;
    cout << sol.goodNodes(root) << '\n';
    
    return 0;
}