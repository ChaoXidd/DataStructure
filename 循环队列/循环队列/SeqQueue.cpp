#include"SeqQueue.h"


template<class T>
SeqQueue<T>::SeqQueue()
{
	front = rear = 0;
}

template<class T>
SeqQueue<T>::SeqQueue(int sz )
{
	front = rear = 0;
	maxSize = sz;
	elements = new T[maxSize];
}


template<class T>
SeqQueue<T>::~SeqQueue()
{
	delete[]elements;
}


template<class T>
void SeqQueue<T>::MakeEmpty()
{
	front = rear = 0;
}


template<class T>
bool SeqQueue<T>::IsEmpty() const
{
	return front == rear;
}


template<class T>
bool SeqQueue<T>::IsFull() const
{ 
	return (rear + 1) % maxSize == front;
}


template<class T>
int SeqQueue<T>::GetSize() const
{ 
	return rear - front + 1;
}


template<class T>
bool SeqQueue<T>::EnQueue(const T& x)
{
	if (IsFull()) return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}


template<class T>
bool SeqQueue<T>::DeQueue(T& x)
{
	if (IsEmpty()) return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}


template<class T>
bool SeqQueue<T>::GetFront(T& x)
{
	if (IsEmpty()) return false;
	x = elements[front];
	return true;
}



int main()
{
	SeqQueue<int> sq = SeqQueue<int>(10);
	sq.EnQueue(1);
	sq.EnQueue(2);
	sq.EnQueue(4);
	while (!sq.IsEmpty())
	{
		int a;
		sq.GetFront(a);
		cout << a << " ";
		sq.DeQueue(a);
	}
	cout << endl;
	sq.EnQueue(6);
	sq.EnQueue(8);
	while (!sq.IsEmpty())
	{
		int b;
		sq.GetFront(b);
		cout << b << " ";
		sq.DeQueue(b);
	}
}