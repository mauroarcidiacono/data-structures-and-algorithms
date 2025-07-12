# 1046. Last Stone Weight
# https://leetcode.com/problems/last-stone-weight/description/
# Difficulty: Easy
# Strategy: Heap.

import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        while (len(stones) > 1):
            first = abs(heapq.heappop(stones))
            second = abs(heapq.heappop(stones))

            if first != second:
                heapq.heappush(stones, -(first - second))

        return -stones[0] if stones else 0


def test():
    sol = Solution()

    stones = [2,7,4,1,8,1]

    return sol.lastStoneWeight(stones)

print(test())
