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
    int findL(ListNode* head)
    {
        int l = 1;
        while (head != NULL)
        {
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB)
            return headA;
        if (headA == NULL || headB == NULL)
            return NULL;
        int lA = findL(headA);
        int lB = findL(headB);
        int k = abs(lA-lB);
        ListNode* a = headA;
        ListNode* b = headB;
        if (k != 0) {
        if (lA > lB)
        {
            int temp = 0;
            while (temp != k)
            {
                a = a->next;
                temp++;
            }
        }
        else
        {
            int temp = 0;
            while (temp != k)
            {
                b = b->next;
                temp++;
            }
            
        }
        }
        if (a==b)
            return a;
        while (a != NULL && b != NULL)
        {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        
        return NULL;
    }
};
