// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
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
        int minDepth(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            if (root->left == nullptr) {
                return minDepth(root->right) + 1;
            }

            if (root->right == nullptr) {
                return minDepth(root->left) + 1;
            }
            
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    };

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* node0 = new TreeNode(9);
    TreeNode* node1 = new TreeNode(20);
    TreeNode* node2 = new TreeNode(15);
    TreeNode* node3 = new TreeNode(7);

    // TreeNode* root = new TreeNode(2);
    // TreeNode* node0 = new TreeNode(3);
    // TreeNode* node1 = new TreeNode(4);
    // TreeNode* node2 = new TreeNode(5);
    // TreeNode* node3 = new TreeNode(6);

    root->left = node0;
    root->right = node1;
    node1->left = node2;
    node1->right = node3;

    // root->right = node0;
    // node0->right = node1;
    // node1->right = node2;
    // node2->right = node3;

    Solution sol;
    cout << sol.minDepth(root) << '\n';

    return 0;
}