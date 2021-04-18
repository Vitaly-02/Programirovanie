#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Obshaga { int number; int s; string fak; int living; } S;

int random(int a, int b) {
    return a + rand() % (b - a + 1); //rand() % N + 1;
}

int main() {
    srand(time(NULL));
    const int n = 10;
    struct Obshaga Massive[n];
    string A = "Fakultet A";
    string B = "Fakultet B";
    string C = "Fakultet C";
    cout << "Nomer room     Ploshad     Fakultet         Kol-vo students" << endl;
    for (int i = 0; i < 3; i++) {
        Massive[i] = { random(1, 100), random(10, 20), A, random(1, 3) };
        cout << Massive[i].number << "             " << Massive[i].s << "             " << Massive[i].fak << "             " << Massive[i].living << endl;
    }
    for (int i = 3; i < 6; i++) {
        Massive[i] = { random(1, 100), random(10, 20), B, random(1, 3) };
        cout << Massive[i].number << "             " << Massive[i].s << "             " << Massive[i].fak << "             " << Massive[i].living << endl;
    }
    for (int i = 6; i < n; i++) {
        Massive[i] = { random(1, 100), random(10, 20), C, random(1, 3) };
        cout << Massive[i].number << "             " << Massive[i].s << "             " << Massive[i].fak << "             " << Massive[i].living << endl;
    }
    
    string** Fakultets;
    Fakultets = new string* [11];
    
    Fakultets[0] = new string[11];
    Fakultets[0] = &Massive[0].fak;
    if (Fakultets == NULL) {
        printf("Error pizdec");
        return 1;
    }

    int amountF = 0;
    
    for (int i = 1; i < n; i++) {
        bool no = 1;
        for (int j = 0; j < amountF+1; j++) {
            if (*Fakultets[j] != Massive[i].fak) {
                no = no * 1;
            }
            else {
                no = 0;
            }   
        }
        if (no == 1) {
            amountF+=1;
            Fakultets[amountF] = new string[11];
            *Fakultets[amountF] = Massive[i].fak;
            no = 0;
        }
    }
    cout << endl;
    for (int i = 0; i < amountF+1; i++) {
        cout << *Fakultets[i] << endl;
    }
    cout << "Vsego fakultetov: " << amountF+1 << "\n\n";
    cout << "Nazvanie fakulteta    Kol-vo rooms    Kol-vo students      Medium ploshad/student" << endl;
    struct Info { string fak; int amount_rooms; int amount_students; double plosh; };
    struct Info *Information;
    Information = new Info[amountF + 1];
    for (int i = 0; i < amountF + 1; i++) {
        Information[i].fak = *Fakultets[i];
        Information[i].amount_rooms = 0;
        Information[i].amount_students = 0;
        Information[i].plosh = 0;
        for (int j = 0; j < n; j++) {
            if (Information[i].fak == Massive[j].fak) {
                Information[i].amount_rooms += 1;
                Information[i].amount_students += Massive[j].living;
                Information[i].plosh += Massive[j].s;
            }
        }
        cout << Information[i].fak << "               " << Information[i].amount_rooms << "                  " << Information[i].amount_students << "               " << Information[i].plosh/Information[i].amount_students << endl;
    }

    for (int i = 0; i < amountF+1; i++) {
        Fakultets[i] = NULL;
    }
    Fakultets = NULL;
    Information = NULL;
    return 0;
}