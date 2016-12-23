#include <iostream>

using namespace std;


class Stack
{
private:
	int* pArr;
	int pTop;
	int pStackSize;
public:
	Stack(int n);
	~Stack();
	void push(int n);
	int pop();
	void peek();
};

int main()
{
	cout<<"Enter the size of stack required\n";
	int n;
	cin>>n;
	Stack S(n);
	int choice;
	bool flag = true;
	while(flag)
	{
		cout<<"Enter operation to perform \n 1. Push \t 2. Pop \t 3. Peek 4. Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1: {
					cout<<"Enter the integer value to be pushed\n"; int temp; cin>>temp; S.push(temp);
					break;
				}
			case 2: {
					int temp = S.pop(); cout<<"Popped element is "<<temp<<endl;
					break;
				}
			case 3: {
					S.peek(); break;
				}
			default: {
					flag = false; break;					
				 }
		}
	}
	return 0;
}

Stack::Stack(int n)
{
	cout<<"Constructor called\n";
	pArr = new int[n];
	pTop = -1;
	pStackSize = n -1;
}

Stack::~Stack()
{
	cout<<"Destructor called\n";
	delete[] pArr;

}

void Stack::push(int n)
{
	if (pTop == pStackSize)
	{
		cout<<"Stack size limit reached\n"; // TOD - Resize stack
		return;
	}
	pTop++;
	pArr[pTop] = n;
	cout<<n<<" was successfully pushed on to stack\n";
	return;
}


int Stack::pop()
{
	if (pTop == -1)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	int temp = pArr[pTop];
	pArr[pTop--] = 0;
	cout<<"Pop operation successful - "<<temp<<endl;
	return temp;
}	

void Stack::peek()
{
	if (pTop == -1)
	{
		cout<<"Stack is empty\n";
		return;
	}
	cout<<"Element at the top of stack is "<<pArr[pTop]<<endl;
	return;
}

