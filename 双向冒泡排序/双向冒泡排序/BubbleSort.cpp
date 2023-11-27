#include<iostream>
#include<algorithm>


using namespace std;



void BubbleSort(int arr[], int len)
{
	int low = 0;
	int high = len - 1;
	bool flag = false;
	while (low < high)
	{
		flag = false;

		for (int i = low; i < high; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = true;
			}
		
		}
		
		if (!flag) break;

		high--;

		for (int j = high; j > low; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr[j - 1], arr[j]);

			}
		}

		low++;

	}




}int main()
{
	int arr[] = { 3, 4, 5, 1, 2 };
	BubbleSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i];
	}
	return 0;
}