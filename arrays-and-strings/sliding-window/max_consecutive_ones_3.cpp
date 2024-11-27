// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/description/
// Difficulty: Medium
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int left = 0, curr = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                curr++;
            }

            while (curr > k) {
                if (nums[left] == 0) {
                    curr--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        cout << ans << '\n';

        return ans;
    }
};

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution sol;
    sol.longestOnes(nums, k);

    return 0;
}