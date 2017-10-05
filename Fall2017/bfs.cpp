#include "qLib.h"
//#include "ll.h"
//#include <iostream>

using namespace std;

class node
{
	public:
		int data;
		node* left;
		node* right;
		node(int val):data(val),left(NULL), right(NULL){}
		~node(){}
};

node* bstInsert(node* head, int val)
{
	if (head == NULL)
        {
                head = new node(val);
                return head;
        }

        node* temp = head;
        while (temp->left != NULL || temp->right != NULL)
        {
                if (temp->data < val)
                {
                        if (temp->right != NULL)
                        {
                                temp = temp->right;
                                continue;
                        }
                        else
                        {
                                temp->right = new node(val);
                                return head;
                        }
                }
                else if (temp->data >= val)
                {
                        if (temp->left != NULL)
                        {
                                temp = temp->left;
                                continue;
                        }
                        else
                        {
                                temp->left = new node(val);
                                return head;
                        }

                }

        }

        if (temp->left == NULL && temp->data >= val)
        {
                temp->left = new node(val);
                return head;
        }
        else if (temp->right == NULL && temp->data < val)
        {
                temp->right = new node(val);
                return head;
        }
}


void inorder(node* head)
{
	if (head == NULL)
		return;
	inorder(head->left);
	cout<<head->data<<" ";
	inorder(head->right);
}
int main()
{
	node* head = NULL;
	Q<node> q;
	cout<<"Enter number of nodes\n";
	int N;
	cin>>N;
	while (N > 0)
	{
		int temp;
		cin>>temp;
		head = bstInsert(head, temp);
		N--;
	}

	cout<<"Inorder traversal  of the tree is\n";
	inorder(head);
	cout<<"Test QLib\n";

	q.insert(head);
	q.remove();
	return 0;
}
