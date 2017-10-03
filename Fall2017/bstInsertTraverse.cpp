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
		~Node()
		{
			delete left;
			delete right;
		}
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


// RIght View of the BST
int rightViewUtil(Node* node, int level, bool tempArr[])
{
        if (node->right != NULL)
        {
                rightViewUtil(node->right, level+1, tempArr);
        }
        if (tempArr[level] == false)
        {
                cout<<node->data<<" ";
                tempArr[level] = true;
        } 
        if (node->left != NULL)
        {
                rightViewUtil(node->left, level + 1, tempArr);
        }
}

void rightView(Node* head)
{
        if (head == NULL)
                return;

        cout<<"Right View of the BST\n";
        // assuming only 1000 nodes are there
        bool tempArr[1000] = {false};

        rightViewUtil(head, 1, tempArr);
}
// Left View of the BST

int leftViewUtil(Node* node, int level, bool tempArr[])
{
	if (node->left != NULL)
	{
		leftViewUtil(node->left, level+1, tempArr);
	}
	if (tempArr[level] == false)
	{
		cout<<node->data<<" ";
		tempArr[level] = true;
	}
	if (node->right != NULL)
	{
		leftViewUtil(node->right, level + 1, tempArr);
	}
}

void leftView(Node* head)
{
	if (head == NULL)
		return;
	
	cout<<"Left View of the BST\n";
	// assuming only 1000 nodes are there
	bool tempArr[1000] = {false};

	leftViewUtil(head, 1, tempArr);
}

//RIght View of the BST

//Top view of the BST

// Bottom view of the BST

int removeLeafUtil(Node* node)
{
	if (node->left == NULL && node->right == NULL)
		return 0;
	else
		return 1;
}


void removeLeafNodes(Node* head)
{
	if (head == NULL)
		return;
	//if (head->left == NULL && head->right == NULL)
	//	return;
	
	if (head->left != NULL && !removeLeafUtil(head->left))
	{
		delete (head->left);
		head->left = NULL;
	}
	if (head->right != NULL && !removeLeafUtil(head->right))
	{
		delete (head->right);
		head->right = NULL;
	}

	if (head->left != NULL)
	{
		removeLeafNodes(head->left);
	}
	if (head->right != NULL)
		removeLeafNodes(head->right);
	return;	
}

// find the height of BST
int findHeight(Node* head)
{
	if (head == NULL)
		return 0;

	return (1 + max(findHeight(head->left),findHeight(head->right)));
}


// find number of nodes
int findNumberOfNodes(Node* head)
{
	if (head == NULL)
		return 0;
	if (head->left == NULL && head->right == NULL)
		return 1;
	else
		return (1+findNumberOfNodes(head->left)+findNumberOfNodes(head->right));	

}


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


	cout<<"Total number of nodes in BST "<<findNumberOfNodes(head)<<endl;

	cout<<"Height of the BST is "<<findHeight(head)<<endl;
	//cout<<"Remove Leaf nodes\n";
	//removeLeafNodes(head);
	//cout<<"BST Traversal\n";
        //traverseBST(head);
	cout<<"Left View of the BST\n";
	leftView(head);
	cout<<endl<<endl;
	rightView(head);
	cout<<endl;
        cout<<endl;
	return 0;
}
