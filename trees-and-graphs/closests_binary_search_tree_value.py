# 270. Closest Binary Search Tree Value
# https://leetcode.com/problems/closest-binary-search-tree-value/
# Difficulty: Easy
# Strategy: DFS + guide traversal toward the target using the BST property, and at each step, compare and update the closest value found so far.

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:        
        closest = root.val
        child = root.left if target < root.val else root.right

        if child:
            child_closest = self.closestValue(child, target)

            if abs(child_closest - target) < abs(closest - target):
                closest = child_closest
            elif abs(child_closest - target) == abs(closest - target):
                closest = min(child_closest, closest)
                
        return closest


def test():
    sol = Solution()

    root = TreeNode(4)
    node0 = TreeNode(2)
    node1 = TreeNode(5)
    node2 = TreeNode(1)
    node3 = TreeNode(3)

    root.left = node0
    root.right = node1
    node0.left = node2
    node0.right = node3

    target = 3.5

    return sol.closestValue(root, target)


print(test())