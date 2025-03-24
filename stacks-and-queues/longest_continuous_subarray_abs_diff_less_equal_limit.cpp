// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
// Difficulty: Medium
// Strategy: two deques and sliding window.
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& nums, int limit) {
            deque<int> increasing;
            deque<int> decreasing;
            int left = 0;
            int ans = 0;

            for (int right = 0; right < nums.size(); right++) {
                while (!increasing.empty() && increasing.back() > nums[right]) {
                    increasing.pop_back();
                }
                while (!decreasing.empty() && decreasing.back() < nums[right]) {
                    decreasing.pop_back();
                }

                increasing.push_back(nums[right]);
                decreasing.push_back(nums[right]);

                while (decreasing.front() - increasing.front() > limit) {
                    if (decreasing.front() == nums[left]) {
                        decreasing.pop_front();
                    }
                    if (increasing.front() == nums[left]) {
                        increasing.pop_front();
                    }
                    left++;
                }
                ans = max (ans, right - left + 1);
            }
            cout << ans << '\n';
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> nums{10, 1, 2, 4, 7, 2};
    int limit = 5;
    sol.longestSubarray(nums, limit);
    return 0;
}
