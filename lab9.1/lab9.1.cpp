#include <iostream>
using namespace std;

struct info {   
    string name;
    int rate_1;
    int rate_2;
    int rate_3;
    int rate_4;
};
struct node {
    node* next;
    struct info data;

    node(info datA): data(datA), next(nullptr) {}
};
struct list {
    node* head;
    node* tail;

    list(): head(nullptr), tail(nullptr) {}

    bool is_empty() {
        return (head == nullptr);
    }

    void pushback(info student) {
        node* p = new node(student);
        if (is_empty()) {
            head = p;
            tail = p;
            return;
        }
        tail->next = p;
        tail = p;
    }

    void print_list() {
        if (is_empty()) {
            return;
        }
        node* p = head;
        while (p) {
            cout << p->data.name << " " << p->data.rate_1 << " " << p->data.rate_2 << " " << p->data.rate_3 << " " << p->data.rate_4 << endl;
            p = p->next;
        }
        cout << endl;
    }

    void sort_name() {
        if (is_empty()) {
            return;
        }
        node* p = head;
        
        while (p) {
            node* temp;
            if (p->next == nullptr) {
                temp = p;
                swap(p, p->next);
                swap(p->next->next, temp);
                swap(temp, p);
                p = nullptr;
                p->next = tail;
            }
            if (p == head) {
                if (p->data.name[0] > p->next->data.name[0]) {
                    head = p->next;
                    temp = p;
                    swap(p, p->next);
                    swap(p->next->next, temp);
                    swap(temp, p);
                }
            }
            else {
                node* temp;
                if (p->data.name[0] > p->next->data.name[0]) {
                    temp = p;
                    swap(p, p->next);
                    swap(p->next->next, temp);
                    swap(temp, p);
                }
            }
        }
    }


};


int main() {

    list q;
    cout << q.is_empty() << endl;
    q.pushback({ "Petr", 1, 2, 3, 4 });
    q.pushback({ "Dalb", 2, 3, 4, 5 });
    q.pushback({ "Ayob", 3, 4, 5, 6 });
    cout << q.is_empty() << endl;
    q.print_list();
    q.sort_name(); q.print_list();
    return 0;
}