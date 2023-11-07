#include"SeqList.h"

template<class T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == NULL)
		{
			cerr << "内存分配错误！" << endl;
			exit(1);
		}
	}
}

template<class T>
bool SeqList<T>::Insert(int i, T x)    //第i项后插入
{
	if (last == maxSize - 1) return false;
	if (i < 0 || i >last + 1) return false;
	for (int j = last; j >= i; j--)
	{
		data[j + 1] = data[j];
	}
	data[i] = x;
	last++;
	return true;
}

template<class T>
bool SeqList<T>::Remove(int i, T& x)
{
	if (last == -1) return false;
	if (i < 1||i > last + 1) return false;
	x = data[i - 1];
	for (int j = i; i <= last; j++)
	{
		data[j - 1] = data[j];
	}
	last--;
	return true;
}
template<class T>
void SeqList<T>::output()
{
	for (int i = 0; i <= last; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
template<class T>
int SeqList<T>::Size()
{
	return maxSize;
}
template<class T>
int SeqList<T>::Length()
{
	return last + 1;
}
template<class T>
void SeqList<T>::Resize(int nz)
{





}

template<class T>
void SeqList<T>::pushBack(T x)
{
	Insert(last + 1, x);
}


template<class T>
void SeqList<T>::pushFront(T x)
{
	Insert(0, x);
}

template<class T>
void SeqList<T>::input()
{
	int i;
	while (cin>>i)
	{
		pushBack(i);
	}
}


//void merge(SeqList<int>&s,SeqList<int>&s1, SeqList<int>&s2)
//{
//	int* A = s1.data; int* B = s2.data;
//	int p1 = 0;
//	int p2 = 0;
//	
//	while (p1 < s1.Length() && p2 < s2.Length())
//	{
//		if (A[p1] < B[p2])
//		{
//			s.pushBack(A[p1]);
//			
//			p1++;
//		}
//		else 
//		{
//			s.pushBack(B[p2]);
//		
//			p2++;
//		}
//	}
//	while (p1 < s1.Length())
//	{
//		s.pushBack(A[p1]);
//		
//		p1++;
//	}
//	while (p2 < s2.Length())
//	{
//		s.pushBack(B[p2]);
//		
//		p2++;
//	}
//	
//}



void test()
{
	SeqList<int> s = SeqList<int>(5);
	s.input();
	s.output();
}
	

int main()
{
	test();
}