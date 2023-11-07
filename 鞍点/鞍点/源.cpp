#include<iostream>
using namespace std;


void f(int A[][5], int n, int m)
{
	int max = 0, min = 0, n1 = 0, m1 = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		min = A[i][0];
		for (int j = 0; j < m; j++)
		{
			
			if (A[i][j] <= min)
			{
				min = A[i][j];
				m1 = j;
			}
		}
		max = min;
		for (int k = 0; k < n; k++)
		{
			if (A[k][m1] >= max)
			{
				max = A[k][m1];
				n1 = k;
			}
		}
		if (max == min)
		{
			cout << " 行：" << n1 + 1 << " 列：" << m1 + 1 << endl;
		}
	}
}



int main()
{
	int A[5][5] = {
		-1,6,7,8,-9,
		-2,4,6,9,-7,
		1,2,4,6,0,
		-4,3,2,1,-6,
		-5,8,0,2,-3
	};

	f(A, 5, 5);
	return 0;
}