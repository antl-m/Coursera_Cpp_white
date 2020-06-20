#include <iostream>
#include <string>

using namespace std;

struct Specialization {
	string str;
	explicit Specialization(string str) :str{ str } {};
};

struct Course {
	string str;
	explicit Course(string str) :str{ str } {};
};

struct Week {
	string str;
	explicit Week(string str) :str{ str } {};
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.str;
		course = c.str;
		week = w.str;
	}
};

int main()
{
	LectureTitle title1 = { Specialization("C++"), Course("White belt"), Week("4th") };
	return 0;
}