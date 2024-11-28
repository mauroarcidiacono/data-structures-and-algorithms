// 1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/description/
// Difficulty: Easy
// Strategy: prefix sum.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix = {nums[0]};
        for (int i = 1 ; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[prefix.size() - 1]);
        };

        for (int num : prefix) {
            cout << num << " ";
        }

        return prefix;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution sol;
    sol.runningSum(nums);

    return 0;
}