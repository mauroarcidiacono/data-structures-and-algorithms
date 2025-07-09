# 98. Validate Binary Search Tree
# https://leetcode.com/problems/validate-binary-search-tree/
# Difficulty: Medium
# Strategy: DFS + dynamic bounds propagation.
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(node, small, large):
            if not node:
                return True

            if not (small < node.val < large):
                return False

            left = dfs(node.left, small, node.val)
            right = dfs(node.right, node.val, large)

            return left and right
        
        return dfs(root, float("-inf"), float("inf"))


def test() -> bool:
    sol = Solution()

    root = TreeNode(5)
    node0 = TreeNode(1)
    node1 = TreeNode(4)
    node2 = TreeNode(3)
    node3 = TreeNode(6)

    root.left = node0
    root.right = node1
    node1.left = node2
    node1.right = node3

    return sol.isValidBST(root)


print(test())
