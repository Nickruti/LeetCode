// url - https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        ListNode *slowptr, *fastptr;
        
        slowptr = head;
        fastptr = head;
        
        while(fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
           
            if(fastptr == slowptr)
            {
                slowptr = head;
                while(fastptr != slowptr)
                {
                    fastptr = fastptr->next;
                    slowptr = slowptr->next;
                }
                return slowptr;
            }
        }
        return NULL;
        
    }
};
