# 2126. Destroying Asteroids
# https://leetcode.com/problems/destroying-asteroids/
# Difficulty: Medium
# Strategy: Greedy approach.
from typing import List

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for am in asteroids:
            if am <= mass:
                mass += am
            else:
                return False
        return True
    

def test():
    sol = Solution()
    mass = 10
    asteroids = [3,9,19,5,21]
    return sol.asteroidsDestroyed(mass, asteroids)


print(test())