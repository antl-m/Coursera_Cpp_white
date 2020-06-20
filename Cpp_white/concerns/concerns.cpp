#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> days_in_month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int cur = 0;
	vector<vector<string>> list(days_in_month[cur]);
	int q;
	string cmd;
	cin >> q;
	for (size_t i = 0; i < q; i++)
	{
		cin >> cmd;
		if (cmd == "ADD")
		{
			int day;
			string str;
			cin >> day >> str;
			list[day - 1].push_back(str);
		}
		else if (cmd == "DUMP")
		{
			int day;
			cin >> day;
			cout << list[day - 1].size() << ' ';
			for (string& str : list[day-1])
			{
				cout << str << ' ';
			}
			cout << endl;
		}
		else if (cmd == "NEXT")
		{
			cur++;
			cur %= 12;
			int d = days_in_month[cur] - days_in_month[cur-1];
			if (d < 0)
			{
				for (size_t j = 0; j < abs(d); j++)
				{
					list[days_in_month[cur]-1].insert(end(list[days_in_month[cur] - 1]), begin(list[days_in_month[cur]+j]), end(list[days_in_month[cur] + j]));
				}
			}
			list.resize(days_in_month[cur]);
		}
	}
	return 0;
}