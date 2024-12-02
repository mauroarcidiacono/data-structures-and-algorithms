// 2351. First Letter to Appear Twice
// https://leetcode.com/problems/first-letter-to-appear-twice/description/
// Difficulty: Easy
// Strategy: unordered set.
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char c : s) {
            if (seen.find(c) != seen.end()) {
                cout << c << '\n';
                return c;
            }
            seen.insert(c);
        }
        cout << ' ' << '\n';
        return ' ';
    }
};

int main() {
    Solution sol;
    string s = "abccbaacz";
    sol.repeatedCharacter(s);
}