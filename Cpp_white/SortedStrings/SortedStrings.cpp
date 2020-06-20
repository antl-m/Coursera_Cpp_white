#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:

	void AddString(const string& s) {
		list.push_back(s);
		sort(begin(list), end(list));
	}

	vector<string> GetSortedStrings() {
		return list;
	}
private:
	vector<string> list;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}