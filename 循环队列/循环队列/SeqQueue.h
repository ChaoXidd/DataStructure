#pragma once
#include<iostream>
using namespace std;

template<class T>
class SeqQueue {
private:
	int rear;
	int front;
	T* elements;
	int maxSize;
public:
	SeqQueue(int sz = 10);
	SeqQueue();
	~SeqQueue();
	bool EnQueue(const T & x);
	bool DeQueue(T& x);
	bool GetFront(T& x);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull()const;
	int GetSize()const;
};

