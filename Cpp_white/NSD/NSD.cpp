#include <iostream>
using namespace std;

int nsd(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
		return a+b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << nsd(a, b);
	return 0;
}