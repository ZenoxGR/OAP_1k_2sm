//#include <iostream>
//#include "windows.h"
//#include <stdio.h>
//#include <string>
//
//using namespace std;
//
//enum government {
//	monarchy = 1,
//	republic,
//	democracy,
//	federation
//};
//
//struct country {
//	string name;
//	string capital;
//	string population;
//	string landmass;
//	government gov;
//};
//
//
//
//
//void input(country &c) {
//	cout << "������� ��������" << endl;
//	getline(cin, c.name, '\t');
//	cout << "������� �������" << endl;
//	getline(cin, c.capital, '\t');
//	cout << "������� ����������� ���������" << endl;
//	getline(cin, c.population, '\t');
//	cout << "������� ������� ������" << endl;
//	getline(cin, c.landmass, '\t');
//	int form;
//	cout << "������� ����� ��������� 1 - ��������, 2 - ����������, 3 - ����������, 4 - ���������" << endl;
//	cin >> form;
//	switch (form) {
//		case 1: {
//			c.gov = monarchy;
//			break;
//		}
//		case 2: {
//			c.gov = republic;
//			break;
//		}
//		case 3: {
//			c.gov = democracy;
//			break;
//		}
//		case 4: {
//			c.gov = federation;
//			break;
//		}
//	}
//	
//}
//
//
//void output(country c[], int ind) {
//	cout << "��������: " << c[ind].name << endl;
//	cout << "�������: " << c[ind].capital << endl;
//	cout << "����������� ���������: " << c[ind].population << endl;
//	cout << "������� ������: " << c[ind].landmass << endl;
//	cout << "����� ���������: ";
//	switch (c[ind - 1].gov) {
//	case monarchy: {
//		cout << "��������" << endl;
//		break;
//	}
//	case republic: {
//		cout << "����������" << endl;
//		break;
//	}
//	case democracy: {
//		cout << "����������" << endl;
//		break;
//	}
//	case federation: {
//		cout << "���������" << endl;
//		break;
//	}
//	}
//}
//
//
//void Delete(country c[], int ind) {
//	c[ind] = {};
//}
//
//
//void search(country c[], int size) {
//	string name;
//	cout << "����� �������, �� ������� ������ ������ ";
//	cin >> name;
//
//	for (int i = 0; i < size; i++) {
//		string name = c[i].capital;
//		if (name == name) {
//			output(c, i);
//		}
//	}
//}
//
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	country country[10];
//	int size = 0;
//	int index = 0;
//	bool flag = true;
//	while (flag) {
//	int choice;
//	cout << "�������� ������� \n 1) ���� ������ \n 2) ����� ������ \n 3) �������� ��������� \n 4) ����� ��������� \n 5) �����" << endl;
//	cin >> choice;
//		switch (choice) {
//			case 1: {
//				input(country[size]);
//				size++;
//				break;
//			}
//			case 2: {
//				cout << "������� ����� ������, ������ ������� �������" << endl;
//				cin >> index;
//				output(country, index);
//				break;
//			}
//			case 3: {
//				cout << "������� ����� ������, ������ ������� �������" << endl;
//				cin >> index;
//				Delete(country, index);
//				break;
//			}
//			case 4: {
//				search(country, size);
//				break;
//			}
//			case 5: {
//				flag = false;
//				break;
//			}
//		}
//	}
//}