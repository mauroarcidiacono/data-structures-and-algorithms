// 1941. Check if All Characters Have Equal Number of Occurrences
// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/
// Difficulty: Easy
// Strategy: unordered set.
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int, int> frequencies;
        unordered_set<int> unique_vals;
        
        for (char c : s) {
            frequencies[c]++;
        }

        for (auto [key, val] : frequencies) {
            unique_vals.insert(val);
        }

        if (unique_vals.size() == 1) {
            cout << "True" << '\n';
        } else {
            cout << "False" << '\n';
        }
        return unique_vals.size() == 1;
    }
};

int main() {
    Solution sol;
    string s = "abacbc";
    sol.areOccurrencesEqual(s);

    return 0;
}

