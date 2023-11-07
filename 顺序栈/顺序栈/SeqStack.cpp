#include"SeqStack.h"
using namespace std;

template<class T>
SeqStack<T>::SeqStack()
{
	top = -1;
	elements = new T[maxSize];
}



template<class T>
SeqStack<T>::SeqStack(int sz)
{
	top = -1;
	maxSize = sz;
	elements = new T[maxSize];
}


template<class T>
SeqStack<T>::~SeqStack()
{
	delete []elements;
}



template<class T>
void SeqStack<T>::overflowProcess()
{
	T* temp = new T[maxSize + stackIncrement];
	for (int i = 0; i <= top; i++)
	{
		temp[i] = elements[i];
	}
	delete[]elements;
	elements = temp;
}


template<class T>
void SeqStack<T>::Push(T x)
{
	if (IsFull()) overflowProcess();
	elements[++top] = x;
}


template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if (IsEmpty()) return false;
	x = elements[top--];
	return true;
}


template<class T>
bool SeqStack<T>::getTop(T& x)
{
	if (IsEmpty()) return false;
	x = elements[top];
	return true;
}


template<class T>
void SeqStack<T>::output()
{
	for (int i = top; i >= 0; i--)
	{
		cout << elements[i] << " " ;
	}
	cout << endl;
}

int main()
{
	SeqStack<int> s = SeqStack<int>(50);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.output();
	int a;
	s.Pop(a);
	cout << a << endl;
	s.output();
}