#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int random(int N) {
    return rand() % N;
}

int main() {
    srand(time(NULL));
    int n, m;
    cin >> n >> m;
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
    C = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        C[i] = new int[m + 1];
    }
    if (C == NULL) {
        printf("Error pizdec");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i][j] = random(11);
        }
    }
    
    int sum = 0, sumi = 0, sumj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                C[i][j] = B[i][j];
                sumi += B[i][j];
                sum += B[i][j];
        }
        C[i][m] = sumi;
        sumi = 0;
    }
    C[n][m] = sum;
    int j = 0; int i = 0;
    while (j < m) {
        for (i = 0; i < n; i++) {
            sumj += B[i][j];
            
        }
        C[n][j] = sumj;
        sumj = 0;
        j++;
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << B[i][j] << " ";
            if (j == m - 1) {
                cout << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            cout << C[i][j] << " ";
            if (j == m) {
                cout << endl;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        B[i] = NULL;
    }
    B = NULL;
    for (int i = 0; i < n + 1; i++) {
        C[i] = NULL;
    }
    C = NULL;
}