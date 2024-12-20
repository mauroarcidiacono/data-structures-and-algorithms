// 383. Ramson Note
// https://leetcode.com/problems/ransom-note/description/
// Difficulty: Easy
// Strategy: hash map.
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Can be solved with a vector of 26 as well. 
        unordered_map<char, int> freqMagazine;

        for (char c : magazine) {
            freqMagazine[c]++;
        }

        for (char c : ransomNote) {
            if (freqMagazine[c] <= 0) {
                return false;
            }
            freqMagazine[c]--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string ransomNote = "a";
    string magazine = "b";
    cout << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << '\n';
    return 0;
}