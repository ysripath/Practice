#include <stdlib.h>
#include "ll.h"
#include <iostream>
using namespace std;

template<class T> class Q
{
	private:
		T rear;
		T front;
	public:
		Q():front(NULL), rear(NULL){}
		~Q(){}
		void insert(T val);
		void remove();
};


template<class T> void Q<T>::insert(T val)
{
	if (front == NULL)
	{
		// Use Try-catch
		rear = new Node<T>(val);
		front = rear;	
	}
	else
	{
		rear->next = new Node<T>(val);
		rear = rear->next;
	}
}


template<class T> void Q<T>:: remove()
{
	if (front != NULL)
	{
		T temp = front;
		front = front->next;
		cout<<"remove "<<temp->data<<endl;
		delete temp;
	}
	else
	{
		cout<<"Empty Q\n";
	}
}
