// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
// Difficulty: Medium
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> routes;
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    int minReorder(int n, vector<vector<int>>& connections) {
        seen = vector(n, false);

        for (vector<int> v : connections) {
            int x = v[0];
            int y = v[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
            routes.insert({x, y});
        }
        seen[0] = true;
        return dfs(0);
    }

    int dfs(int node) {
        int ans = 0;
        for (int neighbour : graph[node]) {
            if (!seen[neighbour]) {
                if (routes.contains({node, neighbour})) {
                    ans++;
                }

                seen[neighbour] = true;
                ans += dfs(neighbour);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};

    cout << sol.minReorder(n, connections) << endl;

    return 0;
}








