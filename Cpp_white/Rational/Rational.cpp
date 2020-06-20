#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Rational {
private:
	int num;
	int den;

	void Simpl() {
		if (den == 0)
			throw invalid_argument("Invalid argument");

		if (num == 0) {
			den = 1;
			return;
		}

		if (den < 0) {
			num *= -1;
			den *= -1;
		}
		int a = max(abs(num), abs(den));
		int b = min(abs(num), abs(den));
		while (a % b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		num /= b;
		den /= b;
	}

public:
	Rational() {
		num = 0;
		den = 1;
	}

	Rational(int numerator, int denominator) {
		num = numerator;
		den = denominator;
		Simpl();
	}

	int Numerator() const {
		return num;
	}

	int Denominator() const {
		return den;
	}

	friend istream& operator>> (istream& stream, Rational& rat);
};

bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	return { lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	return { lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	return { lhs.Numerator() * rhs.Numerator() , lhs.Denominator() * rhs.Denominator() };
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0)
		throw domain_error("Division by zero");
	return { lhs.Numerator() * rhs.Denominator() , lhs.Denominator() * rhs.Numerator() };
}

ostream& operator<< (ostream& stream, const Rational& num) {
	stream << num.Numerator() << '/' << num.Denominator();
	return stream;
}

istream& operator>> (istream& stream, Rational& rat) {
	stream >> rat.num;
	stream.ignore();
	stream >> rat.den;
	rat.Simpl();
	return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

int main() {
	try {
		Rational lhs, rhs, res;
		char operation;
		cin >> lhs >> operation >> rhs;
		switch (operation) {
		case '+':
			cout << lhs + rhs;
			break;
		case '-':
			cout << lhs - rhs;
			break;
		case '*':
			cout << lhs * rhs;
			break;
		case '/':
			cout << lhs / rhs;
			break;
		default:
			break;
		}
	}
	catch (const exception& e) {
		cout << e.what();
	}
	return 0;
}