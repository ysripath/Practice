#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> S1;
stack<int> S2;
bool sFlag = false;
int head;

void enqueue();
void dequeue();
void display();

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N;
	int choice;
	cin>>N;
	while(N != 0)
	{
		cin>>choice;
		switch(choice)
		{
			case 1: { enqueue();  break;}
			case 2: { dequeue(); break;}
			case 3: { cout<<head<<endl; break;}//display(); break;}
			default: { cout<<"Invalid query\n"; break;}
		}
	N--;
	}
    return 0;
}
void transfer(bool flag)
{
	if (flag) // Transfer from S1 to S2
	{
		while (S1.size() != 0)
		{
			S2.push(S1.top());
			S1.pop();
		}
	}
	else // Transfer from S2 to S1
	{
		while (S2.size() != 0)
		{
			S1.push(S2.top());
			S2.pop();
		}
	}
}
void enqueue()
{
	int data;
	cin>>data;
	if ((S1.size() == 0) && sFlag && (S2.size() != 0)) //if all the elements are in S2
	{
		transfer(false);
		sFlag = false;
		S1.push(data);
	}
	else if (S1.size() == 0 && !sFlag)  // Queueu is empty
	{
		S1.push(data);
		head = data;
	}
	else if ((S1.size() != 0) && !sFlag) // Elements are in S1
	{
		S1.push(data);  
	}

}

void dequeue()
{
	if ((S1.size() == 0) && sFlag && (S2.size() != 0)) // All  elements are in S2, then just pop the top most and update head
	{
		S2.pop();
		if (S2.size() != 0)
			head = S2.top();
		else
		{ 
			head = -1; //Invalid
			sFlag = false;
		}
	}
	else if ((S1.size() != 0) && !sFlag) // elements are in S1, transfer to S2 and pop and update head
	{
		transfer(true); // transfer from S1 to S2
		S2.pop();
		if (S2.size() != 0)
			head = S2.top();
		else
		{
			head = -1; //Invalid
			sFlag = false;
			return;
		}
		sFlag = true;
	}
	else if (S1.size() == 0 && S2.size() == 0)
	{
		cout<<"Queue is empty\n";
	}
}

void  display()
{
	cout<<head<<endl;
}
