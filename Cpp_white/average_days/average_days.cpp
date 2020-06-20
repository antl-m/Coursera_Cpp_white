#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int size;
	cin >> size;
	vector<int> list(size);
	int avrg=0;
	for (size_t i = 0; i < list.size(); i++)
	{
		cin >> list[i];
		avrg += list[i];
	}
	avrg /= list.size();
	vector<int> inds;
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] > avrg)
			inds.push_back(i);
	}
	cout << inds.size() << endl;
	for (int& a : inds)
	{
		cout << a << ' ';
	}
	return 0;
}