// 112. Path Sum
// https://leetcode.com/problems/path-sum/description/
// Difficulty: Easy
// Strategy: DFS. 
#include <iostream>

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
        int target;

        bool hasPathSum(TreeNode* root, int targetSum) {
            target = targetSum;
            return dfs(root, 0);
        }

        bool dfs(TreeNode* node, int curr) {
            if (node == nullptr) {
                return false;
            }

            if (node->left == nullptr && node->right == nullptr) {
                return (curr + node->val == target);
            }

            curr += node->val;
            bool left = dfs(node->left, curr);
            bool right = dfs(node->right, curr);

            return left || right;
        }
};

int main() {
    TreeNode* root = new TreeNode(5);
    TreeNode* n0 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(11);
    TreeNode* n2 = new TreeNode(7);
    TreeNode* n3 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(8);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(1);

    root->left = n0;
    root->right = n4;
    n0->left = n1;
    n1->left = n2;
    n1->right = n3;
    n4->left = n5;
    n4->right = n6;
    n6->right = n7;

    Solution sol;
    int targetSum = 22;
    string s = (sol.hasPathSum(root, targetSum)) ? "true" : "false";
    cout << s << '\n';
    return 0;
}