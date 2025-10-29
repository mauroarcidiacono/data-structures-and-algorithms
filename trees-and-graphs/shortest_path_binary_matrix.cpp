// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Difficulty: Medium
// Strategy: BFS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    int n;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        this->grid = grid;
        n = int(grid.size());

        vector<vector<bool>> seen(n, vector<bool>(n, false));
        seen[0][0] = true;

        queue<vector<int>> queue;
        queue.push({0, 0, 1}); // row, col, steps

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            
            if (curr[0] == n - 1 && curr[1] == n - 1) {
                return curr[2];
            }

            for (auto& dir : directions) {
                int next_row = curr[0] + dir[0];
                int next_col = curr[1] + dir[1];
                
                if (is_valid(next_row, next_col) && !seen[next_row][next_col]) {
                    seen[next_row][next_col] = true;
                    queue.push({next_row, next_col, curr[2] + 1});
                }
            }
        }

        return -1;
    }

    bool is_valid(const int& row, const int& col) {
        return row < n && col < n && row >=0 && col >=0 && grid[row][col] == 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

    cout << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}