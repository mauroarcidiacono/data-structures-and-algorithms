// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Difficulty: Medium
// Strategy: DFS.
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root == nullptr || root == p || root == q) {
                return root;
            }

            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q); 

            if (left && right) {
                return root;
            }

            return left ? left : right;
        }
    };

int main() {

    TreeNode* root = new TreeNode(3);
    TreeNode* node0 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(0);
    TreeNode* node7 = new TreeNode(8);

    root->left = node0;
    node0->left = node1; 
    node1->right = node2;
    node2->left = node3;
    node2->right = node4;

    root->right = node5;
    node5->left = node6;
    node5->right = node7;

    Solution sol;
    TreeNode* p = node0;
    TreeNode* q = node5;
    cout << sol.lowestCommonAncestor(root, p, q)->val << '\n';

    return 0;
}