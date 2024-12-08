// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/description/
// Difficulty: Medium
// Strategy: prefix sum and hash map.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts = {{0, 1}};
        int curr = 0, ans = 0;

        for (int num : nums) {
            curr += num;
            ans += counts[curr - k];
            counts[curr]++;
        }
        cout << ans << '\n';
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    int k = 3;
    sol.subarraySum(nums, k);
    return 0;
}