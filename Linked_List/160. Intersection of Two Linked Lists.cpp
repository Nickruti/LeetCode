// Url - https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {        
        ListNode *ptrA, *ptrB;
        ptrA = headA;
        ptrB = headB;
        
        while(ptrA != ptrB)
        {
            ptrA = !ptrA ? headB : ptrA->next;
            ptrB = !ptrB ? headA : ptrB->next;
        }
        
        return ptrA;
    }
};