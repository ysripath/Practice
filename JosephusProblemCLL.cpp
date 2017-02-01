// Josephus problem using circular linked list


#include <iostream>
#include <list>


using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}NODE;


void solve(int n, int m)
{
	NODE* head = NULL;
	//cout << "enter the numbers corresponding to the people sitting in the table\n";
	int tempD;
	int listSize = n;
	for (int i = 1; i <= n; i++)
	{
		tempD = i;
		if (head == NULL)
		{
			head = new NODE();
			head->data = tempD;
			head->left = head;
			head->right = head;
		}
		else
		{
			NODE* temp = head;
			while (temp->right != head)
			{
				temp = temp->right;
			}
			NODE* tempNode = new NODE();
			tempNode->data = tempD;
			tempNode->right = head;
			tempNode->left = temp;
			temp->right = tempNode;
			head->left = tempNode;
		}
						
	}

	//Traverse LL
	cout << "entered set of data in the order of input\n";
	NODE* temp = head;
	while (temp->right != head)
	{
		cout << temp->data << " ";
		temp = temp->right;
	}
	cout << temp->data;
	cout << endl;

	// Josephus problem solution in order of N
	cout << "Josephus permutations\n";
	temp = head;
	int counter = 1;

	while (listSize >= m)
	{		
		if (counter % m == 0)
		{
			NODE* tempL = temp->left;
			tempL->right = temp->right;
 			temp->right->left = tempL;
			cout << temp->data << " ";
			delete temp;
			temp = tempL->right;
			//temp = tempL;
			listSize--;
			counter = 1;
		}
		else
		{
			temp = temp->right;
			counter++;
		}
	}
	cout << "\nSurvivors is/are \n";
	head = temp;
	while (temp->right != head)
	{
		cout << temp->data << " ";
		temp = temp->right;
	}
	cout << temp->data << endl;	
}

int main()
{
	cout << "Enter the n and m value for Josephus problem\n";
	int m, n;
	cin >> n >> m;
	solve(n, m);
	return 0;
}