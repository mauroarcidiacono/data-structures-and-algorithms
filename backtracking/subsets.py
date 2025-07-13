# 78. Subsets
# https://leetcode.com/problems/subsets/description/
# Difficulty: Medium
# Strategy: Backtracking.
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        
        def backtrack(curr, i):
            if i > n:
                return
            
            ans.append(curr[:])
            for j in range(i, len(nums)):
                curr.append(nums[j])
                backtrack(curr, j + 1)
                curr.pop()

        backtrack([], 0)
        return ans
        

def test():
    sol = Solution()
    nums = [1,2,3]
    return sol.subsets(nums)

print(test())