// 2090. K Radius Subarray Averages
// https://leetcode.com/problems/k-radius-subarray-averages/description/
// Difficulty: Medium
// Strategy: prefix sum.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long subarraySum;
        vector<long long> prefix(n, 0);
        vector<int> k_radius_avg_subarray(n, -1);

        if (k == 0) return nums;
        if (n < 2 * k + 1) return k_radius_avg_subarray;
        
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = k; i < n - k; i++) {
            subarraySum = prefix[i + k] - prefix[i - k] + nums[i - k];
            k_radius_avg_subarray[i] = subarraySum / (k * 2 + 1);
        }

        for (int num: k_radius_avg_subarray) {
            cout << num << " ";
        }

        return k_radius_avg_subarray;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    sol.getAverages(nums, k);
    
    return 0;
}