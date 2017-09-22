#include <iostream>


using namespace std;


class Node {

public:
	int data;
	Node* next;

	Node(int val):data(val),next(NULL){}
	~Node();
	Node* getNext(){
		return next;
	}
	void setNext(Node* node) {
		next = node;
	}
	int getVal() {
		return data;
	}

};


Node* revList(Node* node);
void traverseList(Node* node);
Node* head;


int main()
{
	cout<<"Enter the number of nodes\n";
	int N;
	cin>>N;
	cout<<"Enter nodes\n";
	head = NULL;
	Node* cur = NULL;
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
	cout<<"List input is \n";
	traverseList(head);
	cout<<"After reversing the LL\n";

	Node* temp = revList(head);
	traverseList(head);
	return 0;
}



Node* revList(Node* node)
{
	if (node->next == NULL) {
		head = node;
		return node;
	}

	Node* temp = revList(node->next);
	temp->next = node;
	node->next = NULL;
	return node;
}


void traverseList(Node* node)
{
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;

}
