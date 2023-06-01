#include <iostream>
#include "modules.h"
using namespace std;
void insertToQueue(int x, PriorityMode mode) {
    Item* p = new Item;
    p->data = x;
    p->next = NULL;
    Item* v = new Item;
    Item* p1 = new Item;
    Item* p2 = new Item;
    int i = 0;
    bool condition;

    if (isNull()) {
        head = tail = p;
    }
    else {
        p2 = head;
        p1 = head;
        while (p1 != NULL) {
            switch (mode) {
            case MIN_LIFO:
                condition = x < p1->data;
                break;
            case MAX_FIFO:
                condition = x > p1->data;
                break;
            case MIN_LIFO_END:
                condition = x <= p1->data;
                break;
            case MIN_LIFO_START:
                condition = x < p1->data;
                break;
            case MAX_FIFO_END:
                condition = x >= p1->data;
                break;
            default:
                condition = false;
                break;
            }

            if (i == 1) {
                if (condition) {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;
            }
            else {
                if (condition) {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL) {
            tail->next = p;
            tail = p;
        }
    }
}