// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Difficulty: Easy
// Strategy: two pointers.
#include <iostream>
// #include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int wordEnd = 0;

        while (wordEnd < s.size()) {
            while (wordEnd < s.size() && s[wordEnd] != ' ') {
                wordEnd += 1;
            }

            // reverse(s.begin() + left, s.begin() + wordEnd);
            int right = wordEnd - 1;
            while (right > left) {
                swap(s[right], s[left]);
                right--;
                left++;
            }
            
            wordEnd++;
            left = wordEnd;
        }

        cout << s << '\n';
        return s; 
    }
};

int main() {
    Solution sol;
    string input = "Word";
    sol.reverseWords(input);
}