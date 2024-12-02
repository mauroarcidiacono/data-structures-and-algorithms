// 268. Missing number
// https://leetcode.com/problems/missing-number/description/
// Difficulty: Easy
// Strategy: Gauss Sum.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum = n * (n + 1) / 2;
        int actual_sum = 0;
        for (int num : nums) {
            actual_sum += num;
        }
        cout << expected_sum - actual_sum << '\n';
        return expected_sum - actual_sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1};
    sol.missingNumber(nums);
    return 0;
}