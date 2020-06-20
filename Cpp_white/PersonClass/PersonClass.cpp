#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Person {
public:

	Person(const string& name, const string& surname, int year)
	{
		year_to_name[year].first = name;
		year_to_name[year].second = surname;
		birth = year;
	};

	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		if (year < birth)
			return;
		year_to_name[year].first = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		if (year < birth)
			return;
		year_to_name[year].second = last_name;
	}

	string GetFullName(int year) const {
		// получить имя и фамилию по состоянию на конец года year
		if (year < birth)
			return "No person";

		string name, surname;

		for (const auto& item : year_to_name) {
			if (item.first > year)
				break;
			else {
				if (item.second.first != "")
					name = item.second.first;
				if (item.second.second != "")
					surname = item.second.second;
			}
		}

		if (name == "" && surname != "")
			return surname + " with unknown first name";
		if (surname == "" && name != "")
			return name + " with unknown last name";
		if (name == "" && surname == "")
			return "Incognito";

		return name + " " + surname;
	}

	string GetFullNameWithHistory(int year) const {
		// получить все имена и фамилии по состоянию на конец года year
		if (year < birth)
			return "No person";

		vector<string> names, surnames;
		int n = 0, s = 0;
		for (auto it = year_to_name.rbegin(); it != year_to_name.rend(); it++) {
			if (it->first <= year) {
				if (it->second.first != "") {
					if (n == 0 || it->second.first != names[n - 1]) {
						names.push_back(it->second.first);
						n++;
					}
				}
				if (it->second.second != "") {
					if (s == 0 || it->second.second != surnames[s - 1]) {
						surnames.push_back(it->second.second);
						s++;
					}
				}
			}
		}
		string res_names, res_sur;
		if (names.size() > 0) {
			res_names = names[0];
			if (names.size() > 1) {
				res_names += " (";
				bool first = true;
				for (const string& nam : names) {
					if (!first)
						res_names += nam + (nam == names.back() ? "" : ", ");
					first = false;
				}
				res_names += ")";
			}
		}
		if (surnames.size() > 0) {
			res_sur = surnames[0];
			if (surnames.size() > 1) {
				res_sur += " (";
				bool first = true;
				for (const string& sur : surnames) {
					if (!first)
						res_sur += sur + (sur == surnames.back() ? "" : ", ");
					first = false;
				}
				res_sur += ")";
			}
		}

		if (res_names == "" && res_sur != "")
			return res_sur + " with unknown first name";
		if (res_sur == "" && res_names != "")
			return res_names + " with unknown last name";
		if (res_names == "" && res_sur == "")
			return "Incognito";


		return res_names + " " + res_sur;
	}

private:
	map<int, pair<string, string>> year_to_name;
	int birth;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}