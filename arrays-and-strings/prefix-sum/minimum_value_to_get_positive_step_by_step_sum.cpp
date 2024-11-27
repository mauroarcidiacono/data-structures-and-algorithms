// 1413. Minimum Value to Get Positive Step by Step Sum
// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/
// Difficulty: Easy

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minStartValue(vector<int>& nums) {
            int prefixSum = 0;
            int minPrefixSum = 0;

            for (int num : nums) {
                prefixSum += num;
                if (prefixSum < minPrefixSum) {
                    minPrefixSum = prefixSum;
                }
            }

            cout << 1 - minPrefixSum << '\n';
            return 1 - minPrefixSum;
        }
};

int main() {
    vector<int> nums = {-3,2,-3,4,2};
    Solution sol;
    sol.minStartValue(nums);

    return 0;

}

