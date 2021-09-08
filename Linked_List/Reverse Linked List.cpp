// url - https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        
        ListNode *p, *n1, *n2;
        
        p = NULL;
        n1 = head;
        n2 = head->next;
        
        while(n2)
        {
            n1->next = p;
            p = n1;
            n1 = n2;
            n2 = n2->next;
        }
        n1->next = p;
        return n1;
        
        
        
    }
};
