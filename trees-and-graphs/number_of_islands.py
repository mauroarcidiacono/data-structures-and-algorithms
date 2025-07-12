# 200. Number of Islands
# https://leetcode.com/problems/number-of-islands/
# Difficulty: Medium
# Strategy: DFS
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def calc_neighbours(i, j):
            neighbours = []
            for dir in directions:
                i_check = i + dir[0]
                j_check = j + dir[1]

                if 0 <= i_check < rows and 0 <= j_check < cols and grid[i_check][j_check] == "1" and (i_check, j_check) not in seen:
                    seen.add((i_check, j_check))
                    neighbours.append((i_check, j_check))

            return neighbours


        def dfs(i, j):
            neighbours = calc_neighbours(i, j)
            for neighbour in neighbours:
                dfs(neighbour[0], neighbour[1])


        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        rows = len(grid)
        cols = len(grid[0])
        seen = set()
        ans = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] != "0" and (i, j) not in seen:
                    seen.add((i, j))
                    dfs(i, j)
                    ans += 1

        return ans
    

def test():
    sol = Solution()

    grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]

    return sol.numIslands(grid)


print(test())