#include <iostream>
#include <string>
using namespace std;

class ReversibleString : public string
{
public:
    ReversibleString(const char* str) :string(str) {};
    ReversibleString() :string() {};
    ReversibleString(string str) :string(str) {};

    void Reverse(){
        std::reverse(std::begin(*this), std::end(*this));
    }

    string ToString() const {
        return *this;
    }
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}