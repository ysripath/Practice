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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        ListNode* temp2 = head;
        ListNode* temp = head;
        ListNode* prev;
        
        
        while (temp->next != NULL) {
            if (count < n) {
                count++;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
                prev = temp2;
                temp2 = temp2->next;
                count++;
            }
        }
        if (n==1 && count == 1){
            delete head;
            return NULL;
        }
        if (count ==  n) {
            ListNode* a = head;
            head = head->next;
            delete a;
            return head;
        }
        if (n == 1) {
            prev->next = NULL;
            delete temp2;
        }
        if(prev->next != NULL && temp2->next != NULL){
            prev->next = temp2->next;
            delete temp2;
        }
        if (head == NULL)
            return NULL;
        else
            return head;
    }
};