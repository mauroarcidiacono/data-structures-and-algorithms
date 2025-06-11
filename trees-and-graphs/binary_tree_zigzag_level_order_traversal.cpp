// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Difficulty: Medium
// Strategy: BFS.
#include <iostream>
#include <queue>
#include <vector>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> queue;
        queue.push(root);
        vector<vector<int>> ans;
        bool leftToRight = true; 

        while (!queue.empty()) {
            int nodesInCurrentLevel = queue.size();
            vector<int> level(nodesInCurrentLevel);

            for (int i = 0; i < nodesInCurrentLevel; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                int index = leftToRight ? i : nodesInCurrentLevel - 1 - i;
                level[index] = node->val;

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) { 
                    queue.push(node->right);
                }; 
                
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* node_9 = new TreeNode(9);
    TreeNode* node_20 = new TreeNode(20);
    TreeNode* node_15 = new TreeNode(15);
    TreeNode* node_7 = new TreeNode(7);

    root->left = node_9;
    root->right = node_20;
    node_20->left = node_15;
    node_20->right = node_7;

    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    for (vector v : ans ) {
        for (int val : v) {
            cout << val << ' ';
        }
        cout << '\n';
    }

    return 0;
}