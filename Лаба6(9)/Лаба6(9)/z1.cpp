#include <iostream> 
#include<Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* pred;
};

int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. ���� �����" << endl;
	cout << "2. ���������� �������� � � ����� ������" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. �����" << endl;
	cout << endl;
	do
	{
		cout << "��� �����: ";
		cin >> c;
	} while (c < 0 || c > 5);
	return c;
}

void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->pred = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->pred = p;
		*plast = e;
	}
}

Address* setElement()
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.ignore(4096, '\n');
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cout << "������� �����: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	temp->next = NULL;
	temp->pred = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city;
		t = t->next;
	}
	cout << "" << endl;
}

void addXEnd(Address** phead, Address** plast, int x)
{
	Address* e = new Address();
	if (!e)
	{
		cerr << "������ ��������� ������";
		return;
	}
	e->next = *phead;
	e->pred = NULL;
	sprintf_s(e->city, CITY_SIZE - 1, "%d", x);
	if (*phead != NULL)
	{
		(*phead)->pred = e;
	}
	*phead = e;
	if (*plast == NULL)
	{
		*plast = e;
	}
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2:
		{
			int x;
			cout << "������� �����: ";
			cin >> x;
			addXEnd(&head, &last, x);
		}
		break;

		case 3:  outputList(&head, &last);
			break;
		case 4:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}