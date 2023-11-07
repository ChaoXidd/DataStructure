#include<iostream>
using namespace std;

int max(int A[], int n)
{
	if (n == 1)
	{
		return A[0];
    }
	else
	{
		int t = max(A, n - 1);
		return (t >= A[n - 1]) ? t : A[n - 1];
	}
}



int sum(int A[], int n)
{
	if (n == 1)
	{
		return A[0];
	}
	else
	{
		int s = sum(A, n - 1);
		return s + A[n - 1];
	}
}





double average(int A[], int n, int a)
{
	if (n == 1)
	{
		return (double)A[0] / a;
	}
	else
	{
		double s = average(A, n - 1, a);
		return s + (double)A[n - 1] / a;
	}
	
}








int main()
{
	int a[] = {1,101,3,4};
	cout <<average(a, 4,4);
	return 0;
}