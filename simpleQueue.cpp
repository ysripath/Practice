#include <iostream>

using namespace std;

class Queue
{
	private:
		int pFront;
		int pEnd;
		int* pArr;
		int pQueueSize;

	public:
		Queue(int n);
		~Queue();
		void push(int n);
		void pop();
		void peek();			
};


int main()
{
	cout<<"Enter the size of Queue\n";
	int n;
	cin>>n;
	Queue q(n);
	bool flag = true;
	int choice;
	while(flag)
	{
		cout<<"Enter operation to perform \n 1. Push \t 2. Pop \t 3. Peek 4. Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1: {
					cout<<"Enter the integer value to be pushed\n"; int temp; cin>>temp; q.push(temp);
					break;
				}
			case 2: {
					q.pop();
					break;
				}
			case 3: {
					q.peek(); break;
				}
			default: {
					flag = false; break;					
				 }
		}
	}
	return 0;
}

Queue::Queue(int n)
{
	pArr = new int[n];
	pFront = -1;
	pEnd = -1;
	pQueueSize = n -1;
}
Queue::~Queue()
{
	delete[] pArr;
}

void Queue::push(int n)
{
	if (pEnd == pQueueSize)
	{
		cout<<"Queue size limit reached\n";
		return;
	}
	pArr[++pEnd] = n;
	if (pFront == -1)
		pFront++;
	return;
}

void Queue::pop()
{
	if (pFront > pEnd || pEnd == -1 )
	{
		cout<<"Queue is empty\n";
		return;
	}
	cout<<"Popped element is - "<<pArr[pFront]<<endl;
	pArr[pFront] = 0;
	pFront++;
}


void Queue::peek()
{
	if (pFront > pEnd || pEnd == -1 )
        {
                cout<<"Queue is empty\n";
                return;
        }
	cout<<"Element at the front of the Queue is - "<<pArr[pFront]<<endl;
	return;
}
