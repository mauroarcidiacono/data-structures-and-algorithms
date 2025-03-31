// 104. Maximum Depth Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// Difficulty: Easy
// Strategy: maximum value from the leaf upwards. 
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
        int maxDepth(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            int right = maxDepth(root->right);
            int left = maxDepth(root->left);

            return max(right, left) + 1;
        }
    };

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* n0 = new TreeNode(9);
    TreeNode* n1 = new TreeNode(20);
    TreeNode* n2 = new TreeNode(15);
    TreeNode* n3 = new TreeNode(7);

    root->left = n0;
    root->right = n1;
    n1->left = n2;
    n1->right = n3;

    Solution sol;
    cout << sol.maxDepth(root) << '\n';
    return 0;
}