#include <iostream>

using namespace std;

class ListNode
{
        public:
                int data;
                ListNode* next;
                ListNode(int x):data(x),next(NULL){}
};

ListNode* midNode = NULL;

int length;
int mid = 0;
bool oddFlag = false;
int lSLL(ListNode* node)
{
       ListNode* midLocal = node;
    length = 1;
    while (node->next != NULL && node->next->next != NULL)
    {
        node = node->next->next;
        length+=2;
        midLocal = midLocal->next;        
    }
        if (node->next != NULL)
        {
                length++;
                midLocal = midLocal->next;
        }

    if (length % 2 != 0)
	{
        midNode = midLocal->next;
	oddFlag = true;
	}
    else
        midNode = midLocal;
    
    return length;
}



 // For updating the mid node of the LL after finding out LL lengt // For checking length of LL


void findLength(ListNode* node)
{
    ListNode* midLocal = node;
    length = 1;
    while (node->next != NULL && node->next->next != NULL)
    {
        node = node->next->next;
        length+=2;
        midLocal = midLocal->next;        
    }
    
    if (node->next != NULL)
    {
        length++;
        midLocal = midLocal->next;
    }
    mid = length/2;
    if (length % 2 != 0)
    {
        midNode = midLocal->next;
           
    }
    else
        midNode = midLocal;
    
    
    
    //return length;    
}

int recursiveCount;
bool recursiveTraverse(ListNode* node)
{
    if (recursiveCount < mid)
    {
        recursiveCount++;
        if (recursiveTraverse(node->next))
        {
            if (node->data == midNode->data)
            {
                midNode = midNode->next;
                return true;
            }
            else
                return false;
        }
        else
            return false; 
    }
    else if (recursiveCount == mid && oddFlag)
	{
		recursiveCount++;
		return true; 
	}
   else  if (node->data == midNode->data)
        {
            recursiveCount++;
            midNode= midNode->next;
            return true;
        }
        else
            return false;
        
    
}


 bool isPalindrome(ListNode* head) {
        // Check if node is NULL
        if (head == NULL)
            return false;
        
        // Check if LL is just one node
        if (head-> next == NULL)
            return true;
        
        findLength(head);
        
        return recursiveTraverse(head);
        
        
    }

int main()
{
        int n;
        cout<<"Enter number of nodes\n";
        cin>>n;
        cout<<"enter the nodes\n";
        int temp;
        ListNode* head = NULL;
        ListNode* cur = NULL;

        while (n != 0)
        {
                cin>>temp;
                if (head == NULL)
                {
                        head = new ListNode(temp);
                        cur = head;
                }
                else
                {
                        cur->next = new ListNode(temp);
                        cur = cur->next;
                }
                n--;
        }

        cout<<"Length of the SLL is "<<lSLL(head)<<endl;

        cout<<"Mid node is "<<midNode->data<<endl;
	if (oddFlag)
		recursiveCount = 0;
	else 
		recursiveCount = 1;
		if (isPalindrome(head))
			cout<<"Palindrome\n";
		else
			cout<<"Not a palindrome\n";
        return 0;
}













