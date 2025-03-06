// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/
// Difficulty: Medium.
// Strategy: monotonic stack.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> answer(temperatures.size());
            stack<int> s;

            for (int i = 0; i < temperatures.size(); i++) {
                while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                    int j = s.top();
                    answer[j] = i - j;
                    s.pop();
                }

                s.push(i);
            }

            for (int element : answer) {
                cout << element << ' ';
            }

            return answer;
        }
    };

int main() {
    Solution sol;

    vector<int> t = {40, 35, 32, 37, 50};
    sol.dailyTemperatures(t);

    return 0;
}