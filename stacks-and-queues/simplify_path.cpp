// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/description/
// Difficulty: Medium
// Strategy: stack.
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string part;
        string ans;
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!part.empty()) {
                    processPart(part, st);
                    part.clear();
                }
            } else {
                part += path[i];
            }
        }

        // Process the last element of the absolute path if
        // there is no '/' at the end.
        if (!part.empty()) {
            processPart(part, st);
        }

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }

private: 
    void processPart(const string& part, stack<string>& stk) {
        if (part == "..") {
            if (!stk.empty()) {
                stk.pop();
            }
        } else if (part != ".") {
            stk.push(part);
        }
    }
};

int main() {
    Solution sol;
    string p = "/.../a/../b/c/../d/./";
    cout << sol.simplifyPath(p) << '\n';

    return 0;
} 