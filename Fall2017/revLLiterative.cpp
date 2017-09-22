#include <iostream>


using namespace std;


class Node {
public:
	int data;
	Node* next;
	Node(int val):data(val),next(NULL){}
	~Node();
	

};

Node* head;
void traverseList(Node* node)
{
	while(node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}



void reverseIterative(Node* node);

Node* prev;
Node* cur;
Node* next;
int main()
{
	prev = NULL;
	cur = NULL;
	next = NULL;
	 cout<<"Enter the number of nodes\n";
        int N;
        cin>>N;
        cout<<"Enter nodes\n";
        head = NULL;
       
        while (N!=0)
        {
                int temp;
                cin>>temp;
                if (head == NULL) {
                        head = new Node(temp);
                        cur = head;
                }
                else {
                        cur->next = new Node(temp);
                        cur = cur->next;
                }
                N--;
        }
	cur = head;
	prev = head;
	next = head;
        cout<<"List input is \n";
        traverseList(head);
        cout<<"After reversing the LL\n";

        reverseIterative(head);
        traverseList(head);

	

	return 0;
}




void reverseIterative(Node* node)
{
	head = node;
	prev = node;
	cur = node;
	next = node;
	

	if (head->next == NULL)
		return;

	next = head->next;
	cur->next = NULL;

	Node* util = NULL;
	while (next != NULL)
	{
		util = next->next;
		next->next = cur;
		cur = next;
		next = util;
	}
	head = cur;
}

