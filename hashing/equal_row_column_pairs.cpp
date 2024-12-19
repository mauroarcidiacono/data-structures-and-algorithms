// 2352. Equal Row and Column Pairs
// https://leetcode.com/problems/equal-row-and-column-pairs/description/
// Difficulty: Medium
// Strategy: two hash maps.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int, VectorHash> row;
        unordered_map<vector<int>, int, VectorHash> col;
        int ans = 0;

        for (vector v : grid) {
            row[v]++;
        }

        for (int j = 0; j < grid.size(); j++) {
            vector<int> temp;
            for (int i = 0; i < grid.size(); i++) {
                temp.push_back(grid[i][j]);
            }
            col[temp]++;
        }

        for (auto& [row_key, row_val] : row) {
            if (col.find(row_key) != col.end()) {
                ans += row_val * col[row_key];
            }
        }

        return ans;
    }

    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int i : v) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
};

int main() {
    Solution sol;
    vector<vector<int>> g = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout << sol.equalPairs(g) << '\n';
    return 0;
}

