#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string res = "";
	while (n > 0)
	{
		res = char((n % 2)+'0')+res;
		n /= 2;
	}
	cout << res << endl;
	return 0;
}