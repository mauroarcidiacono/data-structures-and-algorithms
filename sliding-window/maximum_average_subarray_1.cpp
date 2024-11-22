// 643. Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/description/
// Difficulty: Easy
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double curr = 0;
        for (int i = 0; i < k; i++){
            curr += nums[i];
        }

        double ans = curr/k;

        for (int i = k; i < nums.size(); i++){
            curr += nums[i] - nums[i - k];
            ans = max(ans, curr/k);
        }

        cout << ans << '\n';

        return ans;
    }
};

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution sol;
    sol.findMaxAverage(nums, k);

    return 0;
}