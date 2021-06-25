#----------Runtime: 60 ms, faster than 97.02% of Python3 online submissions for Remove Linked List Elements.
# ---------Memory Usage: 17.1 MB, less than 90.13% of Python3 online submissions for Remove Linked List Elements.
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
    
        if head is None:
            return head
        
        temp = head
        while temp is not None:
            if temp.val == val and temp == head:
                head = head.next
            elif temp.val != val:
                prev = temp
            else:
                prev.next = temp.next
            temp = temp.next
        return head
        
