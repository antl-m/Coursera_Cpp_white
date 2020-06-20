#include <iostream>
#include <vector>
using namespace std;

class Incognizable
{
public:
    Incognizable() {};
    Incognizable(int) {};
    Incognizable(int,int) {};
    Incognizable(int,int,int) {};
    Incognizable(int,int,int,int) {};
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = { 0 };
    Incognizable d = { 0, 1 };
    return 0;
}