// 938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/
// Difficulty: Easy
// Strategy: limited DFS traversal
#include <iostream>

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int answer = 0;

        if (root->val >= low && root->val <= high) {
            answer += root->val;
        }

        if (root->val >= low) {
            answer += rangeSumBST(root->left, low, high);
        }

        if (root->val <= high) {
            answer += rangeSumBST(root->right, low, high);
        }

        return answer;
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(10);
    TreeNode* node0 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(15);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(18);

    root->left = node0;
    root->right = node1;
    node0->left = node2;
    node0->right = node3;
    node1->right = node4;

    int low = 7;
    int high = 15;

    cout << sol.rangeSumBST(root, low, high) << '\n';

    return 0;
}