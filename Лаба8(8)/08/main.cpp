#include <iostream>
#include "modules.h"
using namespace std;



Item* head = nullptr;
Item* tail = nullptr;


int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice = 1, x;
    while (choice != 0) {
        cout << "1 - добавить элемент" << endl;
        cout << "2 - получить элемент с начала" << endl;
        cout << "3 - извлечь элемент с начала" << endl;
        cout << "4 - вывести элементы" << endl;
        cout << "5 - очистить очередь" << endl;
        cout << "6 - функция по заданию" << endl;
        cout << "0 - выход" << endl;
        cout << "Выберите действие  ";
        cin >> choice;
        switch (choice) {
        
        case 1:
            
            int n;
            cout << "Введите количество элементов: ";
            cin >> n;

            cout << "Введите элементы очереди:" << endl;
            for (int i = 0; i < n; ++i) {
                cin >> x;
                insertToQueue(x, PriorityMode::MIN_LIFO);
            }
            break;
        case 2:
            getFromHead();
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            printQueue();
            break;
        case 5:
            clrQueue();
            break;
        case 6: 
            deleteFirstNegative();
            break;

        }
    }
    return 0;
}
