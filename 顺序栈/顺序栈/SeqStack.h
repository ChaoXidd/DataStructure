#pragma once
#include<iostream>


const int stackIncrement = 20;

template<class T>
class SeqStack {
private:
	T* elements;
	int top;
	int maxSize;
	void overflowProcess();
public:
	SeqStack();
	SeqStack(int sz = 50);
	~SeqStack();
	void Push(T x);
	bool Pop(T& x);
	bool getTop(T& x);
	bool IsEmpty()  { return (top == -1) ? true : false; }
	bool IsFull()  { return (top == maxSize - 1) ? true : false;}
	void output();
};