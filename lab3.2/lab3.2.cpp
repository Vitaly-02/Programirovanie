#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//3.2

void RandomMas(double* P, int size, int a, int b) {
    for (int i = 0; i < size; i++) {
        P[i] = rand() * ((double)b - a) / RAND_MAX + a;
    }
}

void PrintMas(double* P, int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << P[i] << " ";
    cout << endl;
}

int main() {
    srand(time(NULL));
    int size;
    double* Mas;
    cin >> size;
    Mas = new double[size];
    if (Mas == NULL) {
        printf("Error pizdec");
        return 1;
    }
    RandomMas(Mas, size, -10, 10);
    PrintMas(Mas, size);
    double **Points;
    Points = new double*[size];
    if (Points == NULL) {
        printf("Error pizdec 2");
        return 2;
    }
    
    for (int i = 0; i < size; i++) {
        Points[i] = &Mas[i];
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if (*Points[j] < *Points[j - 1]) {
                swap(Points[j], Points[j - 1]);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << *Points[i] << " ";
    } 

    delete Mas;
    delete Points;
    return 0;
}