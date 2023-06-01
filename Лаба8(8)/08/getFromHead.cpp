#include <iostream>
#include "modules.h"
using namespace std;

void getFromHead() {
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
        cout << "Начало = " << head->data << endl;
}