//#include <iostream>
//#include <fstream>
//#include <list>
//using namespace std;
//void printList(list<double> myList);
//double multiplyLessThan10(list<double> myList);
//void saveListToFile(list<double> myList, string fileName);
//list<double> readListFromFile(string fileName);
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    list<double> myList;
//    int choice;
//    double num;
//    string fileName;
//    do {
//        cout << endl << "1. ���������� ��-��" << endl;
//        cout << "2. �������� ��-��" << endl;
//        cout << "3. ����� ��-��" << endl;
//        cout << "4. ����� ������ � �������" << endl;
//        cout << "5. ������ ������ � ����" << endl;
//        cout << "6. ������ ������ �� �����" << endl;
//        cout << "7. ��������� ��-��" << endl;
//        cout << "8. �����" << endl;
//        cout << "��� �����: ";
//        cin >> choice;
//        switch (choice) {
//        case 1:
//            cout << "������� ����� ��� ���������� � ������: ";
//            cin >> num;
//            myList.push_back(num);
//            break;
//        case 2:
//            cout << "������� ����� ��� �������� �� ������: ";
//            cin >> num;
//            myList.remove(num);
//            break;
//        case 3:
//            cout << "������� ����� ��� ������: ";
//            cin >> num;
//            if (find(myList.begin(), myList.end(), num) != myList.end()) {
//                cout << "����� �������" << endl;
//            }
//            else {
//                cout << "����� �� �������" << endl;
//            }
//            break;
//        case 4:
//            printList(myList);
//            break;
//        case 5:
//            cout << "������� ��� �����: ";
//            cin >> fileName;
//            saveListToFile(myList, fileName);
//            break;
//        case 6:
//            cout << "������� ��� �����: ";
//            cin >> fileName;
//            myList = readListFromFile(fileName);
//            printList(myList);
//            break;
//        case 7:
//            cout << "������������ �����, ������� ������ 10: " << multiplyLessThan10(myList);
//            break;
//        case 8:
//            cout << "����� ...";
//            break;
//        default:
//            cout << "�������� �����" << endl;
//            break;
//        }
//    } while (choice != 8);
//    return 0;
//}
//void printList(list<double> myList) {
//    cout << "������: ";
//    for (list<double>::iterator it = myList.begin(); it != myList.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl;
//}
//double multiplyLessThan10(list<double> myList) {
//    double product = 1;
//    for (list<double>::iterator it = myList.begin(); it != myList.end(); it++) {
//        if (*it < 10) {
//            product *= *it;
//        }
//    }
//    return product;
//}
//void saveListToFile(list<double> myList, string fileName) {
//    ofstream outputFile;
//    outputFile.open(fileName.c_str());
//    for (list<double>::iterator it = myList.begin(); it != myList.end(); it++) {
//        outputFile << *it << endl;
//    }
//    outputFile.close();
//    cout << "������ ������� " << fileName << endl;
//}
//list<double> readListFromFile(string fileName) {
//    list<double> myList;
//    ifstream inputFile;
//    inputFile.open(fileName.c_str());
//    if (!inputFile.is_open()) {
//        cout << "�� ������� ������� ���� " << fileName << endl;
//        return myList;
//    }
//    double num;
//    while (inputFile >> num) {
//        myList.push_back(num);
//    }
//    inputFile.close();
//    cout << "������ �������� " << fileName << endl;
//    return myList;
//}


#include <iostream>
using namespace std;
struct list
{
    float number;
    list* next;
};

void insert(list*&, float);
void printList(list*);
void menu(void);
void proiz(list*);


int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    float value;
    menu();
    cout << "�������� �������: ";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:    cout << "������� ����� ";
            cin >> value;
            insert(first, value);
            break;   
        case 2:printList(first);
            break;
        case 3: proiz(first);
        default:  cout << "������������ �����" << endl;
            menu();
            break;
        }
        cout << "�������� �������: " << endl;
        cin >> choice;
    }
    cout << "�����" << endl;
    return 0;
}

void menu(void)
{
    cout << "�������� �����:" << endl;
    cout << " 1 - ���� �����" << endl;
    cout << " 2 - ����� ������" << endl;
    cout << " 3 - ���������� ������������ ����� ������ 10" << endl;
    cout << " 4 - �����" << endl;
}

void insert(list*& p, float value)
{
    list* newP = new list;
    if (newP != NULL)
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "�������� ���������� �� ���������" << endl;
}

void printList(list* p)
{
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        cout << "������:" << endl;
        while (p != NULL)
        {
            cout << " " << p->number;
            p = p->next;
        }
        cout << endl;
    }
}

void proiz(list* p)
{
    float pr = 1;
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 10)
                pr = pr * (p->number);
            p = p->next;
        }
        cout << "������������ = " << pr << endl;
    }
}