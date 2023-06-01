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
//        cout << endl << "1. Добавление эл-ов" << endl;
//        cout << "2. Удаление эл-ов" << endl;
//        cout << "3. Поиск эл-ов" << endl;
//        cout << "4. Вывод списка в консоль" << endl;
//        cout << "5. Запись списка в файл" << endl;
//        cout << "6. Чтение списка из файла" << endl;
//        cout << "7. Умножение эл-ов" << endl;
//        cout << "8. Выход" << endl;
//        cout << "Ваш выбор: ";
//        cin >> choice;
//        switch (choice) {
//        case 1:
//            cout << "Введите число для добавления в список: ";
//            cin >> num;
//            myList.push_back(num);
//            break;
//        case 2:
//            cout << "Введите число для удаления из списка: ";
//            cin >> num;
//            myList.remove(num);
//            break;
//        case 3:
//            cout << "Введите число для поиска: ";
//            cin >> num;
//            if (find(myList.begin(), myList.end(), num) != myList.end()) {
//                cout << "Число найдено" << endl;
//            }
//            else {
//                cout << "Число не найдено" << endl;
//            }
//            break;
//        case 4:
//            printList(myList);
//            break;
//        case 5:
//            cout << "Введите имя файла: ";
//            cin >> fileName;
//            saveListToFile(myList, fileName);
//            break;
//        case 6:
//            cout << "Введите имя файла: ";
//            cin >> fileName;
//            myList = readListFromFile(fileName);
//            printList(myList);
//            break;
//        case 7:
//            cout << "Произведение чисел, которые меньше 10: " << multiplyLessThan10(myList);
//            break;
//        case 8:
//            cout << "Выход ...";
//            break;
//        default:
//            cout << "Неверный выбор" << endl;
//            break;
//        }
//    } while (choice != 8);
//    return 0;
//}
//void printList(list<double> myList) {
//    cout << "Список: ";
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
//    cout << "Список записан " << fileName << endl;
//}
//list<double> readListFromFile(string fileName) {
//    list<double> myList;
//    ifstream inputFile;
//    inputFile.open(fileName.c_str());
//    if (!inputFile.is_open()) {
//        cout << "Не удается открыть файл " << fileName << endl;
//        return myList;
//    }
//    double num;
//    while (inputFile >> num) {
//        myList.push_back(num);
//    }
//    inputFile.close();
//    cout << "Список прочитан " << fileName << endl;
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
    cout << "Выберите вариант: ";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:    cout << "Введите число ";
            cin >> value;
            insert(first, value);
            break;   
        case 2:printList(first);
            break;
        case 3: proiz(first);
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "Выберите вариант: " << endl;
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Вывод списка" << endl;
    cout << " 3 - Нахождение произведения чисел меньше 10" << endl;
    cout << " 4 - Выход" << endl;
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
        cout << "Операция добавления не выполнена" << endl;
}

void printList(list* p)
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
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
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 10)
                pr = pr * (p->number);
            p = p->next;
        }
        cout << "Произведение = " << pr << endl;
    }
}