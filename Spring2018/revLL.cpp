/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* HEAD;

class Solution {
public:
    ListNode* util(ListNode* head) {
                
        if (head->next == NULL) {
            HEAD = head;
            return HEAD;            
        }
        
        ListNode* temp = util(head->next);
        temp->next = head;
        head->next = NULL;
        return head;     
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* temp = util(head);
        return HEAD;
    }
};
