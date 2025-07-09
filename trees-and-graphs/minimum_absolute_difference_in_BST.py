# 530. Minimum Absolute Difference in BST
# https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
# Difficulty: Easy
# Strategy: in order DFS traversal
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node: return
            
            dfs(node.left)
            values.append(node.val)
            dfs(node.right)

        values = []
        dfs(root)
        ans = float("inf")
        for i in range(1, len(values)):
            ans = min(ans, values[i] - values[i - 1])

        return ans
    

def test() -> int:
    sol = Solution()

    root = TreeNode(4)
    node0 = TreeNode(2)
    node1 = TreeNode(1)
    node2 = TreeNode(3)
    node3 = TreeNode(6)

    root.left = node0
    root.right = node3
    node0.left = node1
    node0.right = node2

    return sol.getMinimumDifference(root)

print(test())
