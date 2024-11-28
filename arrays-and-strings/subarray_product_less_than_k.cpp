// 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/description/
// Difficulty: Medium
// Strategy: sliding window.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, numberOfSubarrays = 0;
        int curr = 1;
        if (k <= 1) return 0;

        for (int right = 0; right < nums.size(); right++) {
            curr = curr * nums[right];
            while (curr >= k) {
                curr /= nums[left];
                left++;
            }
            numberOfSubarrays += right - left + 1;
        }

        cout << numberOfSubarrays << '\n';
        return numberOfSubarrays;
    }    
};

int main() {
    Solution sol;
    vector<int> nums = {10,5,2,6};
    int k = 100;
    sol.numSubarrayProductLessThanK(nums, k);

    return 0;
}