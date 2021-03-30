#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Moves, Compares;

void InsertSort(int Massive[], int size) {
    Moves = 0, Compares = 0;
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = Massive[i];
        Moves++;
        j = i - 1;
        Compares++;
        while ((j >= 0) && (temp > Massive[j])) {
            Massive[j + 1] = Massive[j];
            if (j == i - 1) {
                Compares--;
            }
            Moves++;
            Compares++;
            j = j - 1;
        }
        Massive[j + 1] = temp;
        Moves++;
    }
}

void FillInc(int A[], int N) {
    for (int i = 0; i < N; i++)
        A[i] = i + 1;
};

void PrintMas(int A[], int N) {
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
};

void BSearch(int Massive[], int size, int search) {
    Compares = 0;
    int left = 0, right = size - 1, medium = 0;
    bool end = 0;

    while (left < right) {
        medium = (left + right) / 2;
        Compares++;
        if (Massive[medium] > search) {
            left = medium + 1;
        }
        else {
            right = medium;
        }
    }
    Compares++;
    if (Massive[right] == search) {
        end = 1;
    }

    cout << end << endl;
}

void Search(int Massive[], int size, int search) {
    Compares = 0;
    bool end = 0;
    for (int i = 0; i < size; i++) {
        Compares++;
        if (Massive[i] == search) {
            end = 1;
            break;
        }
    }
    cout << end << endl;
}

int main() {
    int A[100];
    FillInc(A, 100);
    InsertSort(A, 100);
    PrintMas(A, 100);
    cout << endl << "Moves = " << Moves << " Compares = " << Compares << "\n\n";
    int B[1000];
    FillInc(B, 1000);
    InsertSort(B, 1000);
    PrintMas(B, 1000);
    cout << endl << "Moves = " << Moves << " Compares = " << Compares << "\n\n";

    BSearch(A, 100, 8);
    cout << "Binary search Compares = " << Compares << "\n\n";

    Search(A, 100, 8);
    cout << "Default search Compares = " << Compares << "\n\n";
    
    BSearch(B, 1000, 8);
    cout << "Binary search Compares = " << Compares << "\n\n";

    Search(B, 1000, 8);
    cout << "Default search Compares = " << Compares << "\n\n";

	
	return 0;
}