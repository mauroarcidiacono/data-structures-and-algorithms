# 2294. Partition Array Such That Maximum Difference Is K
# https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/
# Difficulty: Medium
# Strategy: Greedy approach.
from typing import List

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        x = nums[0]
        ans = 1

        for i in range(len(nums)):
            if (nums[i] - x > k):
                x = nums[i]
                ans += 1

        return ans
    

def test():
    sol = Solution()
    k = 2
    nums = [3,6,1,2,5]
    return sol.partitionArray(nums, k)


print(test())