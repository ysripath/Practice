// Sort LL contating only 0, 1 and 2 in ascending  order

#include <iostream>
#include <vector>


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
	// With aux space consumption
	int arr[3] = {0, 0, 0};
	
	Node* node = head;
	while (node != NULL)
	{
		switch(node->data)
		{
			case 0: arr[0]++;
				break;
			case 1: arr[1]++;
				break;
			case 2: arr[2]++;
				break;
			default: cout<<"Wrong input in SLL\n";
		}
		node = node->next;
	}

	node = head;
	while (node != NULL)
	{
		if (arr[0] != 0)
		{
			node->data = 0;
			arr[0]--;
		}
		else if (arr[1] != 0)
		{
			node->data = 1;
			arr[1]--;
		}
		else if (arr[2] != 0)
		{
			node->data = 2;
			arr[2]--;
		}
		node = node->next;
	}
	return head;
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
