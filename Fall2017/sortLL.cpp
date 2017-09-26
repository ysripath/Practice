#include <iostream>


using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int val):data(val){}
	~Node();
};

int size = 0;
void display(Node* node)
{
	size = 0;
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
		size++;
	}
	cout<<endl;
}


Node* sort(Node* head)
{
	// BUbble sort
	while (size > 0)
	{
		

	}
}

int main()
{
	Node* head = NULL;
	Node* cur = NULL;

	cout<<"Enter the number of nodes\n";
	int N;
	cin>>N;
	
	while (N>0)
	{
			int temp;
		cin>>temp;
		if (head == NULL)
		{
			head = new Node(temp);
			cur = head;			
		}
		else {
			cur->next = new Node(temp);
			cur = cur->next;
		}
	N--;
	}

	cout<<"Input list is \n";
	display(head);

	cout<<"Sorted List is\n";
	head = sort(head);
	display(head);
	
	return 0;
}
