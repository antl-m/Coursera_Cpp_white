#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<bool> is_woried;
	int q;
	string cmd;
	cin >> q;
	int tmp;
	for (size_t k = 0; k < q; k++)
	{
		cin >> cmd;
		if (cmd == "WORRY")
		{
			cin >> tmp;
			is_woried[tmp] = true;
		}
		else if (cmd == "QUIET")
		{
			cin >> tmp;
			is_woried[tmp] = false;
		}
		else if (cmd == "COME")
		{
			cin >> tmp;
			is_woried.resize(is_woried.size() + tmp);
		}
		else if (cmd == "WORRY_COUNT")
		{
			int sum = 0;
			for (bool pers: is_woried)
			{
				if (pers)
					sum++;
			}
			cout << sum << endl;
		}
	}
	return 0;
}