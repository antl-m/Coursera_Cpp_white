#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <exception>
#include <iomanip>

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() : year{ 0 }, month{ 0 }, day{ 0 } {}
	Date(int year, int month, int day) {
		this->year = year;
		if (month < 1 || month > 12)
			throw logic_error("Month value is invalid: " + to_string(month));
		this->month = month;
		if (day < 1 || day > 31)
			throw logic_error("Day value is invalid: " + to_string(day));
		this->day = day;
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

istream& operator>>(istream& in, Date& dat) {
	string format;
	in >> format;
	stringstream ss(format);
	int year, month, day;
	ss >> year;
	if (ss.peek() == '-') {
		ss.ignore();
	}
	else {
		throw logic_error("Wrong date format: " + format);
	}
	if (ss.eof())
		throw logic_error("Wrong date format: " + format);
	ss >> month;
	if (ss.peek() == '-') {
		ss.ignore();
	}
	else {
		throw logic_error("Wrong date format: " + format);
	}
	if (ss.peek()==EOF)
		throw logic_error("Wrong date format: " + format);
	ss >> day;
	if (!ss.eof())
		throw logic_error("Wrong date format: " + format);
	dat = { year, month, day };
	return in;
}

ostream& operator<<(ostream& out, const Date& dat) {
	out << setfill('0')
		<< setw(4) << dat.GetYear() << '-'
		<< setw(2) << dat.GetMonth() << '-'
		<< setw(2) << dat.GetDay();
	return out;
}

class Database {
	map<Date, set<string>> db;
public:
	void AddEvent(const Date& date, const string& event) {
		db[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (db.count(date) > 0) {
			if (db[date].count(event) > 0) {
				db[date].erase(event);
				return true;
			}
		}
		return false;
	}

	int  DeleteDate(const Date& date) {
		int N = 0;
		if (db.count(date) > 0) {
			N = db[date].size();
			db.erase(date);
		}
		return N;
	}

	void Find(const Date& date) const {
		try {
			for (const string& it : db.at(date)) {
				cout << it << endl;
			}
		}
		catch (...) {}
	}

	void Print() const {
		for (const auto& dat : db) {
			for (const string& evt : dat.second) {
				cout << dat.first << ' ' << evt << endl;
			}
		}
	}

	void CommandParse(const string& command) {
		if (command == "")
			return;
		stringstream ss(command);
		string cur;
		ss >> cur;
		if (cur == "Add") {
			Date addin;
			ss >> addin;
			ss >> cur;
			AddEvent(addin, cur);
		}
		else if (cur == "Del") {
			Date dat;
			ss >> dat;
			if (ss.eof())
				cout << "Deleted " << DeleteDate(dat) << " events" << endl;
			else {
				ss >> cur;
				if (DeleteEvent(dat, cur))
					cout << "Deleted successfully" << endl;
				else
					cout << "Event not found" << endl;
			}
		}
		else if (cur == "Find") {
			Date dat;
			ss >> dat;
			Find(dat);
		}
		else if (cur == "Print") {
			Print();
		}
		else {
			throw logic_error("Unknown command: " + cur);
		}
	}
};



int main() {
	Database db;
	string command;
	try {
		while (getline(cin, command)) {
			db.CommandParse(command);
		}
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}