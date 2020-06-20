#include <iostream>
#include<vector>
#include<string>
using namespace std;

void UpdateIfGreater(int first, int& second)
{
    if (first > second)
        second = first;
}

void MoveStrings(vector<string>& source, vector<string>& destination)
{
    for (size_t i = 0; i < source.size(); i++)
    {
        destination.push_back(source[i]);
    }
    source.clear();
}

void Reverse(vector<int>& v)
{
    for (size_t i = 0; i < v.size()/2; i++)
    {
        swap(v[i], v[v.size() - i - 1]);
    }
}

vector<int> Reversed(const vector<int>& v)
{
    vector<int> res;
    for (int i = v.size()-1; i >= 0; i--)
    {
        res.push_back(v[i]);
    }
    return res;
}

int main()
{
    int a, b;
    while (true)
    {
        cin >> a >> b;
        UpdateIfGreater(a, b);
        cout << a << ' ' << b << endl;
    }
    return 0;
}