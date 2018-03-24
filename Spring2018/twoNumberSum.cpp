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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if both null
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        if (l1 == NULL || l2 == NULL)
        {
            if (l1 == NULL)
                return l2;
            else
                return l1;
        }
        
        ListNode* head = NULL;
        ListNode* cur = NULL;
        int carry = 0;
        while (l1 != NULL
              && l2 != NULL) {
            int temp = l1->val + l2->val + carry;
            int val = 0;
            if (temp > 9)
            {
                val = temp%10;
                carry = 1;
            }
            else
            {
                val = temp;
                carry = 0;
            }
            if (head == NULL)
            {
                head = new ListNode(val);
                cur = head;
            }
            else 
            {
                ListNode* tempNode = new ListNode(val);
                cur->next = tempNode;
                cur = cur->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL)
        {
            if (carry > 0)
            {
                if (l1->val+carry > 9)
                {
                    int t = l1->val + carry;
                    int v = t%10;
                    carry = 1;
                    cur->next = new ListNode(v);
                    cur = cur->next;
                    l1 = l1->next;
                }
                else
                {
                    int v = l1->val + carry;
                    carry = 0;
                    cur->next = new ListNode(v);
                    cur = cur->next;
                    l1 = l1->next;
                }
            }
            else 
            {
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                l1 = l1->next;
            }
        }
        
        while (l2 != NULL)
        {
            if (carry > 0)
            {
                if (l2->val+carry > 9)
                {
                    int t = l2->val + carry;
                    int v = t%10;
                    carry = 1;
                    cur->next = new ListNode(v);
                    cur = cur->next;
                    l2 = l2->next;
                }
                else
                {
                    int v = l2->val + carry;
                    carry = 0;
                    cur->next = new ListNode(v);
                    cur = cur->next;
                    l2 = l2->next;
                }
            }
            else 
            {
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (carry > 0)
            cur->next = new ListNode(carry);
        
        return head;
    }
};
