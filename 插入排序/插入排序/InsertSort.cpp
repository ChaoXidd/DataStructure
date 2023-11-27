#include<iostream>
using namespace std;


void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j > 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

}

void ShellSort(int a[], int n)
{
	int gap = n;
	do {
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int key = a[i];
			int j = i - gap;
			while (j > 0 && a[j] > key)
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = key;
		}
	} while (gap > 1);
}




int main()
{
	int a[] = { 0, 3, 4, 5, 8, 9 };
	ShellSort(a, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}


	return 0;
}