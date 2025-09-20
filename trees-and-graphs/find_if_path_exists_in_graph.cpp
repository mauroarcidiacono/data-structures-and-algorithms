// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/description/
// Difficulty: Easy
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        seen = vector(n, false);

        for (vector<int> e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        seen[source] = true;

        return dfs(source, destination);
    }

    bool dfs(int source, int destination) {
        for (int neighbour : graph[source]) {
            if (!seen[neighbour]) {
                seen[neighbour] = true;
                if (neighbour == destination) {
                    return true;
                }
                if (dfs(neighbour, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    int n = 3;
    int source = 0;
    int destination = 2;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}}; 

    cout << (sol.validPath(n, edges, source, destination) ? "True" : "False") << endl;
    return 0;
}