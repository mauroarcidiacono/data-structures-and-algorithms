// 1026. Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
// Difficulty: Medium
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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* node, int curr_min, int curr_max) {
        if (!node) return curr_max - curr_min;

        curr_min = min(node->val, curr_min);
        curr_max = max(node->val, curr_max);

        int left = dfs(node->left, curr_min, curr_max);
        int right = dfs(node->right, curr_min, curr_max);
        
        return max(right, left);
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(8);
    TreeNode* node0 = new TreeNode(3);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(7);
    TreeNode* node5 = new TreeNode(10);
    TreeNode* node6 = new TreeNode(14);
    TreeNode* node7 = new TreeNode(13);

    root->left = node0;
    node0->left = node1;
    node0->right = node2;
    node2->left = node3;
    node2->right = node4;

    root->right = node5;
    node5->right = node6;
    node6->left = node7;

    cout << sol.maxAncestorDiff(root) << '\n';

    return 0;
}
