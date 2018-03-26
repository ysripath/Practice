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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
      ListNode* HEAD = new ListNode(0);
        
      ListNode* cur = head;
      HEAD->next = cur;
      cur = HEAD;  
      while ( cur->next->next)
      {
          while (cur->next->next && cur->next->val == val)
          {
              cur->next->val = cur->next->next->val;
              cur->next->next = cur->next->next->next;
          }
          
          if (cur->next->next == NULL)
          {
              if (cur->next->val == val)
                  cur->next = NULL;
              return HEAD->next;
          }
          cur = cur->next;
      }
      if (cur->next->val == val)
      {
          cur->next = NULL;
      }
        
      return HEAD->next;  
    }
};
