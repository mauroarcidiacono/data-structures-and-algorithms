// 344. Reverse String
// https://leetcode.com/problems/reverse-string/description/
// Difficulty: Easy
// Strategy: two pointers.
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void reverseString(vector<char>& s) {
        
        int i = 0;
        int j = s.size() - 1;

        while (j > i) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }

        for (char c : s) {
            cout << c;
        }
        cout << '\n';
    }
};

int main() {
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    
    return 0;
}