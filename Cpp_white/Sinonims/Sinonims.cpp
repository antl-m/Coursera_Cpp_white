#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
	int q;
	cin >> q;
	map<string, set<string>> syns_of_word;
	for (size_t k = 0; k < q; k++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			syns_of_word[word1].insert(word2);
			syns_of_word[word2].insert(word1);
		}
		else if (cmd == "COUNT")
		{
			string word;
			cin >> word;
			cout << syns_of_word[word].size() << endl;
		}
		else if (cmd == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;
			if (syns_of_word[word1].count(word2) == 0 && syns_of_word[word2].count(word1) == 0)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}