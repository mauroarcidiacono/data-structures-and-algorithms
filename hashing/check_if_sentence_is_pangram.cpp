// 1832. Check if the Sentence is a Pangram
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
// Difficulty: Easy
// Strategy: unordered set.
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) return false;
        unordered_set<char> s(sentence.begin(), sentence.end());
        return s.size() == 26;
    }
};

int main () {
    Solution sol;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    sol.checkIfPangram(sentence);
}