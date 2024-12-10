// 1133. Largest Unique Number
// https://leetcode.com/problems/largest-unique-number/description/
// Difficulty: Easy
// Strategy: hash map
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        for (auto& [key, value] : counts) {
            if (key > ans && value == 1) {
                ans = key;
            }
        }

        cout << ans << '\n';
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {9,9,8,8};
    sol.largestUniqueNumber(nums);
    return 0;
}