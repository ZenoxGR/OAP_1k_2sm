#include <iostream>
#include "modules.h"
using namespace std;

void deleteFirstNegative() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        Item* prev = nullptr;
        Item* curr = head;

        while (curr != nullptr) {
            if (curr->data < 0) {
                

                if (prev == nullptr) {
                    
                    Item* temp = head;
                    head = head->next;
                    delete temp;
                    return;
                }
                else {
                   
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
            }

            prev = curr;
            curr = curr->next;
        }
        cout << "Отрицательный элемент не найден" << endl;
    }
}