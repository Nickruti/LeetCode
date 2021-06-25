#Runtime: 20 ms, faster than 99.49% of Python3 online submissions for Convert Binary Number in a Linked List to Integer.
#Memory Usage: 14.3 MB, less than 8.12% of Python3 online submissions for Convert Binary Number in a Linked List to Integer.
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        
        count = 0
        temp = head
        
        while temp is not None:
            count += 1
            temp = temp.next
        
        ans = 0
        temp = head
        while count != 0:
            if temp.val == 1:
                ans += 2**(count-1)
            temp = temp.next
            count -= 1
            
        return ans
