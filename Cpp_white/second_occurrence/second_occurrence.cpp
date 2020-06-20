#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	bool is = false;
	bool one = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == 'f')
		{
			if (!is)
			{
				is = true;
				one = true;
			}
			else
			{
				cout << i;
				one = false;
				break;
			}
		}
	}

	if (is && one)
		cout << -1;
	else if (!is)
		cout << -2;
	return 0;
}