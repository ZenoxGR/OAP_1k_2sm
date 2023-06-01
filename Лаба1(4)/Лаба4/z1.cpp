#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"
using namespace std;

struct Car {
    string model;
    string color;
    string fabricNum;
    string releaseDate;
    string carBody;
    string lastTechInspectionDate;
    string ownerName;
};


void inputElements(Car &c) {
    cout << "Введи марку: ";
    cin >> c.model;
    cout << "Введи цвет: ";
    cin >> c.color;
    cout << "Введи заводской номер: ";
    cin >> c.fabricNum;
    cout << "Введи дату выпуска:";
    cin >> c.releaseDate;
    cout << "Введи тип кузова:";
    cin >> c.carBody;
    cout << "Введи дату последнего техосмотра:";
    cin >> c.lastTechInspectionDate;
    cout << "Введи имя владельца:";
    cin >> c.ownerName;
    cout << "Информация добавлена!" << endl;
}


void outputElements(Car cars[], int index) {
    cout << "Марка: " << cars[index].model << endl;
    cout << "Цввет: " << cars[index].color << endl;
    cout << "Заводской номер: " << cars[index].fabricNum << endl;
    cout << "Дата выпуска: " << cars[index].releaseDate << endl;
    cout << "Тип кузова: " << cars[index].carBody << endl;
    cout << "Дата последнего техосмотра: " << cars[index].lastTechInspectionDate << endl;
    cout << "Имя владельца: " << cars[index].ownerName << endl;
}


void deleteStruct(Car& c) {
    c = {};
}


void searchByOwnerName(Car cars[], int size) {
    string name;
    cout << "Введи имя, по которому искать авто: ";
    cin >> name;

    for (int i = 0; i < size; i++) {
        string Name = cars[i].ownerName;
        if (Name == name) {
            outputElements(cars, i);
        }
    }
}

 
void writeToFile(Car cars[], int size) {
    ofstream file("car_data.txt");
    for (int i = 0; i < size; i++) {
        file << cars[i].model << ", " << cars[i].color << ", " << cars[i].fabricNum << ", " << cars[i].releaseDate << ", " << cars[i].carBody << ", " << cars[i].lastTechInspectionDate << ", " << cars[i].ownerName << endl;
    }
    file.close();
    cout << "Данные записаны в файл car_data.txt" << endl;
}


void readFromFile() {
    ifstream file("car_data.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    Car cars[100];
    int size = 0;

    while (true) {
        cout << "1. Ввести данные об авто" << endl;
        cout << "2. Вывести данные об авто" << endl;
        cout << "3. Удалить данные об авто" << endl;
        cout << "4. Поиск по имени владельца" << endl;
        cout << "5. Запись в файл" << endl;
        cout << "6. Чтение из файла" << endl;
        cout << "7. Выход" << endl;
        cout << "Введите вариант: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            inputElements(cars[size]);
            size++;
            break;
        }
        case 2: {
            int index;
            cout << "Введите номер машины, данные которой нужно вывести: ";
            cin >> index;
            outputElements(cars, index);
            break;
        }
        case 3:
        {
            int index;
            cout << "Введите номер машины, данные которой нужно удалить: ";
            cin >> index;
            deleteStruct(cars[index]);
            break;
        }
        case 4: {
            searchByOwnerName(cars, size);
            break;
        }
        case 5: {
            writeToFile(cars, size);
            break;
        }
        case 6: {
            readFromFile();
            break;
        }
        case 7: {
            return 0;
        }
        default: {
            cout << "Неверный вариант! Попробуйте еще раз!" << endl;
            break;
        }
        }
    }
    return 0;
}