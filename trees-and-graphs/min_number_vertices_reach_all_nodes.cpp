// 1557. Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
// Difficulty: Medium
// Strategy: Return the number of nodes with an indegree of zero

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        vector<int> ans;

        for (vector<int> edge : edges) {
            indegree[edge[1]]++;
        }

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    int n = 6;

    vector<int> ans = sol.findSmallestSetOfVertices(n, edges);

    for (int val : ans) {
        cout << val << endl; 
    }

    return 0;
}