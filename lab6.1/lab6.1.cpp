#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Triangle(int a, int b, int c, int *P, double *S) {
	if (((a + b < c) || (a + c < b) || (b + c < a)) == 1) {
		cout << "Triangle dont exist" << endl;
		return 1;
		
	}
	*P = a + b + c;
	*S = sqrt((*P / 2) * ((*P / 2) - a) * ((*P / 2) - b) * ((*P / 2) - c));
	return 0;
}

int main() {
	int P = 0; double S = 0;
	cout << Triangle(2, 2, 2, &P, &S) << endl;
	cout << P << " " << S;
	return 0;
}