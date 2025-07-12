# 2208. Minimum Operations to Halve Array Sum
# https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
# Difficulty: Medium
# Strategy: Heap.
from typing import List
import heapq

class Solution:
    def halveArray(self, nums: List[int]) -> int:
        half = sum(nums) / 2
        nums = [-n for n in nums]
        heapq.heapify(nums)
        ans = 0

        while (half > 0):
            ans += 1
            current_half_max = heapq.heappop(nums) / 2
            half += current_half_max
            heapq.heappush(nums, current_half_max)

        return ans
    
def test():
    sol = Solution()
    nums = [5,19,8,1]
    return sol.halveArray(nums)

print(test())