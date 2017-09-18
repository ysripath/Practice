#include <iostream>

using namespace std;

class NodeList 
{
	public:
		int data;
		NodeList* next;
		NodeList(int x):data(x),next(NULL){}
};

NodeList* midNode = NULL;

int lSLL(NodeList* node)
{
	NodeList* midLocal = node;
    int length = 1;
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
        midNode = midLocal->next;
    else
        midNode = midLocal;
    
    return length;
}

int main()
{
	int n;
	cout<<"Enter number of nodes\n";
	cin>>n;
	cout<<"enter the nodes\n";
	int temp;
	NodeList* head = NULL;
	NodeList* cur = NULL;

	while (n != 0)
	{
		cin>>temp;
		if (head == NULL)
		{
			head = new NodeList(temp);
			cur = head;
		}
		else
		{
			cur->next = new NodeList(temp);
			cur = cur->next;
		}
		n--;
	}

	cout<<"Length of the SLL is "<<lSLL(head)<<endl;
	cout<<"Mid node is "<<midNode->data<<endl;

	return 0;
}
