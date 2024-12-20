// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Difficulty: Medium
// Strategy: sliding window with an unordered set.
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ul; // unique letters
        size_t ans = 0;
        size_t start = 0;
        
        for (size_t end = 0; end < s.length(); end++) {
            char c = s[end];
            while (ul.find(c) != ul.end()) {
                ul.erase(s[start]);
                start++;
            }
            ul.insert(c);
            ans = max(ans, ul.size());
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