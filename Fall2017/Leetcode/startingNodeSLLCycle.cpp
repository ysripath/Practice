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
    ListNode* ifCycle(ListNode* head)
    {
        if (head->next == NULL || head->next->next == NULL)
            return NULL;
        
        ListNode* turtle = head;
        ListNode* hare = head;
        while (hare->next->next != NULL)
        {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle)
                return hare;
            if (hare->next == NULL)
                return NULL;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
            if (head == NULL)
                return NULL;
            ListNode* node = ifCycle(head);
            if (node == NULL)
                return NULL;
            
            ListNode* temp = head;
            while (temp != node)
            {
                temp = temp->next;
                node = node->next;
            }
            return temp;
    }
};
