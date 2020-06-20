#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

void PrintFile(const string& path) {
	ifstream fin(path);
	if (fin) {
		string line;
		while (getline(fin, line)) {
			cout << line << endl;
		}
	}
	fin.close();
}

void PrintFileNums(const string& path) {
	ifstream fin(path);
	if (fin) {
		double num;
		cout << fixed << setprecision(3);
		while (fin >> num) {
			cout << num << endl;
		}
	}
	fin.close();
}

void PrintFileTable(const string& path) {
	ifstream fin(path);
	if (fin) {
		int N{}, M{}, num;
		fin >> N >> M;
		cout << setfill(' ');
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				fin >> num;
				fin.ignore();
				cout << setw(10) << num << (j == M - 1 ? "" : " ");
			}
			cout << (i == N - 1 ? "" : "\n");
		}
	}
	fin.close();
}

void CopyFile(const string& from, const string& to) {
	ifstream fin(from);
	ofstream fout(to);
	if (fin) {
		string line;
		while (getline(fin, line)) {
			fout << line << (fin.eof() ? "" : "\n");
		}
	}
	fin.close();
	fout.close();
}

struct student
{
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main()
{
	int N;
	cin >> N;
	vector<student> list(N + 1);
	for (size_t i = 1; i < N + 1; i++) {
		string name, surname;
		int day, month, year;
		cin >> name >> surname >> day >> month >> year;
		list[i] = { name, surname, day, month, year };
	}
	int M;
	cin >> M;
	for (size_t i = 0; i < M; i++) {
		string cmd;
		int ind;
		cin >> cmd >> ind;
		if (cmd == "name" && (ind >= 1 && ind <= N))
			cout << list[ind].name << ' ' << list[ind].surname << endl;
		else if (cmd == "date" && (ind >= 1 && ind <= N))
			cout << list[ind].day << '.' << list[ind].month << '.' << list[ind].year << endl;
		else
			cout << "bad request" << endl;
	}
	return 0;
}