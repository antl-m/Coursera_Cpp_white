#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string str)
{
	for (size_t i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
			return false;
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLenght)
{
	vector <string> res;
	for (auto word: words)
	{
		if (word.size() >= minLenght && IsPalindrom(word))
			res.push_back(word);
	}
	return res;
}

int main()
{
	vector<string> aaa = PalindromFilter({ "asdfdsa","asdsdsa","asdsdsw","asa","assa","asda" }, 4);
	for (auto str : aaa)
	{
		cout << str << endl;
	}
	return 0;
}