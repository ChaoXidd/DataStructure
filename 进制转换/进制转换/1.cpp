#include<iostream>
#include<stack>
using namespace std;

string convertBase(int N, int B)
{
	string result;
	stack<char>s;
	const char digitMap[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (N == 0)
	{
		return "0";
	}
	while (N > 0)
	{	
		s.push(digitMap[N % B]);
		N /= B;
	}
	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}
	return result;
}








int main()
{
	cout << convertBase(12, 16);
	return 0;
}










