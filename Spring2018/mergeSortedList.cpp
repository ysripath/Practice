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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        // if either is empty
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                if (head == NULL) {
                    head = new ListNode(l1->val);                    
                    cur = head;
                } else {
                    cur->next = new ListNode(l1->val);
                    cur = cur->next;
                }
                l1 = l1->next;
            }
            else if (l2->val < l1->val)
            {
                if (head == NULL) {
                    head = new ListNode(l2->val);                    
                    cur = head;
                } else {
                    cur->next = new ListNode(l2->val);
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
        
        // one of them is empty
        if (l1 == NULL && l2 == NULL)
            return head;
        if (l1 == NULL)
        {
            while (l2 != NULL)
            {
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                l2 = l2->next;
            }
        }
        else if (l2 == NULL)
        {
            while (l1 != NULL)
            {
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                l1 = l1->next;
            }
        }
        return head;
    }
};
