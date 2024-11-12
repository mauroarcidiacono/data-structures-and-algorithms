// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/description/
// Difficulty: Easy
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int n = nums.size();
        int pos = n - 1;
        vector<int> results(n);

        while (i <= j) {
            int sq1 = nums[i] * nums[i];
            int sq2 = nums[j] * nums[j];

            if (sq2 >= sq1) {
                results[pos] = sq2;
                j--;
            } else if (sq2 < sq1) {
                results[pos] = sq1;
                i++;
            }

            pos--;
        }

        for (int n : results) {
            cout << n << ' ';
        }
        cout << '\n';

        return results;
    }
};

int main() {
    vector<int> nums = {-7,-3,2,3,11};
    Solution sol;
    sol.sortedSquares(nums);

    return 0;
}