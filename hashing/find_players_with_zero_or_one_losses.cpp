// 2225. Find Players With Zero or One Losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
// Difficulty: Medium
// Strategy: hash map.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lcounts;
        vector<int> w, l;

        for (const auto& p : matches) {
            if (lcounts.find(p[0]) == lcounts.end()) {
                lcounts[p[0]] = 0;
            }
            lcounts[p[1]]++;
        }

        for (const auto& [key, value] : lcounts) {
            if (value == 0) {
                w.push_back(key);
            } else if (value == 1) {
                l.push_back(key);
            }
        }

        sort(w.begin(), w.end());
        sort(l.begin(), l.end());

        for (int pw : w) {
            cout << pw << " ";
        } 
        cout << '\n';
        for (int pl : l) {
            cout << pl << " ";
        } 

        return {w, l};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    sol.findWinners(matches);
    return 0;
}