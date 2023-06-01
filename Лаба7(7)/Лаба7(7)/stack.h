#pragma once
#include <iostream>;
#include <fstream>
#include <string>
#include <malloc.h>
using namespace std;

struct comp {
	int Data;
	comp* next;
};

void push(comp** top, int D);
void delete_key(comp** top, int N);
void find(comp* top, int N, int M);
void print(comp* top);
bool extract(comp** top);
void toFile(comp* top);
void fromFile(comp** top);
void clear(comp** top);

int menu();
