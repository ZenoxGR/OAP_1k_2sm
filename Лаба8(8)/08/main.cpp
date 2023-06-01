#include <iostream>
#include "modules.h"
using namespace std;



Item* head = nullptr;
Item* tail = nullptr;


int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice = 1, x;
    while (choice != 0) {
        cout << "1 - �������� �������" << endl;
        cout << "2 - �������� ������� � ������" << endl;
        cout << "3 - ������� ������� � ������" << endl;
        cout << "4 - ������� ��������" << endl;
        cout << "5 - �������� �������" << endl;
        cout << "6 - ������� �� �������" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� ��������  ";
        cin >> choice;
        switch (choice) {
        
        case 1:
            
            int n;
            cout << "������� ���������� ���������: ";
            cin >> n;

            cout << "������� �������� �������:" << endl;
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
