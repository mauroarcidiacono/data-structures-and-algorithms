// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// Difficulty: Medium
// Strategy: sliding window.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, odd_count = 0, ans = 0, prev = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 != 0) {
                odd_count++;
                prev = 0;
            }

            while (odd_count == k) {
                prev++;
                if (nums[left] % 2 != 0) {
                    odd_count--;
                }
                left++;
            }

            ans += prev;
            right++;
        }
        cout << ans << '\n';
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    sol.numberOfSubarrays(nums, k);
    return 0;
}