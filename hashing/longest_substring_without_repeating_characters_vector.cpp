// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Difficulty: Medium
// Strategy: sliding window with a vector.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // ASCII chars
        int ans = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char c = s[end];

            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }

            lastIndex[c] = end;
            ans = max(ans, end - start + 1);

        }
        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    sol.lengthOfLongestSubstring(s);
    return 0;
}