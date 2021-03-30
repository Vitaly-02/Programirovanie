#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int random(int N) {
    return rand() % N + 1;
}

void SumStr(int** Mas, int size) {
    cout << endl;
    int temp = 0;
    for (int i = 0; i < size; i++) {
        temp = 0;
        for (int j = 0; j < Mas[i][0]; j++) {
            temp += Mas[i][j];
        }
        cout << temp << endl;
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    int** B;
    int N = random(10);
    B = new int* [N];
    for (int i = 0; i < N; i++) {
        int e = random(5);
        B[i] = new int[e];
        B[i][0] = e;
    }
    if (B == NULL) {
        printf("Error pizdec");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < B[i][0]; j++) {
            B[i][j] = random(10);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B[i][0]; j++) {
            cout << B[i][j] << " ";
            if (j == B[i][0] - 1) {
                cout << endl;
            }
        }
    }

    SumStr(B, N);

    for (int i = 0; i < N; i++) {
        B[i] = NULL;
    }
    B = NULL;
}