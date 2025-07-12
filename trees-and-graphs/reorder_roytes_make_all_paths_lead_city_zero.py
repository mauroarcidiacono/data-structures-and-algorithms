# 1466. Reorder Routes to Make All Paths Lead to the City Zero
# https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
# Difficulty: Medium
# Strategy: DFS
from typing import List
from collections import defaultdict

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        def dfs(node):
            ans = 0
            for neighbour in graph[node]:
                if neighbour not in seen:
                    seen.add(neighbour)
                    if (node, neighbour) in roads:
                        ans += 1
                    ans += dfs(neighbour) 
            return ans

        roads = set()
        graph = defaultdict(list)
        for (x, y) in connections:
            graph[x].append(y)
            graph[y].append(x)
            roads.add((x, y))

        seen = set()
        seen.add(0)
        return dfs(0)


def test():
    sol = Solution()
    connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
    n = 6

    return sol.minReorder(n, connections)


print(test())