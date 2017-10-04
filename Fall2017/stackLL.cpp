#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int val):data(val), next(NULL){}
	~Node(){}	
};

int main()
{
	int choice;
	Node* top = NULL;
	bool flag = true;
	while(flag)
	{
		cout<<"Enter stack operation to perform\n";
		cout<<"1.Push	2.Pop 3.Empty Stack	4.Top data\n";
		cin>>choice;
		switch(choice)
		{
			case 1: {
					cout<<"Enter data to push\n";
					int data;
					cin>>data;
					if (top == NULL)
					{
						top = new Node(data);
					}
					else
					{
						Node* temp = new Node(data);
						temp->next = top;
						top = temp;
					}
				}
				break;
			case 2: {
					if (top == NULL)
					{
						cout<<"Empty Stack\n";
						
					}
					else
					{
						Node* temp = top;
						top = top->next;
						cout<<"Pop "<<temp->data<<endl;
						delete temp;
					}
				}
				break;
			case 3: {
					while (top != NULL)
					{
						cout<<"Pop "<<top->data<<endl;
						Node* temp = top;
						top = top->next;
						delete temp;
					}
				}
				break;
			case 4: {
					if (top != NULL)
						cout<<"top element "<<top->data<<endl;
					else
						cout<<"Empty stack\n";
				}
				break;
			default: { cout<<"Invalid option\n";
					flag = false; }
		}
	}

	return 0;
}
