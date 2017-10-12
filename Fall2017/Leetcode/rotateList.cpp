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
    int getL(ListNode* node)
    {
        int count = 0;
        while (node != NULL)
        {
            count++;
            node = node->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        if (k == 0)
            return head;
        if (head->next == NULL)
            return head;
        ListNode* node = head;
        ListNode* last = NULL;
        ListNode* cur = NULL;
        int l = getL(head);
        int r;
        if (k > l)
        {
            r = k%l;
            k = k/l;
           // r--;
             while (r != 0)
        {            
                while (node->next != NULL)
                {
                    cur = node;
                    node = node->next;
                }
                cur->next = NULL;
                node->next = head;
                head = node;
            
                r--;
        }
        }
        else
        {
            while (k != 0)
        {            
                while (node->next != NULL)
                {
                    cur = node;
                    node = node->next;
                }
                cur->next = NULL;
                node->next = head;
                head = node;
            k--;
        }
        }
       
        return head;
    }
};
