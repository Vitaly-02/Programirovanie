#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct School { int number; int graduated; int students; } S;

int random(int a, int b) {
    return a + rand() % (b - a + 1); //rand() % N + 1;
}

void FillInc(int A[], int N) {
    for (int i = 0; i < N; i++)
        A[i] = i;
};

int CompareSchool(School one, School two) {
    int temp1 = (one.students*100 / one.graduated);
    int temp2 = (two.students*100 / two.graduated);
        if (temp1 > temp2) {
            return 2;
        }
        else if (temp1 < temp2) {
            return 1;
        }
    return 0; //esli ravno
}

void BubbleSort(School Massive[], int Index[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if (CompareSchool(Massive[Index[j]], Massive[Index[j-1]]) == 1) {
                swap(Index[j], Index[j - 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    const int n = 4;
    struct School Massive[n];
    for (int i = 0; i < n; i++) {
        int g = random(10, 120);
        Massive[i] = { random(1, 99), g, random(10, g) };
        cout << Massive[i].number << " " << Massive[i].graduated << " " << Massive[i].students << endl;
    }
    int Index[n];
    FillInc(Index, n);
    BubbleSort(Massive, Index, n);
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        cout << Massive[Index[i]].number << " " << Massive[Index[i]].graduated << " " << Massive[Index[i]].students << endl;
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        cout << Massive[Index[i]].number << " Graduated: " << Massive[Index[i]].graduated << " Postupili: " << (Massive[Index[i]].students)*100/Massive[Index[i]].graduated << "%" << endl;
    }
   
    return 0;
}

