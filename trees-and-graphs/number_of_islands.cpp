// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/
// Difficulty: Medium
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int n;
    int m;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<char>> grid;

    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();     // row
        n = grid[0].size();  // col
        seen = vector(m, vector<bool>(n, false));
        int ans = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' && !seen[row][col]) {
                    ans++;
                    seen[row][col] = true;
                    dfs(row, col);
                }
            }
        }

        return ans;
    }

    void dfs(int row, int col) {
        for (auto& dir : directions) {
            int next_row = row + dir[0];
            int next_col = col + dir[1];

            if (is_valid(next_row, next_col) && !seen[next_row][next_col]) {
                seen[next_row][next_col] = true;
                dfs(next_row, next_col);
            }
        }
    }

    bool is_valid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1';
    }

};

int main() {
    Solution sol;

    vector<vector<char>> grid = { {'1','1','1','1','0'},
                                  {'1','1','0','1','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','0','0','0'}
                                };
    
    cout << sol.numIslands(grid) << endl;
    
    return 0;
}


