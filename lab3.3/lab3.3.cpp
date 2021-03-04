#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    int n;
    bool* Mas;
    cin >> n;
    Mas = new bool[n];
    if (Mas == NULL) {
        printf("Error pizdec");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        Mas[i] = true;
    }

    for (int i = 2; i*i <= n; i++) {
        if (Mas[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                Mas[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (Mas[i] == true) {
            cout << i << " ";
        }
    }
    Mas = NULL;
    return 0;
}