#include <iostream>
#include "modules.h"
using namespace std;

void getFromHead() {
    if (isNull())
        cout << "������� �����" << endl;
    else
        cout << "������ = " << head->data << endl;
}