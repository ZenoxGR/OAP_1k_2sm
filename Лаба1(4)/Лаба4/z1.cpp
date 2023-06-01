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
    cout << "����� �����: ";
    cin >> c.model;
    cout << "����� ����: ";
    cin >> c.color;
    cout << "����� ��������� �����: ";
    cin >> c.fabricNum;
    cout << "����� ���� �������:";
    cin >> c.releaseDate;
    cout << "����� ��� ������:";
    cin >> c.carBody;
    cout << "����� ���� ���������� ����������:";
    cin >> c.lastTechInspectionDate;
    cout << "����� ��� ���������:";
    cin >> c.ownerName;
    cout << "���������� ���������!" << endl;
}


void outputElements(Car cars[], int index) {
    cout << "�����: " << cars[index].model << endl;
    cout << "�����: " << cars[index].color << endl;
    cout << "��������� �����: " << cars[index].fabricNum << endl;
    cout << "���� �������: " << cars[index].releaseDate << endl;
    cout << "��� ������: " << cars[index].carBody << endl;
    cout << "���� ���������� ����������: " << cars[index].lastTechInspectionDate << endl;
    cout << "��� ���������: " << cars[index].ownerName << endl;
}


void deleteStruct(Car& c) {
    c = {};
}


void searchByOwnerName(Car cars[], int size) {
    string name;
    cout << "����� ���, �� �������� ������ ����: ";
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
    cout << "������ �������� � ���� car_data.txt" << endl;
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
        cout << "1. ������ ������ �� ����" << endl;
        cout << "2. ������� ������ �� ����" << endl;
        cout << "3. ������� ������ �� ����" << endl;
        cout << "4. ����� �� ����� ���������" << endl;
        cout << "5. ������ � ����" << endl;
        cout << "6. ������ �� �����" << endl;
        cout << "7. �����" << endl;
        cout << "������� �������: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            inputElements(cars[size]);
            size++;
            break;
        }
        case 2: {
            int index;
            cout << "������� ����� ������, ������ ������� ����� �������: ";
            cin >> index;
            outputElements(cars, index);
            break;
        }
        case 3:
        {
            int index;
            cout << "������� ����� ������, ������ ������� ����� �������: ";
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
            cout << "�������� �������! ���������� ��� ���!" << endl;
            break;
        }
        }
    }
    return 0;
}