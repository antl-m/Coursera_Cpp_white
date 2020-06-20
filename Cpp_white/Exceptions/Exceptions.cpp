#include <iostream>
#include <exception>
#include <string>
using namespace std;

void EnsureEqual(const string& left, const string& right) {
    if (left != right)
        throw runtime_error(left + " != " + right);
}


string AskTimeServer() {
    throw exception();
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string res{ AskTimeServer() };
            last_fetched_time = res;
            return res;
        }
        catch (const system_error& e) {
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}