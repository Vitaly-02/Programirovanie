#include <iostream>
//laba 1
using namespace std;

double Stepen(double x, int n) {
	double step = x;
	for (int i = 1; i < n; i++) {
		step *= x;
	}
	return step;
};

long double Factorial(long double y) {
	if (y < 0)
		return 0;
	if (y == 0)
		return 1;
	else 
		return y * Factorial(y - 1);
};

double Cosinus(double x) {
	double cos = 1, eps = 0.0001;
	int n = 1;
	while ((Stepen(x, n * 2) / Factorial(n * 2)) >= eps) {
		cos = cos + (Stepen(-1, n) * Stepen(x, n*2) / Factorial(n*2));
		n++; 
	}
	
	return cos;
};

int main() {
	cout << Cosinus(4) << endl;
}