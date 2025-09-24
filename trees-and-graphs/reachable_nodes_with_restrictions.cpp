// 2368. Reachable Nodes With Restrictions
// https://leetcode.com/problems/reachable-nodes-with-restrictions/description/
// Difficulty: Medium
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> restricted_set;
    vector<bool> seen;

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        seen = vector(n, false);
        restricted_set = unordered_set<int>(restricted.begin(), restricted.end());

        for (vector<int> edge : edges) {
            int x = edge[0];
            int y = edge[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        return dfs(0);
    }

    int dfs(int node) {
        int ans = 1;
        seen[node] = true;
        for (int neighbour : graph[node]) {
            if (!seen[neighbour] && !restricted_set.count(neighbour)) {
                ans += dfs(neighbour);
            }
        }
        return ans;
    }
};

int main() {

    Solution sol;
    int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    vector<int> restricted = {4, 5};

    cout << sol.reachableNodes(n, edges, restricted) << endl;

    return 0;
}