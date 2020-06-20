#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int q;
	cin >> q;
	string cmd;
	map<string, string> capital_of;

	for (size_t j = 0; j < q; j++)
	{
		cin >> cmd;
		if (cmd == "CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;
			string old_capital = capital_of[country];

			if (old_capital == "")
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			else if (old_capital == new_capital)
				cout << "Country " << country << " hasn't changed its capital" << endl;
			else
				cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;

			capital_of[country] = new_capital;
		}
		else if (cmd == "RENAME")
		{
			string old_country, new_country;
			cin >> old_country >> new_country;
			if (capital_of.count(old_country) == 0 || capital_of.count(new_country) != 0 || old_country == new_country)
				cout << "Incorrect rename, skip" << endl;
			else {
				cout << "Country " << old_country << " with capital " << capital_of[old_country] << " has been renamed to " << new_country << endl;
				capital_of[new_country] = capital_of[old_country];
				capital_of.erase(old_country);
			}
		}
		else if (cmd == "ABOUT")
		{
			string country;
			cin >> country;
			if (capital_of.count(country) == 0)
				cout << "Country " << country << " doesn't exist" << endl;
			else
				cout << "Country " << country << " has capital " << capital_of[country] << endl;
		}
		else if (cmd == "DUMP")
		{
			if (capital_of.size() == 0)
				cout << "There are no countries in the world" << endl;
			else
			{
				for (const auto& item : capital_of)
				{
					cout << item.first << '/' << item.second<<' ';
				}
				cout << endl;
			}
		}
	}
	return 0;
}