// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/description/
// Difficulty: Easy
// Strategy: set.
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> j;
        int ans = 0;

        for (char c : jewels) {
            j.insert(c);
        }

        for (char c : stones) {
            if (j.find(c) != j.end()) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout << sol.numJewelsInStones(jewels, stones) << '\n';
    return 0;
}