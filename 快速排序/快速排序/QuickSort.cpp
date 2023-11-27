#include<iostream>
using namespace std;

void QuickSort(int arr[], int L, int R)
{
	if (L > R) return;
	int left = L;
	int right = R;
	int pivot = arr[left];

	while (left < right)
	{
		while (left < right && arr[right] >= pivot)
		{
			right--;
		}
		if (left < right)
		{
			arr[left] = arr[right];
			left++;
		}
		while (left < right && arr[left] <= pivot)
		{
			left++;
		}
		if (left < right)
		{
			arr[right] = arr[left];
			right--;
		}
		if (left == right)
		{
			arr[left] = pivot;
		}

	}
	
	QuickSort(arr, L, right - 1);
	QuickSort(arr, right + 1, R);

}



int main()
{
	int arr[] = { 9, 3, 8, 0, 1, 7 };
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	QuickSort(arr, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}