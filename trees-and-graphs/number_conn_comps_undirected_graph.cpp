// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
// Difficulty: Medium
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    int countComponents(int n, vector<vector<int>>& edges) {
        seen = vector(n, false);
        int ans = 0;

        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                seen[i] = true;
                dfs(i);
                ans++;
            }
        }

        return ans;
    }

    void dfs(int node) {
        for (int neighbour : graph[node]) {
            if (!seen[neighbour]) {
                seen[neighbour] = true;
                dfs(neighbour);
            }
        }
    }
};


int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << sol.countComponents(n, edges) << endl;

    return 0;
}

