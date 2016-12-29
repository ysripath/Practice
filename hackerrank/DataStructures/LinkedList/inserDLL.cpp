#include <iostream>

using namespace std;


//
//    Insert Node in a doubly sorted linked list 
//    After each insertion, the list should be sorted
//   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   };

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    if (head == NULL)
        {
        head = new Node;
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        return head;
    }
    Node* tempH = head;
    while (head->next != NULL && head->next->data <= data)
        {
        head = head->next;
    }
    if (head->next == NULL)
        {
        Node* temp1 = new Node;
        temp1->data = data;
        temp1->prev = head;
        head->next = temp1;
        temp1->next = NULL;
    }
    else
        {
         Node* temp = new Node;
        temp->data = data;
        temp->prev = head;
        temp->next = head->next;
        head->next = temp;
        temp->next->prev = temp;
    }
    return tempH;
}


int main()
{
	int n;
cin>>n;
int k;
Node* head = NULL;
for (int i = 0; i < n; i++)
{
 cin>>k;
 head = SortedInsert(head,k);	
}
while (head != NULL)
{
	cout<<head->data<<" ";
	head = head->next;
}
return 0;
}
