// Url - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        int lenLL = 0;
        ListNode* ptr1;
        ListNode* ptr2;
        ptr1 = head;
        ptr2 = head;
        
        while(ptr1 != NULL)
        {
            lenLL++;
            ptr1 = ptr1 -> next;
        }
        
        int secPos = lenLL - k + 1;
        ptr1 = head;
        
        for(int i = 1; i < k; i++)
        {
            ptr1 = ptr1->next;
        }
        
        for(int i = 1; i < secPos; i++)
        {
            ptr2 = ptr2->next;
        }

        int temp = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = temp;
        
        return head;
    }
};