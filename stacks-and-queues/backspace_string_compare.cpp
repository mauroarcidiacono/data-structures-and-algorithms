// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/description/
// Difficulty: Easy
// Strategy: stack.
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare (string s, string t) {
        return build(s) == build(t);
    }

    string build(string s) {
        string str = "";
        for (char c : s) {
            if (c != '#') {
                str.push_back(c);
            } else if (!str.empty()) {
                str.pop_back();
            } 
        }
        return str;
    }
};

int main() {
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";
    cout << (sol.backspaceCompare(s, t) ? "true" : "false") << '\n';

    return 0;
} 