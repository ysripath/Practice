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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        // Only one node
        if (head->next == NULL)
            return head;
        if (head->next->next == NULL)
            return head;
        ListNode* oddHead = NULL;
        ListNode* evenHead = NULL;
        ListNode* oT = NULL;
        ListNode* eT = NULL;
        ListNode* odd = NULL;
        ListNode* even = NULL;
        
        // initialize known stuff
        oddHead = head;
        evenHead = head->next;
        oT = oddHead;
        eT = evenHead;
        odd = evenHead->next;
        // SPL case if only 3 nodes in SLL
        if (odd->next == NULL)
        {
            oT->next = odd;
            odd->next = eT;
            eT->next = NULL;
            return head;
        }
        even = odd->next;
        while (true)
        {
            oT->next = odd;
            eT->next = even;
            odd->next = NULL;
            oT = oT->next;
            eT = eT->next;
            if (even->next == NULL)
                break;
            //eT = eT->next;
            //oT = oT->next;
            odd = even->next;
            if (odd->next != NULL)
            {
                even = odd->next;
            }
            else
            {
                oT->next = odd;
                odd->next = NULL;
                oT= oT->next;
                //eT->next = NULL;
                break;
            }
        }
        eT->next = NULL;
        oT->next = evenHead;
        return head;
    }
};
