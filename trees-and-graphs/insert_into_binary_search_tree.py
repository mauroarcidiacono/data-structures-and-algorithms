# 701. Insert into a Binary Search Tree
# https://leetcode.com/problems/insert-into-a-binary-search-tree/
# Difficulty: Medium
# Strategy: DFS + guided structural recursion using the BST invariant.
from typing import Optional
import utils

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)

        if val < root.val:
            root.left = self.insertIntoBST(root.left, val)
        else:
            root.right = self.insertIntoBST(root.right, val)

        return root


def test():
    sol = Solution()

    root = TreeNode(4)
    node0 = TreeNode(2)
    node1 = TreeNode(7)
    node2 = TreeNode(1)
    node3 = TreeNode(3)

    root.left = node0
    root.right = node1
    node0.left = node2
    node0.right = node3

    val = 5
    l_ans = utils.tree_to_list(sol.insertIntoBST(root, val))
    return l_ans


print(test())
