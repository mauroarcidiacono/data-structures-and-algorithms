// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
// Difficulty: Easy
// Strategy: string used as stack.
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for (char c : s) {
            if (!ans.empty() && ans.back() == c) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abbaca";
    cout << sol.removeDuplicates(s)<< "\n";
    return 0;
}