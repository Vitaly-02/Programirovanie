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

void Chisla(int Mas[], int size, int num) {
    if (num >= size) {
        return; 
    }
    if (Mas[num] < 0) {
        cout << Mas[num] << endl;
    }
    num += 1;
    
    Chisla(Mas, size, num);
    if (Mas[size-num] > 0)
    cout << Mas[size-num] << endl;
};

long long int Convert_10to2(long long int number) {
    if (number < 2) {
        return number;
    }
    return 10*Convert_10to2(number / 2) + (number % 2);
}


int main() {
    int n = 10;
    int A[] = { 1,-2,3,-4,5, -6,7,-8,9,-10 };
    Chisla(A, n, 0); 
    cout << endl;
    cout << Convert_10to2(4096);
}