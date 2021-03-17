#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int random(int N) {
    return rand() % N;
}

int main() {
 /*   int n = 5, m, **B, **C;
    cin >> m;
    B = new int *[m];
    for (int i = 0; i < m; i++) {
        B[i] = new int[n];
    }
    if (B == NULL) {
        printf("Error pizdec");
        return 1;
    }
    C = new int* [m-1];
    for (int i = 0; i < m-1; i++) {
        C[i] = new int[n-1];
    }
    if (C == NULL) {
        printf("Error pizdec");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = rand() % 10;
        }
    }
  */
    srand(time(NULL));
    int n = 5, m;
    cin >> m;
    int** B;
    B = new int* [n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[m];
    }
    if (B == NULL) {
        printf("Error pizdec");
        return 1;
    }
    int** C;
    C = new int* [n-1];
    for (int i = 0; i < n; i++) {
        C[i] = new int[m-1];
    }
    if (C == NULL) {
        printf("Error pizdec");
        return 1;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i][j] = random(11);
            cout << B[i][j] << " ";
            if (j == m - 1) {
                cout << endl;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (B[a][b] < B[i][j]) {
                a = i;
                b = j;
            }
        }
    }
    cout << endl;
    cout << a << " " << b;
    cout << endl;
    for (int i = 0, k = 0; i < n, k < n - 1; i++, k++) {
        for (int j = 0, l = 0; j < m, l < m - 1; j++, l++) {
            int y = 0;
            if (i == a) {
                y = 1;
            }
            if (j == b) {
                y = 2;
            }
            if ((i == a)&&(j == b)) {
                y = 3;
            }
            switch (y) {
            case 0:
                break;
            case 1:
                i++;
                break;
            case 2:
                j++;
                break;
            case 3:
                i++;
                j++;
                break;
            }
            C[k][l] = B[i][j];
            cout << C[k][l] << " ";
            if (j == m - 2) {
                cout << endl;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        B[i] = NULL;
    }
    B = NULL;
    for (int i = 0; i < n-1; i++) {
        C[i] = NULL;
    }
    C = NULL;
}
