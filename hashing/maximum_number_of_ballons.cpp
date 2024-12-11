// 1189. Maximum Number of Ballons
// https://leetcode.com/problems/maximum-number-of-balloons/description/
// Difficulty: Easy
// Strategy: hash map.
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int, int> counts;
        int ans = 0;

        for (char c : text) {
            counts[c]++;
        }

        ans = min({counts['b'], counts['a'], counts['l'] / 2, counts['o'] / 2, counts['n']});
        cout << ans << '\n';
        return ans;
    }
};

int main() {
    Solution sol;
    string text = "loonbalxballpoon";
    sol.maxNumberOfBalloons(text);
    return 0;
}