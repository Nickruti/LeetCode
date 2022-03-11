// Url - https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int cnt = 0;
        
        ListNode *ptr1 = head;
        while(ptr1!=NULL)
        {
            cnt++;
            ptr1 = ptr1->next;
        }
        
        k = k % cnt;
        
        for(int i = 0; i < k; i++)
        {
            ListNode *ptr1 = head;
            ListNode *ptr2 = head;
            while(ptr2->next != NULL)
            {
                ptr2 = ptr2->next;
            }
            
            ptr2->next = ptr1;
            
            while(ptr1->next != ptr2)
            {
                ptr1 = ptr1->next;
            }
            
            ptr1->next = NULL;  
            head = ptr2;

        }
        
        return head;
    }
};