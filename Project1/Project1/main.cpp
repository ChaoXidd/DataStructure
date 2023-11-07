#include<iostream>
using namespace std;
void f(int a[], int n)
{

    int counts[5] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0 && a[i] <= 20)
        {
            counts[0]++;
        }
        else if (a[i] >= 21 && a[i] <= 50)
        {
            counts[1]++;
        }
        else if (a[i] >= 51 && a[i] <= 80)
        {
            counts[2]++;
        }
        else if (a[i] >= 81 && a[i] <= 130)
        {
            counts[3]++;
        }
        else if (a[i] >= 131 && a[i] <= 200)
        {
            counts[4]++;
        }
    }
    cout << "[0,20]: " << counts[0] << endl;
    cout << "[21,50]: " << counts[1] << endl;
    cout << "[51,80]: " << counts[2] << endl;
    cout << "[81,130]: " << counts[3] << endl;
    cout << "[131,200]: " << counts[4] << endl;

}

int main()
{
    int a[] = {1,2,200,150,50};
    f(a, 5);
    return 0;
}