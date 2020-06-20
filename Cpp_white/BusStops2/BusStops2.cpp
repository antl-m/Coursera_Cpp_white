#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

int main()
{
	map<set<string>, int> num_of_bus;
	int q;
	cin >> q;
	for (size_t k = 0; k < q; k++)
	{
		int num;
		string stop;
		set<string> cur;
		cin >> num;
		for (size_t i = 0; i < num; i++)
		{
			cin >> stop;
			cur.insert(stop);
		}
		if (num_of_bus.count(cur) == 0)
		{
			int number = num_of_bus.size() + 1;
			num_of_bus[cur] = number;
			cout << "New bus ";
		}
		else
		{
			cout << "Already exists for ";
		}
		cout << num_of_bus[cur] << endl;
	}
	return 0;
}