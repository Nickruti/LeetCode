# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return 1
        
        temp = head
        count = 0
        while temp is not None:
            count += 1
            temp = temp.next
            
        temp = head
        firstList = []
        
        for i in range(int(count/2)):
            firstList.append(temp.val)
            temp = temp.next
        
        firstList.reverse()
        
        if count % 2 != 0:
            temp = temp.next
        
        notPalindrome = 0
        for i in range(int(count/2)):
            if firstList[i] != temp.val:
                notPalindrome = 1
                break
            
            temp = temp.next
            
        if notPalindrome == 1:
            return 0
        else:
            return 1
                
            
        
            
        
        
