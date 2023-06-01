#include <iostream>
#include "modules.h"
using namespace std;

void deleteFirst() {
    if (isNull())
        cout << "Очередь пуста" << endl;
    else {
        Item* p = head;
        head = head->next;
        delete p;
    }
}