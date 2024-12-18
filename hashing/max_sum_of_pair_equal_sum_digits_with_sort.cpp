// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
// Difficulty: Medium
// Strategy: hash map.
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> counts;
        int ans = -1;

        for (int n : nums) {
            int sum = 0;
            int original_n = n;
            while (n > 0) {
                int digit = n % 10;
                sum += digit;
                n /= 10;
            }
            counts[sum].push_back(original_n);
        }

        for (auto& [key, value_arr] : counts) {
            if (value_arr.size() > 1) {
                sort(value_arr.begin(), value_arr.end(), greater<int>()); // desc order
                ans = max(ans, value_arr[0] + value_arr[1]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {18,43,36,13,7};
    vector<int> nums = {10,12,19,14};
    cout << sol.maximumSum(nums) << endl;
    return 0;
}