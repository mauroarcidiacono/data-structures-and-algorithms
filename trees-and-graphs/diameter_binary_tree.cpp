// 543. Diameter Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/description/
// Difficulty: Easy
// Strategy: DFS.
#include <iostream>
#include <algorithm>

using namespace std;

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
    int max_diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_diameter;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        max_diameter = max(max_diameter, left + right);

        return max(left, right) + 1;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1);
    TreeNode* node0 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(3);

    root->left = node0;
    root->right = node3;
    node0->left = node1;
    node0->right = node2;

    cout << sol.diameterOfBinaryTree(root) << '\n';

    return 0;
}