#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> char_count(const string& word)
{
    map<char, int> res;
    for (const auto& ch : word)
    {
        res[ch]++;
    }
    return res;
}

bool is_anagr(const string& str1, const string& str2)
{
    return char_count(str1) == char_count(str2);
}

int main()
{
    int q;
    string str1, str2;
    cin >> q;
    for (size_t k = 0; k < q; k++)
    {
        cin >> str1 >> str2;
        if (is_anagr(str1, str2))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}