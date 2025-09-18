// 547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/description/
// Difficulty: Medium
// Strategy: DFS + Hash Map
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    
    int findCircleNum(vector<vector<int>>& isConnected) {    
        int n = isConnected.size();
        seen = vector(n, false);
        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (isConnected[row][col] == 1) {
                    graph[row].push_back(col);
                    graph[col].push_back(row);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                ans++;
                seen[i] = true;
                dfs(i);
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
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;

    return 0;
}