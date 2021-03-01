#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//3.1
int random(int N) { 
    return rand() % N; 
}

void RandomMas(int* P, int size, int a, int b) {
    for (int i = 0; i < size; i++) {
        P[i] = random(b - a + 1) + a;
    }
}

void PrintMas(int* P, int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << P[i] << " ";
    cout << endl;
};

int main() {
    srand(time(NULL));
    int size;
    int* Mas;
    scanf_s("%d", &size);
    Mas = (int*)malloc(size * sizeof(int));
    if (Mas == NULL) {
        printf("Error pizdec");
        return 1;
    }
    RandomMas(Mas, size, -50, 50);
    PrintMas(Mas, size);
    
    int otric = 0, poloz = 0;
    for (int i = 0; i < size; i++) {
        if (Mas[i] < 0) {
            otric++;
        }
    }
    poloz = size - otric;
    int* Poloz; 
    int* Otric;
    Poloz = (int*)malloc(poloz * sizeof(int));
    Otric = (int*)malloc(otric * sizeof(int));
    int j = 0, k = 0;
    for (int i = 0; i < size; i++) {
        if (Mas[i] < 0) {
            Otric[j] = Mas[i];
            j++;
        }
        else {
            Poloz[k] = Mas[i];
            k++;
        }
    }
    PrintMas(Otric, otric);
    PrintMas(Poloz, poloz);
    return 0;
}
