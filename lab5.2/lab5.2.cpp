#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int** B;
    B = new int* [9];
    for (int i = 0; i < 9; i++) {
        B[i] = new int[i+1];
    }
    if (B == NULL) {
        printf("Error pizdec");
        return 1;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < i+1; j++) {
            
            B[i][j] = (i+1) * (j+1);
            cout << B[i][j] << " ";
            if (j == i) {
                cout << endl;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        B[i] = NULL;
    }
    B = NULL;
}