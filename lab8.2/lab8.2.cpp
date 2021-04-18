#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Obshaga { int number; int s; char fak[11]; int living; } S;

int random(int a, int b) {
    return a + rand() % (b - a + 1); //rand() % N + 1;
}

int main() {
    srand(time(NULL));
    const int n = 10;
    struct Obshaga Massive[n];
    char A[11] = "Fakultet A";
    char B[11] = "Fakultet B";
    char C[11] = "Fakultet C";
    for (int i = 0; i < 3; i++) {
        Massive[i] = { random(1, 100), random(10, 20), "Fakultet A", random(1, 3) };
        cout << Massive[i].number << " " << Massive[i].s << " " << Massive[i].fak << " " << Massive[i].living << endl;
    }
    for (int i = 4; i < 6; i++) {
        Massive[i] = { random(1, 100), random(10, 20), "Fakultet B", random(1, 3) };
        cout << Massive[i].number << " " << Massive[i].s << " " << Massive[i].fak << " " << Massive[i].living << endl;
    }
    for (int i = 6; i < n; i++) {
        Massive[i] = { random(1, 100), random(10, 20), "Fakultet C", random(1, 3) };
        cout << Massive[i].number << " " << Massive[i].s << " " << Massive[i].fak << " " << Massive[i].living << endl;
    }
    cout << "\n\n";

    char** Fakultets;
    Fakultets = new char* [];
    
    Fakultets[0] = new char[11];
    Fakultets[0] = Massive[0].fak;
    if (Fakultets == NULL) {
        printf("Error pizdec");
        return 1;
    }
    char temp[11];
  //  char temp = *Massive[0].fak;
    int amountF = 0;
    
    for (int i = 1; i < n; i++) {
        bool no = 0;
        for (int j = 0; j < amountF+1; j++) {
            if ((Fakultets[j] != Massive[i].fak)&&(no == 0)) {
                amountF++;
                Fakultets[amountF] = new char[11];
                Fakultets[amountF] = Massive[i].fak;
                no = 1;
                break;
            }
        }
    }
    cout << "\n\n";
    for (int i = 0; i < amountF; i++) {
        cout << Fakultets[i] << " ";
    }
    cout << amountF;

    for (int i = 0; i < amountF; i++) {
        Fakultets[i] = NULL;
    }
    Fakultets = NULL;
    return 0;
}