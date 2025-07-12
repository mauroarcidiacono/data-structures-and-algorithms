
# 704. Binary Search
# https://leetcode.com/problems/binary-search/description/
# Difficulty: Medium
# Strategy: Binary search.
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        
        while right >= left:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid

            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1

        return -1
    

def test():
    sol = Solution()
    nums = [-1,0,3,5,9,12]
    target = 5
    return sol.search(nums, target)

print(test())