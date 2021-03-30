#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

long int Fact(int a) {
	int temp = a;
	long int F = 1;
	while (temp != 1) {
		F = F * temp;
		temp -= 1;
	}
	return F;
}

int Cnm(int n, int m) {
	int c;
	c = Fact(n) / (Fact(m) * Fact(n - m));
	return c;
}

int Func(int n, int m, double &pd, double& pm) {
	if ((n <= m) == 1) {
		cout << "error" << endl;
		return 1;
	}
	double p = 0.45;
	double q = 1 - p;
	pd = Cnm(n, m) * pow(p, m) * pow(q, n-m);
	pm = Cnm(n, m) * pow(q, m) * pow(p, n - m);
	return 0;
}

int main() {
	double M = 0; double D = 0;
	int n, m;
	cout << "Input n m " << endl;
	cin >> n >> m;
	Func(n, m, D, M);
	cout << "Boys " << M << endl << "Girls " << D << endl;
	return 0;
}