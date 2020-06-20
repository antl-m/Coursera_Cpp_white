#include <iostream>
using namespace std;

int Factorial(int num)
{
    int res = 1;
	for (int i = 2; i <= num; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	return 0;
}