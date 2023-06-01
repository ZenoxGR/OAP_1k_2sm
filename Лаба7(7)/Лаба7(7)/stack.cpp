#include "stack.h"

string A = "A.txt";
char str[100];
int numOfnumber;
int* arr = new int[0];

void push(comp** top, int D)
{
	comp* q = new comp();
	q->Data = D;
	if (top == NULL)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

void delete_key(comp** top, int N)
{
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL)
	{
		if (q->Data == N)
		{
			if (q == *top)
			{

				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}

void find(comp* top, int N, int M)
{
	comp* q = top;
	comp* prev = NULL;
	cout << "������� : " << endl;
	while (q != NULL)
	{
		if (q->Data > N && q->Data < M) cout << q->Data << endl;
		prev = q;
		q = q->next;
	}
}

void print(comp* top)
{
	comp* q = top;
	while (q)
	{
		cout << q->Data << " --> ";
		q = q->next;
	}
	cout << "NULL" << endl;
}

bool extract(comp** top)
{
	comp* q = *top;
	if (q != NULL)
	{
		*top = q->next;
		free(q);
	}
	else return 0;

	return 1;
}

void toFile(comp* top)
{
	numOfnumber = 0;
	ofstream fAout(A);
	if (fAout.is_open())
	{
		if (top == NULL)
		{
			fAout << "������ ����" << endl;
		}
		else
		{
			while (top != NULL)
			{
				fAout << top->Data << endl;
				numOfnumber++;
				top = top->next;
			}
		}
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAout.close();
}

void fromFile(comp** top)
{
	int* arr = new int[numOfnumber], n;
	ifstream fAin(A);
	if (fAin.is_open())
	{
		clear(top);
		for (int i = 0; i < numOfnumber; i++)
		{
			fAin.getline(str, sizeof(str));
			arr[i] = atoi(str);
		}
		for (int i = numOfnumber - 1; i >= 0; i--)
		{
			push(top, arr[i]);
		}
		comp* q = *top;
		while (q)
		{
			cout << q->Data << " --> ";
			q = q->next;
		}
		cout << "NULL" << endl;
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAin.close();
	delete[] arr;
}

void clear(comp** top)
{
	while (extract(top));
}


int menu()
{
	int n = 0;
	cout << endl;
	cout << " 1. ���������� �����" << endl;
	cout << " 2. �������� �����" << endl;
	cout << " 3. ����� � �������" << endl;
	cout << " 4. ����� ����� � �������� ���������" << endl;
	cout << " 5. ������ � ����" << endl;
	cout << " 6. ������ �� �����" << endl;
	cout << " 7. ������� �����" << endl;
	cout << " 0. �����" << endl;
	cout << "(������� �����) ";
	cin >> n;
	cout << endl;
	return n;
}
































