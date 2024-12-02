// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
// Difficulty: Easy
// Strategy: hash map.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (dic.find(complement) != dic.end()) {
                cout << i << ", " << dic[complement] << '\n';
                return {i, dic[complement]};
            }
            dic[nums[i]] = i;
        }
        cout << -1 << ", " << -1 << '\n';
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    sol.twoSum(nums, target);

    return 0;
}