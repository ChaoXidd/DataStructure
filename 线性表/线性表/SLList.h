#pragma once

#include"LinearList.h"
#include<iostream>
using namespace std;
template<class T>
struct LinkNode {
	T data;
	LinkNode<T>* link;
	LinkNode(const T& x, LinkNode<T>* ptr = NULL)
	{
		data = x;
		link = ptr;
	}
	LinkNode()
	{
		data = -1;
		link = NULL;
	}
};


template<class T>
class SLList:public LinearList<T>
{
public:
	SLList()
	{
		first = new LinkNode<T>();
		m_size = 0;
	}

	SLList(const T& x)
	{
		first = new LinkNode<T>(x);
	    m_size = 0;
	}
	~SLList()
	{

	}



	virtual int Size();

	virtual int Length();

	virtual void pushBack(T x);

	virtual void pushFront(T x);

	LinkNode<T>* Locate(int i);   //定位

	LinkNode<T>* Search(T x);  //搜索

	bool Insert(int i, T x);   //在第i项后插入

	bool Remove(int i, T& x);

	void output();


private:
	LinkNode<T>* first;
	int m_size;
};