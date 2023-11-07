#include<iostream>
using namespace std;
int parent[1024];
inline void init(int n)
{
	for (int i = 0; i < n; i ++)
	{
		parent[i] = -1;
	}
}
int find(int p)
{
	if (parent[p] < 0)
	{
		return p;
	}
	else
	{
		parent[p] = find(parent[p]);
		return parent[p];
	}
}
inline void merge(int p, int q)
{
	int rp = find(p);
	int rq = find(q);
	if (parent[rp] < parent[rq])
	{
		parent[rp] += parent[rq];
		parent[rq] = rp;
	}
	else 
	{
		parent[rq] += parent[rp];
		parent[rp] = rq;
	}
}

bool isConnected(int p, int q)
{
	return find(p) == find(q);
}



int main() {
	init(5);
	merge(0, 1);
	merge(1, 2);
	//cout << isConnected(0, 2) << endl;
	cout << parent[1] << endl;

}