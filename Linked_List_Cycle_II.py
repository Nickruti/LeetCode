'''
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        
        s = set() 
        temp = head 
        while (temp): 
          
             # If we have already has 
             # this node in hashmap it 
             # means their is a cycle 
             # (Because you we encountering 
             # the node second time). 
            if (temp in s): 
                return temp
     
            # If we are seeing the node for 
            # the first time, insert it in hash 
            s.add(temp) 
     
            temp = temp.next
        
'''
Input - 
[3,2,0,-4]
1

Output - 
tail connects to node index 1
'''
