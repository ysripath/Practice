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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* temp = head;
        
        while (temp->next != NULL && temp != NULL)
        {
            if (temp->val == temp->next->val)
            {
                ListNode* t = temp->next;
                if (t->next == NULL)
                   temp->next = NULL;
                else
                    temp->next = t->next;
                delete t;
            }
            else
            {
                temp = temp->next;
            }
            //temp = temp->next;
        }
        return head;
        
    }
};
