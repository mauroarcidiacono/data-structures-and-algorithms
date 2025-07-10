# 547. Number of Provinces
# https://leetcode.com/problems/number-of-provinces/
# Difficulty: Medium
# Strategy: DFS + hash map
from collections import defaultdict
from typing import List

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(node):
            for neighbour in graph[node]:
                if neighbour not in seen:
                    seen.add(neighbour)
                    dfs(neighbour)

        n = len(isConnected)
        graph = defaultdict(list)
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j]:
                    graph[i].append(j)
                    graph[j].append(i)

        seen = set()
        ans = 0

        for i in range(n):
            if i not in seen:
                ans += 1
                seen.add(i)
                dfs(i)

        return ans


def test():
    sol = Solution()
    isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    
    return sol.findCircleNum(isConnected)


print(test())
