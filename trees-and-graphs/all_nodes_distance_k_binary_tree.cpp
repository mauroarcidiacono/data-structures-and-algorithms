// 863. All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// Difficulty: Medium
// Strategy: DFS to build hash map plus BFS to find the nodes
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);

        queue<TreeNode*> queue;
        queue.push(target);

        unordered_set<TreeNode*> seen;
        seen.insert(target);

        int distance = 0;
        while(!queue.empty() && distance < k) {
            int level_size = queue.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                for (TreeNode* neighbour: {node->left, node->right, parents[node]}) {
                    if (neighbour != nullptr && !seen.contains(neighbour)) {
                        seen.insert(neighbour);
                        queue.push(neighbour);
                    }
                }
            }
            distance++;
        }

        vector<int> ans;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            ans.push_back(node->val);
        }

        return ans;
    }

    void dfs(TreeNode* node, TreeNode* parent) {
        if (node == nullptr) return;
        
        parents[node] = parent; 
        dfs(node->right, node);
        dfs(node->left, node);
    }
};


int main() {
    Solution sol;

    TreeNode* root = new TreeNode(3);
    TreeNode* n0 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(0);
    TreeNode* n7 = new TreeNode(8);

    root->left = n0;
    root->right = n5;
    n0->left = n1;
    n0->right = n2;
    n2->left = n3;
    n2->right = n4;
    n5->right = n6;
    n5->left = n7;

    TreeNode* target = n0;
    int k = 2;

    vector<int> ans = sol.distanceK(root, target, k);

    for (int v : ans) {
        cout << v << endl;
    }

    return 0;
}



