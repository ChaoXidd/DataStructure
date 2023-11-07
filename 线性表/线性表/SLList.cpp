#include"SLList.h"

template<class T>
int SLList<T>::Size()
{
	return m_size;
}


template<class T>
int SLList<T>::Length()
{
	return m_size;
}

template<class T>
LinkNode<T>* SLList<T>::Locate(int i)
{
	if (i <  0) return NULL;
	LinkNode<T>* p = first;
	int k = 0;
	while (p != NULL && k < i)
	{
		p = p->link;
		k++;
	}
	return p;
}

template<class T>
LinkNode<T>* SLList<T>::Search(T x)
{
	LinkNode<T>* p = first->link;
	while (p->data != x && p != NULL)
	{
		p = p->link;
	}
	return p;
}

template<class T>
bool SLList<T>::Insert(int i, T x)
{
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return false;
	LinkNode<T>* newNode = new LinkNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "内存分配错误" << endl;
		exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	m_size++;
	return true;
}

template<class T>
bool SLList<T>::Remove(int i, T& x)
{
	LinkNode<T>* current = Locate(i - 1);
	if (current == NULL || current->link == NULL) return false;
	LinkNode<T>* del = current->link;
	x = del->data;
	current->link = del->link;
	delete del;
	m_size--;
	return true;
}

template<class T>
void SLList<T>::output()
{
	LinkNode<T>* p = first->link;
	while (p->link != NULL)
	{
		cout << p->data << " -> ";
		p = p->link;
	}
	cout << p->data;
	cout << endl;
}


template<class T>
void SLList<T>::pushBack(T x)
{
	Insert(m_size, x);
}

template<class T>
void SLList<T>::pushFront(T x)
{
	Insert(0, x);
}



//void test2()
//{
//	SLList<int> l = SLList<int>();
//	l.pushBack(1);
//	l.pushBack(0);
//	l.pushBack(3);
//	l.pushBack(0);
//	l.pushBack(1);
//	l.pushBack(4);
//	l.output();
//	int x;
//	l.Remove(3,x);
//	l.output();
//}
//
//int main()
//{
//	test2();
//}