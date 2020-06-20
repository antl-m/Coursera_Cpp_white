#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "abcde";
	cout << strchr(str.c_str(), 'r')<<endl;
	cout << strchr(str.c_str(), 'c') - str.c_str()<<endl;
	cout <<  int(str.c_str())<<endl;
	cout << int(strchr(str.c_str(), 'c'))<<endl;
	
	return 0;
	int a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}
