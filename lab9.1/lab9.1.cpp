#include <iostream>
using namespace std;
typedef struct info {
    string name;
    int rate_1;
    int rate_2;
    int rate_3;
    int rate_4;
};
typedef struct list {
    list* next;
    struct info data;
};

void new_1(list *point){

}

void initialization(list* head, info temp) {
    list* pointer = new list;
    pointer->data = temp;
    pointer->next = NULL;
    head = pointer;
}

void add_start(list* head, info temp) {
    if (head == NULL) {
        initialization(head, temp);
        cout << "inited";
    }
    else {
        list *p = new list;
        p->data = temp;
        p->next = head;
        head = p;
    }
}

void print_list(list* head) {
    list* p = head;
    cout << "\n";
    while (p != 0) {
        cout << p->data.name << " " << p->data.rate_1 << " " << p->data.rate_2 << " " << p->data.rate_3 << " " << p->data.rate_4 << "\n";
        p = p->next;
    }
}

int main() {
    list* head = NULL;
    info temp = { "name",0,0,0,0 };
 //   initialization(head, temp);
    cout << "inited123";
    head = new list;
    add_start(head, { "Petr", 1, 2, 3, 4 });
    add_start(head, { "Dalb", 2, 3, 4, 5 });
    add_start(head, { "Ayob", 3, 4, 5, 6 });
    print_list(head);

    cout << head->data.rate_1;
    return 0;
}