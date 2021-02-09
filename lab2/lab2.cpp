#include <iostream>
//laba 2
using namespace std;
void Polozhitelnie() {
    int n;
    cin >> n;
    while (n != 0) {
        if (n > 0)
            cout << n << " ";
        Polozhitelnie();
    }
    cout << endl;
};

void Chisla(int A[], int n) {
    

};

int main() {
    int n = 10;
    int A[] = { 1,-2,3,-4,5, -6,7,-8,9,-10 };
    Chisla(A, n);
}