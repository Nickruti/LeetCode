# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        
        visitedArr = []
        temp = head
        while temp is not None:
            if temp.val not in visitedArr:
                visitedArr.append(temp.val)
                prev = temp
            else:
                prev.next = temp.next
            temp = temp.next
        return head
            
