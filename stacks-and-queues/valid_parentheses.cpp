// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/
// Difficulty: Easy
// Strategy: stack.
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> matching {{'(',')'}, {'{','}'}, {'[',']'}};

        for(char c : s) {
            if (matching.find(c) != matching.end()) {
                stack.push(c);
            } else {

                if (stack.empty()) {
                    return false;
                }

                char lastItem = stack.top();
                if (matching[lastItem] != c) {
                    return false;
                }

                stack.pop();
            }
            
        }
        
        return stack.empty();

    }
};

int main() {
    Solution sol;
    string s = "()[]{}";
    cout << (sol.isValid(s) ? "true" : "false")<< "\n";
    return 0;
}