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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        
        ListNode* hare = head;
        ListNode* turtle = head;
        
        while (hare->next->next != NULL)
        {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle)
                return true;
            if (hare->next == NULL)
                return false;
        }
        return false;
    }
};
