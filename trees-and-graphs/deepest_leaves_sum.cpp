// 1302. Deepest Leaves Sum
// https://leetcode.com/problems/deepest-leaves-sum/description/
// Difficulty: Medium
// Strategy: BFS.
#include <iostream>
#include <queue>

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int ans;

        while (!queue.empty()) {
            int nodesInCurrentLevel = queue.size();
            ans = 0;

            for (int i = 0; i < nodesInCurrentLevel; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                ans += node->val;

                if (node->left) {
                    queue.push(node->left);
                }

                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* node_2 = new TreeNode(2);
    TreeNode* node_3 = new TreeNode(3);
    TreeNode* node_4 = new TreeNode(4);
    TreeNode* node_5 = new TreeNode(5);
    TreeNode* node_6 = new TreeNode(6);
    TreeNode* node_7 = new TreeNode(7);
    TreeNode* node_8 = new TreeNode(8);

    root->left = node_2;
    root->right = node_3;
    node_2->left = node_4;
    node_2->right = node_5;
    node_4->left = node_7;
    node_3->right = node_6;
    node_6->right = node_8;

    Solution sol;
    cout << sol.deepestLeavesSum(root) << '\n';

    return 0;
}