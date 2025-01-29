// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/description/
// Difficulty: Easy
// Strategy: stack.
#include <iostream>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans = string(1, s[0]);  
        for (int i = 1; i < s.size(); i++) {
            if (!ans.empty() && abs(s[i] - ans.back()) == 32) {
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "leEeetcode";
    cout << sol.makeGood(s) << '\n';
}