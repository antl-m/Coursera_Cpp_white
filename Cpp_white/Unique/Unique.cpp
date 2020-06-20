#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	set<string> list;
	for (size_t i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		list.insert(word);
	}
	cout << list.size() << endl;
	return 0;
}