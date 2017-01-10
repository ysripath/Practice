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
int carryFind(int x, int y,int z = 0)
{
	int res = x + y + z;
	int temp = res % 10;
	return temp;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* res = NULL;
	ListNode* head = NULL;
	int carry = 0;
	while (l1 != NULL && l2 != NULL)
	{
		int temp = l1->val + l2->val + carry;
		if (temp > 9)
		{
			temp = carryFind(l1->val, l2->val, carry);
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		if (res == NULL)
		{
			res = new ListNode(temp);
			head = res;

		}
		else
		{
			res->next = new ListNode(temp);
			res = res->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	int temp;
	while (l1 != NULL)
	{
		if (carry == 1)
		{
			temp = carry + l1->val;
			if (temp > 9)
			{
				temp = carryFind(carry, l1->val);
				carry = 1;
			}
			else
				carry = 0;
			res->next = new ListNode(temp);			
		}
		else
		{
			res->next = new ListNode(l1->val);
		}
		res = res->next;
		l1 = l1->next;
	}
	while(l2 != NULL)
	{
		if (carry == 1)
		{
			temp = carry + l2->val;
			if (temp > 9)
			{
				temp = carryFind(carry, l2->val);
				carry = 1;
			}
			else
				carry = 0;
			res->next = new ListNode(temp);
		}
		else
		{
			res->next = new ListNode(l2->val);
		}
		res = res->next;
		l2 = l2->next;
	}
	if (carry == 1)
	{
		res->next = new ListNode(1);
	}
	return head;
}
};
