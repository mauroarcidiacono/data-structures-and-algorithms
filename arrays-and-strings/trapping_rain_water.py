# 42. Trapping Rain Water
# https://leetcode.com/problems/trapping-rain-water/
# Difficulty: Hard
# Strategy: Two pointers. 
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n < 3:
            return 0

        left_max = [0] * n
        right_max = [0] * n
        
        left_max[0] = height[0]
        for i in range(1, n):
            left_max[i] = max(left_max[i-1], height[i])

        right_max[-1] = height[-1]
        for i in range(n-2, -1, -1):
            right_max[i] = max(right_max[i+1], height[i])

        trapped = 0
        for i in range(n):
            trapped += min(left_max[i], right_max[i]) - height[i]

        return trapped
    

def test():
    sol = Solution()
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    return sol.trap(height)

print(test())