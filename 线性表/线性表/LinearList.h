#pragma once

template<class T>
class LinearList
{
public:
	virtual int Size() = 0;
	virtual int Length() = 0;
	virtual void pushBack(T x) = 0;
	virtual void pushFront(T x) = 0;
};
