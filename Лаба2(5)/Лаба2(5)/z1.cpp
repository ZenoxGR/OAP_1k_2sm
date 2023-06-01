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
//	cout << "введите название" << endl;
//	getline(cin, c.name, '\t');
//	cout << "введите столицу" << endl;
//	getline(cin, c.capital, '\t');
//	cout << "введите численность населени€" << endl;
//	getline(cin, c.population, '\t');
//	cout << "введите площадь страны" << endl;
//	getline(cin, c.landmass, '\t');
//	int form;
//	cout << "введите форму правлени€ 1 - монархи€, 2 - республика, 3 - демократи€, 4 - федераци€" << endl;
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
//	cout << "название: " << c[ind].name << endl;
//	cout << "столица: " << c[ind].capital << endl;
//	cout << "численность населени€: " << c[ind].population << endl;
//	cout << "площадь страны: " << c[ind].landmass << endl;
//	cout << "форма правлени€: ";
//	switch (c[ind - 1].gov) {
//	case monarchy: {
//		cout << "монархи€" << endl;
//		break;
//	}
//	case republic: {
//		cout << "республика" << endl;
//		break;
//	}
//	case democracy: {
//		cout << "демократи€" << endl;
//		break;
//	}
//	case federation: {
//		cout << "федераци€" << endl;
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
//	cout << "введи столицу, по которой искать страну ";
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
//	cout << "выберите вариант \n 1) ввод данных \n 2) вывод данных \n 3) удаление элементов \n 4) поиск элементов \n 5) выход" << endl;
//	cin >> choice;
//		switch (choice) {
//			case 1: {
//				input(country[size]);
//				size++;
//				break;
//			}
//			case 2: {
//				cout << "введите номер страны, данные которой вывести" << endl;
//				cin >> index;
//				output(country, index);
//				break;
//			}
//			case 3: {
//				cout << "введите номер страны, данные которой удалить" << endl;
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