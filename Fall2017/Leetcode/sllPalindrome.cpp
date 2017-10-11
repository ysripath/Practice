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
    ListNode* mid = NULL;
ListNode* utilNode = NULL;
bool util(ListNode* node)
{
    if (node == mid)
    {
        
        if (node->val == utilNode->val)
           {
                utilNode = utilNode->next;
                return true;
           }
        else
            return false;
    }
    else if (util(node->next))
    {
        if (node->val == utilNode->val)
        {
            utilNode = utilNode->next;
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
        return true;
       if (head->next == NULL)
        return true;
        ListNode* temp = NULL;
        ListNode* last = head;
        mid = head;
        bool flag = false; //odd length - false; even length - true
        int count = 1;
        
        while (last->next != NULL)
        {
            if (last->next->next != NULL)
            {
                last = last->next->next;
                temp = mid;
                mid = mid->next;
                count+=2;
            }
            else
            {
                last = last->next;
                count+=1;
                break;
            }            
        }
        utilNode = mid->next;
        if (count % 2 != 0)
        {
            
            mid = temp;     
        }     
            
        return util(head);
    }
};
