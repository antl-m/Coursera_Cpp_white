#include <iostream>
#include <vector>

using namespace std;

class FunctionPart {
private:
	char op;
	double val;
public:
	FunctionPart(char operation, double num) {
		op = operation;
		val = num;
	}

	void Invert() {
		switch (op) {
		case '+': op = '-'; break;
		case '-': op = '+'; break;
		case '*': op = '/'; break;
		case '/': op = '*'; break;
		default:break;
		}
	}

	void Apply(double& arg) const {
		switch (op) {
		case '+': arg += val; break;
		case '-': arg -= val; break;
		case '*': arg *= val; break;
		case '/': arg /= val; break;
		default:break;
		}
	}
};

class Function {
private:
	vector<FunctionPart> parts;
public:
	void AddPart(char operation, double num) {
		parts.push_back({ operation, num });
	}

	void Invert() {
		for (FunctionPart& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}

	double Apply(double arg) const {
		for (const FunctionPart& part : parts) {
			part.Apply(arg);
		}
		return arg;
	}
};

//struct Image {
//	double quality;
//	double freshness;
//	double rating;
//};

//struct Params {
//	double a;
//	double b;
//	double c;
//};

//Function MakeWeightFunction(const Params& params,
//	const Image& image) {
//	Function function;
//	function.AddPart('*', params.a);
//	function.AddPart('-', image.freshness * params.b);
//	function.AddPart('+', image.rating * params.c);
//	return function;
//}

//double ComputeImageWeight(const Params& params, const Image& image) {
//	Function function = MakeWeightFunction(params, image);
//	return function.Apply(image.quality);
//}

//double ComputeQualityByWeight(const Params& params,
//	const Image& image,
//	double weight) {
//	Function function = MakeWeightFunction(params, image);
//	function.Invert();
//	return function.Apply(weight);
//}

int main() {
	//Image image = { 10, 2, 6 };
	//Params params = { 4, 2, 6 };
	//cout << ComputeImageWeight(params, image) << endl;
	//cout << ComputeQualityByWeight(params, image, 52) << endl;
	return 0;
}
