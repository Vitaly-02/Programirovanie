#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int random(int N) {
    return rand() % N;
}

void RandomMas(int* P, int size, int a, int b) {
    for (int i = 0; i < size; i++) {
        P[i] = random(b - a + 1) + a;
    }
}


int main() {
    srand(time(NULL));
    int size;
    int* Mas;
    cin >> size;
    Mas = new int[size];
    if (Mas == NULL) {
        printf("Error pizdec");
        return 1;
    }
    RandomMas(Mas, size, -10, 10);
    for (int i = 0; i < size; i++) {
        cout << Mas[i] << " ";
    }
    cout << endl;
    int k;
    cin >> k;
    if (k >= size) {
        cout << "error k>=m";
        return 1;
    }
    int str;
    if ((size % k) == 0) {
        str = (size / k) - 1;
    }
    else {
        str = size / k;
    }
    
    int** B;
    B = new int* [k];
    for (int i = 0; i <= str; i++) {
        B[i] = new int[k];
    }
    if (B == NULL) {
        printf("Error pizdec");
        return 1;
    }
    int m = 0, j = 0;
    for (int i = 0; i <= str; i++) {
        for (j = 0; j < k; j++) {
            if (m >= size) {
                B[i][j] = 0;
            }
            else {
                B[i][j] = Mas[m];
            }
            m++;
        }
    }
// cout << endl << m << endl << str << endl;
    cout << endl;
    while (m % k != 0) {
        B[str - 1][j] = 0;
        m++;
        j++;
    }


    for (int i = 0; i <= str; i++) {
        for (int j = 0; j < k; j++) {
            cout << B[i][j] << " ";
            if (j == k - 1) {
                cout << endl;
            }
        }
    }



    for (int i = 0; i <= str; i++) {
        B[i] = NULL;
    }
    B = NULL;
}