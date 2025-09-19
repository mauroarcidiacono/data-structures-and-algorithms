// 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/description/
// Difficulty: Medium
// Strategy: DFS
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> seen;
    vector<vector<int>> rooms;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        seen.insert(0);
        return dfs(0) == rooms.size();
    }

    size_t dfs(int node) {
        for (int neighbour : rooms[node]) {
            if (!seen.contains(neighbour)) {
                seen.insert(neighbour);
                dfs(neighbour);
            }
        }

        return seen.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rooms = {{1},{2},{3},{}};

    cout << (sol.canVisitAllRooms(rooms) ? "True" : "False") << endl;

    return 0;
}