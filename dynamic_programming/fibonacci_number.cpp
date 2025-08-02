// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/description/?envType=problem-list-v2&envId=math
// Difficulty: Easy
// Strategy: top-down DP.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        memo[0] = 0;
        if (n >= 1) memo[1] = 1; 
        return dp(n, memo);
    }

private:
    int dp(int n, vector<int>& memo) {
        if (memo[n] != -1) return memo[n];
        return memo[n] = dp(n - 1, memo) + dp(n - 2, memo);
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    cout << sol.fib(5) << endl;
}
