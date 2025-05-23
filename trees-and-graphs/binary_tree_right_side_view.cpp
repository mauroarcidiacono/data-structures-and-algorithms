// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/
// Difficulty: Medium
// Strategy: BFS.
#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> queue;
        vector<int> ans;
        queue.push(root);
        
        while (!queue.empty()) {
            int nodesInCurrentLevel = queue.size();
            ans.push_back(queue.back()->val);

            for (int i = 0; i < nodesInCurrentLevel; i++) {
                TreeNode* node = queue.front();
                queue.pop();

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
    Solution sol;

    TreeNode* root = new TreeNode(1);
    TreeNode* node0 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(4);

    root->left = node0;
    root->right = node1;
    node0->right = node2;
    node1->right = node3;

    vector<int> answer = sol.rightSideView(root);
    for (int element : answer) {
        cout << element << ' ';
    }

    return 0;
}