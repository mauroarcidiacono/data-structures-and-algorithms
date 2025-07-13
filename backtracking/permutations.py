# 46. Permutations
# https://leetcode.com/problems/permutations/description/
# Difficulty: Medium
# Strategy: Backtracking.
from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []

        def backtrack(curr):
            if len(curr) == n:
                ans.append(curr[:])
                return
            
            for num in nums:
                if num not in curr:
                    curr.append(num)
                    backtrack(curr)
                    curr.pop()

        backtrack([])
        return ans


def test():
    sol = Solution()
    nums = [1,2,3]
    return sol.permute(nums)

print(test())