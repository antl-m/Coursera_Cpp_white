#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string* A = new string[N];
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(&A[0], &A[N], [](string a, string b)
		{
			for (size_t i = 0; i < min(a.size(), b.size()); i++)
			{
				if (tolower(a[i]) != tolower(b[i]))
					return tolower(a[i]) < tolower(b[i]);
			}
			return false;
		});
	for (size_t i = 0; i < N; i++)
	{
		cout << A[i] << ' ';
	}
	return 0;
}