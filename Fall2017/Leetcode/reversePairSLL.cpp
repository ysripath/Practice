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
    void rev(ListNode* first, ListNode* second)
    {
        first->next = second->next;
        second->next = first;
        
    }
    ListNode* swapPairs(ListNode* head) {
        bool flag = false;
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* first = NULL;
        ListNode* second = NULL;
        
        first = head;
        second = head->next;
        
        if (second->next == NULL)
        {
            rev(first,second);
            head = second;
            return head;
        }
        
        ListNode* cur = head;
        ListNode* temp = NULL;
        while (second->next != NULL)
        {
            rev(first, second);
            if (temp != NULL)
            {
                temp->next = second;
            }
            if (!flag)
            {
                head = second;
                flag = true;
            }
            temp = first;
            cur = first;
            first = cur->next;
            if (first->next == NULL)
                return head;
            second = first->next;
        }
        cur->next = second;
        second->next = first;
        first->next = NULL;
        return head;
    }
};
