// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
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
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> queue;
        vector<int> ans;
        queue.push(root);

        while (!queue.empty()) {
            int nodesInCurrentLevel = queue.size();
            int currMax = INT_MIN;

            for (int i = 0; i < nodesInCurrentLevel; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                
                if (currMax < node->val) {
                    currMax = node->val;
                }

                if (node->left) {
                    queue.push(node->left);
                }

                if (node->right) {
                    queue.push(node->right);
                }
            }
            ans.push_back(currMax);
        }
        return ans;
    };
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(1);
    TreeNode* node0 = new TreeNode(3);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(9);

    root->left = node0;
    root->right = node1;
    node0->left = node2;
    node0->right = node3;
    node1->right = node4;

    vector<int> answer = sol.largestValues(root);
    for (int i = 0; i <answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}