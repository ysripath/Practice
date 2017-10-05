#include <stdlib.h>


template <class T> class Node
{
	private:
		T data;
		Node* next;
	public:
		Node(T val):data(val), next(NULL){}
		~Node(){}
		T getData();
		Node* getNext();
};


template<class T> T Node<T>::getData()
{
	return data;
}


template<class T> Node<T>* Node<T>::getNext()
{
	return next;
}
