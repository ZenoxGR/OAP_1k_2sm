#include <iostream>
#include "modules.h"
using namespace std;

void printQueue() {
    Item* p = new Item;
    if (isNull()) {
        cout << "������� �����" << endl;
    }
    else {
        cout << "������� = ";
        p = head;
        while (!isNull()) {
            if (p != NULL) {
                cout << p->data << " ";
                cout << "-> ";
                p = p->next;
            }
            else {
                cout << "NULL" << endl;
                return;
            }
        }
    }
}