#include<iostream>
using namespace std;
int * temp = new int[100];


void Merge(int a[], int left, int right, int  *temp)
{
	int i = left;
	int mid = (left + right) / 2;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}

		else
		{
			temp[k++] = a[j++];
		}
	}
	

	while (i <= mid)
	{
	 temp[k++] = a[i++];
	}


	while (j <= right)
	{
	 temp[k++] = a[j++];
	}
  
	while (left <= right)
	{
		a[left] = temp[left];
		left++;
	}



}


void MergeSort(int a[], int left, int right)
{
	if (left < right) 
	{
		MergeSort(a, left, (left + right) / 2);
		MergeSort(a, (left + right) / 2 + 1, right);
		Merge(a, left, right, temp);
	}
}






int main()
{
	int a[] = { 2,5,1,6,7, -9, 10 };
	MergeSort(a, 0, 6);
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}

