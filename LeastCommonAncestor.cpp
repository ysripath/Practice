#include <iostream>
#include <stack>
typedef struct node
{
	int data;
	node* left;
	node* right;
}node;

using namespace std;


stack<int> s1, s2;
bool flag = true;
bool find(node*  root, int v)
    {
    if (root->data == v)
        {
        if (flag)
            {
            s1.push(root->data);
		cout<<"S1 top "<<s1.top()<<endl;
        }
        else
            {
            s2.push(root->data);
		cout<<"S2 top "<<s2.top()<<endl;
        }
        return true;
    }
    bool lFlag = true;
    if(root->left != NULL)
        {
        if (find(root->left, v))
            {
            if (flag)
{
                s1.push(root->data);
		cout<<"S1 top "<<s1.top()<<endl;
}
            else
{
                s2.push(root->data);
		 cout<<"S2 top "<<s2.top()<<endl;
}
            return true;
        }
        else
            lFlag = true;
    }
    if (root->right != NULL && lFlag)
        {
        if (find(root->right,v))
            {
            if (flag)
		{
                s1.push(root->data);
		 cout<<"S1 top "<<s1.top()<<endl;
		}
            else
		{
                s2.push(root->data);
		 cout<<"S2 top "<<s2.top()<<endl;
		}
            return true;
        }
        else
            lFlag = true;
    }
    if (lFlag)
        return false;
    else
        return true;
}

node* findNode(node* root,int v)
    {
    node* temp;
    if (root->data == v)
        return root;
    else if (root->left != NULL)
        {
       temp = findNode(root->left,v);
    }
    if (temp != NULL)
        return temp;
    else if (root->right != NULL)
        {
        temp = findNode(root->right,v);
    }
    if (temp != NULL)
        return temp;
    else
        return NULL;
}

node * lca(node * root, int v1,int v2)
{
    if (find(root, v1))
        {
        flag = false;
        if (find(root, v2))
            {
        /*if (s1.size() == s2.size())
            {
            while (s1.top() != s2.top())
                {
                s1.pop();
                s2.pop();                
            }
            //cout<<s1.top();
            return findNode(root,s1.top());
        }
        else if (s1.size() > s2.size())
            {
            while(s1.size() != s2.size())
                {
                s1.pop();
            }
             while (s1.top() != s2.top())
                {
                s1.pop();
                s2.pop();                
            }
          //  cout<<s1.top();
            return findNode(root,s1.top());
        }
        else
            {
            while(s1.size() != s2.size())
                {
                s2.pop();
            }
             while (s1.top() != s2.top())
                {
                s1.pop();
                s2.pop();                
            }
           // cout<<s1.top();
            return findNode(root,s1.top());
        }*/

	int size1 = s1.size();
	int* arr1 = new int[size1]; 
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = s1.top();
		s1.pop();
	}

	int size2 = s2.size();
	int* arr2 = new int[size2];
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = s2.top();
		s2.pop();
	}
	for (int i = size2 -1; i >= 0; i--)
		for (int j = size1 -1; j >=0; j--)
		{
			if (arr1[j] == arr2[i])
			{
				return findNode(root,arr1[j]);
			}
		}

        }
    }

   return root;
}

node* insert(node* root, int value)
{

	if(root==NULL)
  {
     node* temp=new node;
     temp->data=value;
     temp->left=NULL;
     temp->right=NULL;
     root=temp;
 }
 else if(root->data>value)
      root->left=insert(root->left,value);
  else if(root->data<value)
      root->right=insert(root->right,value);

  return root;
}



void inorder(node* root)
{
	if (root->left != NULL)
		inorder(root->left);
	cout<<root->data<<" ";
	if (root->right != NULL)
		inorder(root->right);
}
int main()
{
	int n;
	cout<<"enter the number of nodes\n";
	cin>>n;
	node* head = NULL;
	int value;
	for (int i = 0; i < n; i++)
	{
		cin>>value;
		head = insert(head, value);
	}

	//inorder(head);
	cout<<"Enter v1 and v2\n";
	int v1, v2;
	cin>>v1>>v2;
	head = lca(head, v1, v2);
	cout<<"LCA "<<head->data<<endl;
		
}
