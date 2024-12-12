// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/description/
// Difficulty: Medium
// Strategy: hash map and prefix sum.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> counts = {{0, -1}};
        int prefix_sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += (nums[i] == 0) ? -1 : 1;
            if (counts.find(prefix_sum) == counts.end()) {
                counts[prefix_sum] = i;
            } else {
                ans = max(ans, i - counts[prefix_sum]);
            }
        }
        cout << ans << '\n';
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1};
    sol.findMaxLength(nums);
    return 0;
}