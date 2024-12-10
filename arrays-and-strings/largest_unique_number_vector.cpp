// 1133. Largest Unique Number
// https://leetcode.com/problems/largest-unique-number/description/
// Difficulty: Easy
// Strategy: vector.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int> counts(1001, 0);

        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        for (int i = 1000; i >= 0; i--) {
            if (counts[i] == 1) {
                cout << i << '\n';
                return i;
            }
        }

        cout << -1 << '\n';
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,7,3,9,4,9,8,3,1};
    sol.largestUniqueNumber(nums);
    return 0;
}