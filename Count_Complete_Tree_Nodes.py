'''
Problem url - https://leetcode.com/problems/count-complete-tree-nodes/
'''
#Runtime: 68 ms, faster than 93.68% of Python3 online submissions for Count Complete Tree Nodes.
#Memory Usage: 21.5 MB, less than 31.51% of Python3 online submissions for Count Complete Tree Nodes.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = []
        height = 0
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            height += 1
            root = root.right
        return (height)
