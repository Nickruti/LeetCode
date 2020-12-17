'''
problem url - https://leetcode.com/explore/featured/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3568/
'''

#------------- Recursive Solution but not that effective = 56ms to run ------------------------
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution: 
    def isValidBST(self, root: TreeNode) -> bool:
        
        def isBST(node, minValue, maxValue):
            if node is None:
                return True

            if node.val <= minValue or node.val >= maxValue:
                return False

            return (isBST(node.left, minValue, node.val)) and (isBST(node.right, node.val, maxValue))
        
        return isBST(root, -10000000000, 10000000000)
    
#------------- Solution using Stack = 16ms to run ------------------------------------
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        if not root:
            return True
        stack = []
        pre = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pre != None and pre.val >= root.val:
                return False
            pre = root
            root = root.right
            
        return True
