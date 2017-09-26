#include <iostream>


using namespace std;


class Node
{
// fix to make it private
public:
	
		int data;
		Node* left;
		Node* right;
	
		Node(int val):data(val), left(NULL), right(NULL){}
		~Node();
		void insertLeft(Node* node)
		{
			if (node != NULL)
				left = node;
		}
		void insertRight(Node* node)
		{
			if (node != NULL)
				right = node;
		}

		int getData()
		{
			return data;
		}

		void setData(int val)
		{
			data = val;
		}
};


bool checkBSTValidity(Node* head)
{
	if (head ==  NULL)
		return  true;
	Node* temp = head;
	bool flag = true;
	if (temp->left != NULL && temp->right != NULL)
	{
		if (temp->data >= temp->left->data && temp->data < temp->right->data)
			flag = true;
		else 
			flag = false;
	}
	else if (temp->left == NULL && temp->right == NULL)
		flag = true;
	else if (temp->left == NULL &&  temp->data > temp->right->data)
	{
		flag = false;
	}
	else if (temp->right == NULL && temp->data < temp->left->data)
	{
		flag = false;
	}
	return (flag && checkBSTValidity(head->left) && checkBSTValidity(head->right));
}


void traverseBST(Node* head)
{
//	Node* temp = head;
	// Inorder traversal
	if (head == NULL)
		return;
	traverseBST(head->left);
	cout<<head->data<<" ";
	traverseBST(head->right);

}


Node* insertNode(Node* head, int val)
{
	if (head == NULL)
	{
		head = new Node(val);
		return head;
	}
	
	Node* temp = head;
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
				temp->right = new Node(val);
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
				temp->left = new Node(val);
				return head;	
			}

		}

	}
	
	if (temp->left == NULL && temp->data >= val)
	{
		temp->left = new Node(val);
		return head;
	}
	else if (temp->right == NULL && temp->data < val)
	{
		temp->right = new Node(val);
		return head;
	}
	
}

int main()
{
	int N;
	cout<<"Enter the number of nodes in BST\n";
	cin>>N;

	Node* head = NULL;
	cout<<"Enter input\n";
	while (N>0)
	{
		int temp;
		cin>>temp;
		head = insertNode(head, temp);	
		N--;
	}

	cout<<"BST Traversal\n";
	traverseBST(head);
	cout<<endl;
	if (checkBSTValidity(head))
		cout<<"Valid BST\n";
	else
		cout<<"Not a valid BST\n";

	return 0;
}
