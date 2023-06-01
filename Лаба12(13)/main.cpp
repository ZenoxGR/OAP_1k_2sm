#include "Heap.h"//�������� �������������, �������� i-�� � ����������� ���� ���
#include <iostream>
#include <fstream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  // ������� ��������� 2� ��������� ���� ���
{
#define A1 ((AAA*)a1) 
#define A2 ((AAA*)a2)

    heap::CMP  rc = heap::EQUAL;     // ��������� ���������� ���� CMP, �� ���� ��������� ��������� ���� �������� (=���� ��������� ����)
    if (A1->x > A2->x)             // ���� �������� ������� �������� ������ �������� �������
        rc = heap::GREAT;             // ���������� � ����������, ��� ������ ������� ������ �������
    else
        if (A2->x > A1->x)         // ���� ������ ������� ������ ������� 
            rc = heap::LESS;      // ���������� � ����������, ��� ������ ������� ������ �������
    return rc;              //  ���������� �������� ����������
#undef A2  
#undef A1  
}
bool BuildHeap(char* FileName, heap::Heap& h)  // ���������� ���� �� �����, char *FileName - ��� �����, heap::Heap& h - ����, �� ������� ������ ���������
{
    bool rc = true;
    int n;
    ifstream inFile;
    inFile.open(FileName);
    if (!inFile)
    {
        cout << "���������� ������� ����" << endl;
        exit(1);
    }
    cout << "    �������� ������" << endl;
    while (inFile >> n)
    {
        int* a = new int;
        *a = n;  // ������������ ����������� ������� �� ������ � ���������� ������ 
        h.Insert((void*)a);
        cout << *a << endl;
    }
    inFile.close();
    return rc;
}

void SaveHeap(heap::Heap& h, char* FileName)
{
    ofstream  outFile(FileName);
    if (!outFile)
    {
        std::cout << "������ �������� ��������� �����" << std::endl;
        return;
    }
    int* a;
    for (int u = 0; u < h.Size; u++)
    {
        a = (int*)h.Storage[u];
        outFile << *a;
        outFile << endl;
    }
    outFile.close();
}

void main()
{
    setlocale(LC_ALL, "rus");
    char buf[255];
    int k;
    heap::Heap h1 = heap::Create(30, cmpAAA), h2 = heap::Create(30, cmpAAA);

    int choise;
    AAA* a;
    for (;;)
    {
        cout << "1 - ����� ���� �� �����" << endl;
        cout << "2 - ���������� ��������" << endl;
        cout << "3 - �������� �������������" << endl;
        cout << "4 - �������� ����" << endl;
        cout << "5 - ��������� � ����" << endl;
        cout << "6 - ��������� �� �����" << endl;
        cout << "7 - ���������� ������������ ��������" << endl;
        cout << "8 - �������� i-��� ��������" << endl;
        cout << "9 - ����������� ���� ��� � ����" << endl;
        cout << "0 - �����" << endl;
        cout << "��� ���� �������?" << endl;
        cin >> choise;
        switch (choise)
        {
        case 0:  exit(0);
        case 1:  h1.Scan(0);
            break;
        case 2:
            a = new AAA;
            cout << "������� ������� " << endl;
            cin >> k;
            a->x = k;
            h1.Insert(a);
            break;
        case 3:
            a = (AAA*)h1.ExtractMax();

            if (a != NULL)
                cout << "������������ �������: " << a->x << endl;
            else cout << "���� �����." << endl;
            break;
        case 4:   h1.DeleteHeap();
            break;
        case 5:
            cout << "������� ��� �����" << endl;
            cin >> buf;
            SaveHeap(h1, buf);
            break;
        case 6:
            h1.DeleteHeap();
            cout << "������� ��� �����" << endl;
            cin >> buf;
            BuildHeap(buf, h1);
            break;
        case 7:
            a = (AAA*)h1.ExtractMin();

            if (a != NULL)
                cout << "����������� �������: " << a->x << endl;
            else cout << "���� �����." << endl;
            break;
        case 8:
            cout << "������� ����� �������� " << endl;
            cin >> choise;
            a = (AAA*)h1.ExtractI(choise);

            if (a != NULL)
                cout << "����������� �������: " << a->x << endl;
            else cout << "���� �����." << endl;
            break;
        case 9:
            cout << "������� ��� �����" << endl;
            cin >> buf;
            h2.DeleteHeap();
            BuildHeap(buf, h2);
            h1.Union(h2);
            break;
        default:
            cout << endl << "������� �������� �������!"; cout << endl;
        }
    }
}