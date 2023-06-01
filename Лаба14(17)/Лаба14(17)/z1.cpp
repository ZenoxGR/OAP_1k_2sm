//Заполнить массив С элементами массива А больше максимального элемента массива B
#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_50 5000

using namespace std;

int* MAX_MASSIVA(int size);
void transferElements(int A[], int size_a, int B[], int size_b, int C[], int& size_c);
int* sortMerge(int m[], int lm, int sm = 0);
void insOrd(int m[], int sm, int em, int e);
int* merge(int m[], int sm, int cm, int em);
void heapify(int A[], int pos, int n);
void piramSort(int A[], int n);
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
		cout << "4 - Сортировка массива C выбором" << endl;
		cout << "5 - Сортировка массива C слиянием" << endl;
		cout << "6 - Сортировка массива C пирамидаидальной сортировкой" << endl;
		cout << "7 - Вывод массива А" << endl;
		cout << "8 - Вывод массива В" << endl;
		cout << "9 - Вывод массива С" << endl;

		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			cout << "Введите количество элементов массива:";
			cin >> size_a;
			A = MAX_MASSIVA(size_a);
			control = 1;
			break;
		}
		case 2:
			cout << "Введите количество элементов массива:";
			cin >> size_b;
			B = MAX_MASSIVA(size_b);
			break;
		case 3: {
			transferElements(A, size_a, B, size_b, C, size_c);
			break;
		}
		case 4: {
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			insertSort(C, size_c);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
			break;
		}
		case 5:
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			sortMerge(C, size_c, 0);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
		}
		break;
		case 6:
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			piramSort(C, size_c);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
		}
		break;
		case 7: {
			PRINT(A, size_a);
			break;
		}
		case 8: {
			PRINT(B, size_b);
			break;
		}
		case 9: {
			PRINT(C, size_c);
			break;
		}
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
		*(mas + iter) = rand() % (size * 5);
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


void insOrd(int m[], int sm, int em, int e)
{ // m[]  массив чисел; sm  индекс 1-ого элемента левой части; cm  индекс
  //последн. элемента левой части; em  индекс последн. элемента правой части
	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
int* sortMerge(int m[], int lm, int sm)
{
	if (lm > 1)
	{
		sortMerge(m, lm / 2, sm);
		sortMerge(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}


void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
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