#pragma once
#include<iostream>
#include<stdlib.h>
#include"LinearList.h"
using namespace std;

template<class T>
class SeqList: public LinearList<T>
{
public:
	SeqList()
	{
	}
	~SeqList()
	{
	}

	SeqList(int sz);

	 bool Insert(int i, T x);

	 bool Remove(int i, T& x);

	 void output();

	 void input();

	 virtual int Size();

	 virtual int Length();

	 //SeqList<T> merge(SeqList<T>s1, SeqList<T>s2);   //将两个线性表合并，并按升序排列

	 virtual void pushBack(T x);

	 virtual void pushFront(T x);


	 T* data;
private:
	
	int maxSize;
	int last;
	int RFACTOR = 2;
	void Resize(int newSize);



};