# 347. Top K frequent Elements
# https://leetcode.com/problems/top-k-frequent-elements/description/
# Difficulty: Medium
# Strategy: Heap and hashmap.
from typing import List
from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        heap = []

        for key, val in counts.items():
            heapq.heappush(heap, (val, key))
            if len(heap) > k:
                heapq.heappop(heap)

        return [key for val, key in heap]
    

def test():
    nums = [1,1,1,2,2,3]
    k = 2

    sol = Solution()
    return sol.topKFrequent(nums, k)


print(test())