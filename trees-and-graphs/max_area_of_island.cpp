// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/description/
// Difficulty: Medium
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m;
    int n;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        int ans = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1 && !seen[row][col]) {
                    int curr = dfs(row, col);
                    if (curr > ans) ans = curr;
                }
            }
        }

        return ans;
    }

    int dfs(int row, int col) {
        seen[row][col] = true;
        int area = 1;
        for (vector<int> dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if (is_valid(new_row, new_col) && !seen[new_row][new_col]) {
                area += dfs(new_row, new_col);
            }
        }
        return area;
    }

    bool is_valid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}
                            };

    // vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};

    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}