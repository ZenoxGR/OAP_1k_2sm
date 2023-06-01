//Заполнить массив С элементами массива А больше максимального элемента массива B
#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_50 50000

using namespace std;

int* MAX_MASSIVA(int size);
void transferElements(int A[], int size_a, int B[], int size_b, int C[], int& size_c);
void bubbleSort(int C[], int size_c);
void PRINT(int* MASSIVE, int size);
void insertSort(int* C, int size_c);
int size_a = 0;
int size_b = 0;
int size_c = 0;

int main()
{
	int control = 0; 
	int* A = new int[MAX_50], * B = new int[MAX_50], * C = new int[MAX_50];
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int choice = 0;
	do
	{
		cout << "\nВыберите необходимый пункт:\n";
		cout << "1 - Заполнить массив A n-значениями" << endl;
		cout << "2 - Заполнить массив B n-значениями " << endl;
		cout << "3 - Заполнение массива C элементами массива А, большими максимального элемента массива В" << endl;
		cout << "4 - Сортировка массива C пузырьком по убыванию" << endl;
		cout << "5 - Сортировка массива C вставками по возрастанию" << endl;
		cout << "6 - Вывод массива А" << endl;
		cout << "7 - Вывод массива В" << endl;
		cout << "8 - Вывод массива С" << endl;

		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите количество элементов массива:";
			cin >> size_a;
			control = 0;
			A = MAX_MASSIVA(size_a);
			control = 1;
			break;
		case 2:
			cout << "Введите количество элементов массива:";
			cin >> size_b;
			control = 2;
			B  = MAX_MASSIVA(size_b);
			 break;
		case 3: {
			transferElements(A, size_a, B, size_b, C, size_c);
			break;
		}
		case 4: {
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			bubbleSort(C, size_c);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
			break;
		}
		case 5:
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			insertSort(C, size_c);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
		}
			break;

		case 6:if (control >= 1)PRINT(A, size_a);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 7:if (control >= 1)PRINT(B, size_b);
			  else
			cout << "Массив не объявлен!" << endl;
			break;
		case 8:if (control >= 1)PRINT(C, size_c);
			  else
			cout << "Массив не объявлен!" << endl;
			break;
		case 0:exit(0); break;
		default:cout << "Введена неверная команда!" << endl; break;
		}

	} while (choice != 0);
	return 0;
}

int* MAX_MASSIVA(int size)
{
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		*(mas + iter) = rand() % (size*5);
	}
	return  mas;
}

void transferElements(int A[], int size_a, int B[], int size_b, int C[], int& size_c) {
	int maxB = B[0];
	for (int i = 1; i < size_b; i++) {
		if (B[i] > maxB) {
			maxB = B[i];
		}
	}
	size_c = 0;
	for (int i = 0; i < size_a; i++) {
		if (A[i] > maxB) {
			C[size_c] = A[i];
			size_c++;
		}
	}
}


void bubbleSort(int C[], int size_c)
{
	int i, j, t;
	for (i = 1; i < size_c; i++)
		for (j = size_c - 1; j >= i; j--)
			if (C[j - 1] < C[j])
			{
				t = C[j - 1];
				C[j - 1] = C[j];
				C[j] = t;
			}
}

void insertSort(int* C, int size_c)
{
	int t, i, j;
	for (i = 1; i < size_c; i++)
	{
		t = C[i];
		for (j = i - 1; j >= 0 && C[j] > t; j--)
			C[j + 1] = C[j];
		C[j + 1] = t;
	}
}


void PRINT(int* MASSIVE, int size)
{
	int space = 0;
	for (int iter = 0; iter < size; iter++)
	{
		cout.width(5);
		cout << MASSIVE[iter] << "  ";
		space++;
		if (space == 10)
		{
			printf("\n");
			space = 0;
		}
	}
	printf("\n");
}