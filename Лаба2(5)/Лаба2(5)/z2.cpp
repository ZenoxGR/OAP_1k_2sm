#include <iostream>
#include "Windows.h"
#include <string>
#include <stdio.h>
#include <fstream>


using namespace std;


struct CITIZEN {
	string name;
	string birthDay;
	string address;
	string sex;
};




void Input(CITIZEN& c) {
	cout << "Введите ФИО" << endl;
	getline(cin, c.name, '\t');
	cout << "Введите год рождения" << endl;
	getline(cin, c.birthDay, '\t');
	cout << "Адрес" << endl;
	getline(cin, c.address, '\t');
	cout << "Пол" << endl;
	getline(cin, c.sex, '\t');
}


void Output(CITIZEN c[], int ind) {
	cout << "ФИО: " << c[ind].name << endl;
	cout << "Год рождения: " << c[ind].birthDay << endl;
	cout << "Адрес: " << c[ind].address << endl;
	cout << "Пол: " << c[ind].sex << endl;
	
}


void Delete(CITIZEN c[], int ind) {
	c[ind] = {};
}


void Search(CITIZEN c[], int size) {
	string year;
	cout << "Введите год рожения, по которому искать гражданина ";
	cin >> year;

	for (int i = 0; i < size; i++) {
		string year = c[i].birthDay;
		if (year == year) {
			Output(c, i);
		}
	}
}


void writeToFile(CITIZEN c[], int size) {
	ofstream file("citizen_data.txt");
	for (int i = 0; i < size; i++) {
		file << c[i].name << ", " << c[i].birthDay << ", " << c[i].address << ", " << c[i].sex << endl;
	}
	file.close();
	cout << "Данные записаны в файл citizen_data.txt" << endl;
}


void readFromFile() {
	ifstream file("citizen_data.txt");
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CITIZEN cirizen[10];
	int size = 0;
	int index = 0;
	bool flag = true;
	while (flag) {
		int choice;
		cout << "Выберите вариант \n 1) Ввод данных \n 2) Вывод данных \n 3) Удаление элементов \n 4) Поиск элементов \n 5) Запись в файл \n 6) Чтение из файла \n 7) Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			Input(cirizen[size]);
			size++;
			break;
		}
		case 2: {
			cout << "Введите номер гражданина, данные которого вывести" << endl;
			cin >> index;
			Output(cirizen, index);
			break;
		}
		case 3: {
			cout << "Введите номер гражданина, данные которого удалить" << endl;
			cin >> index;
			Delete(cirizen, index);
			break;
		}
		case 4: {
			Search(cirizen, size);
			break;
		}
		case 5: {
			writeToFile(cirizen, size);
			break;
		}
		case 6: {
			readFromFile();
			break;
		}
		case 7: {
			flag = false;
			break;
		}
		}
	}
}