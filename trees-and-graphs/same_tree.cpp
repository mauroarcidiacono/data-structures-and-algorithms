// 100. Same Tree
// https://leetcode.com/problems/same-tree/description/
// Difficulty: Easy
// Strategy: DFS traversal and short circuit.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;

        if (!p || !q || p->val != q->val) return false;

        return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
    }
};

int main() {

    TreeNode* root0 = new TreeNode(1);
    TreeNode* node00 = new TreeNode(2);    
    TreeNode* node01 = new TreeNode(3);

    TreeNode* root1 = new TreeNode(1);
    TreeNode* node10 = new TreeNode(2);    
    TreeNode* node11 = new TreeNode(3);

    // TreeNode* root2 = new TreeNode(1);
    // TreeNode* node20 = new TreeNode(2);

    // TreeNode* root3 = new TreeNode(1);
    // TreeNode* node30 = new TreeNode(2);

    root0->left = node00;
    root0->right = node01;
    root1->left = node10;
    root1->right = node11;

    // root2->left = node20;
    // root3->right = node30;

    Solution sol;
    cout << (sol.isSameTree(root0, root1) ? "true" : "false") << '\n';
    // cout << (sol.isSameTree(root2, root3) ? "true" : "false") << '\n';

    return 0;
}