#pragma once
struct Item {
    int data;
    Item* next;

};

extern Item* head;
extern Item* tail; 

enum PriorityMode {
    MIN_LIFO,
    MAX_FIFO,
    MIN_LIFO_END,
    MIN_LIFO_START,
    MAX_FIFO_END
};

bool isNull();
void deleteFirst();
void getFromHead();
void insertToQueue(int x, PriorityMode mode);
void printQueue();
void deleteFirstNegative();
void clrQueue();

