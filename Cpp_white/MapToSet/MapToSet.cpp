#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> res;
	for(const auto& pair: m)
	{
		res.insert(pair.second);
	}
	return res;
}

/*
int main()
{
    std::cout << "Hello World!\n";
}
*/