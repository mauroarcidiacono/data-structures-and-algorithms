// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// Difficulty: Medium
// Strategy: prefix sum and hash map.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts{{0, 1}};
        int curr = 0, ans = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                curr += 1;
            }
            ans += counts[curr - k];
            counts[curr]++;
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