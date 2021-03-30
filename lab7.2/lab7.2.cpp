#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int random(int N) {
    return rand() % N + 1;
}

int main() {
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
        cout << B[i][0] << endl;

    }
    cout << "\n\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B[i][0]; j++) {

            B[i][j] = random(11);
            cout << B[i][j] << " ";
            if (j == B[i][0]) {
                cout << endl;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        B[i] = NULL;
    }
    B = NULL;
}

