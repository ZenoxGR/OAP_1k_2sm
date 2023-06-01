#include <iostream>
#include <windows.h>
#include<conio.h>  
using namespace std;
#define max 100
struct Tree          //������
{
	int key;         //����
	int number;    //����� - �� ����� 4 ����
	Tree* left, * right;
};
Tree* Root = NULL;
int sum = 0;
int d = 0;
Tree* makeTree(Tree* Root, int& left, int& right);       //�������� ������
Tree* list(int i, int s);       //�������� ������ ��������
Tree* insertElem(Tree* Root, int key, int s, int& left, int& right);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
int count(Tree* t, int k);  //������� ���������� ����
void delAll(Tree* t);//������� ������

int wrtreelast1(Tree* t);
void wrtree(Tree* t);
void wrtree1(Tree* t);
void wrtree2(Tree* t);
int Depth(Tree* t);
bool IsBalanced(Tree* t);

void main()
{
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int key, choice, left_count = 0, right_count = 0;
	Tree* rc; int s, letter, k = 0;
	for (;;)
	{
		cout << "\n1 -	�������� ������\n";
		cout << "2 -	���������� ��������\n";
		cout << "3 -	����� �� �����\n";
		cout << "4 -	�������� ��������\n";
		cout << "5 -	����� ������\n";
		cout << "6 -	���������� ������ � ����������� ���������\n";
		cout << "7 -	������� ������\n";
		cout << "8 -	�������� ������������������ ������\n";
		cout << "9 -	����� ������ ����� ������\n";
		cout << "10 -	������ �����\n";
		cout << "11 -	������������ �����\n";
		cout << "12 -	�������� �����\n";
		cout << "13 -	�����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root, left_count, right_count);	break;
		case 2:  cout << "\n������� ����: "; cin >> key;
			cout << "������� �����: "; cin >> s;
			insertElem(Root, key, s, left_count, right_count); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			if (rc != NULL)
			{
				cout << "��������� �����= ";
				cout << rc->number << endl;
			}break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root != NULL)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 6:
			sum = 0;
			cout << "������� �������� k:"; cin >> k;
			count(Root, k);
			cout << "\n��������� ����� �� ��������� k = " << sum << endl; break;
		case 7:  delAll(Root); Root = NULL; break;
		case 8:  if (IsBalanced(Root) != 1)
			cout << "��� ���������������� ������" << endl;
			  else cout << "��� �� ���������������� ������" << endl; break;
		case 9:  cout << "���������� ����� ������ ����� ������: " << wrtreelast1(Root) - 1; break;
		case 10:  wrtree(Root); break;
		case 11:  wrtree1(Root); break;
		case 12:  wrtree2(Root); break;
		case 13:  exit(0);
		}

	}
}
Tree* makeTree(Tree* Root, int& left, int& right)    //�������� ������
{
	int key; int s;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> s;
		Root = list(key, s);	// ��������� ��������� �� ������
	}
	while (1)                //���������� ���������
	{
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) break;       //������� ������ (���� < 0)   
		cout << "������� �����: ";  cin >> s;
		insertElem(Root, key, s, left, right);
	}
	return Root;
}
Tree* list(int i, int s)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->number = s;
	t->left = t->right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key, int s, int& left, int& right)  //���������� ������ ��������
{
	Tree* Prev = NULL;	     // Prev - ������� ����� �������
	int find = 0;  // ������� ������  
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //����� ������ ���� ���������
		else
			if (key < t->key) t = t->left;
			else t = t->right;
	}

	if (!find)
	{
		t = list(key, s);
		if (key < Prev->key)
		{
			Prev->left = t;
			left++;
		}
		else
		{
			Prev->right = t;
			right++;
		}
	}
	return t;
}
Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->right == NULL) // ����� �������� R ��� ������
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R; // �� ����� ����� 
		else
			Prev_Del->right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}
Tree* search(Tree* n, int key)  //����� �������� �� ����� 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < n->key)
			rc = search(n->left, key);
		else
			if (key > n->key)
				rc = search(n->right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}
int count(Tree* t, int k)
{
	if (t == NULL) { return NULL; }
	if (t->right == NULL && t->left == NULL)
	{
		if (t->number == k)
		{
			sum += 1;
		}
		return 1;
	}
	else
	{
		return (count(t->right, k) + count(t->left, k));
	}
}
void view(Tree* t, int level) //����� ������ 
{
	if (t == NULL)return;
	else
	{
		view(t->left, ++level);
		for (int i = 0; i < level; i++)
			cout << "      ";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->number << endl;
		level--;
	}
	view(t->right, ++level);
}
void delAll(Tree* t) //������� ������
{
	if (t != NULL)
	{
		delAll(t->left);
		delAll(t->right);
		delete t;
	}
}



int wrtreelast1(Tree* t)
{

	if (t == NULL) return d;
	d++;
	wrtreelast1(t->left);
	return d;
}
void wrtree(Tree* t) // ������ �����
{
	if (t == NULL) return;
	cout << t->key << '-' << t->number << " ";
	wrtree(t->left);
	wrtree(t->right);

}
void wrtree1(Tree* t)// ������������ �����
{
	if (t == NULL) return;

	wrtree(t->left);
	cout << t->key << '-' << t->number << " ";
	wrtree(t->right);

}
void wrtree2(Tree* t) // �������� �����
{
	if (t == NULL) return;

	wrtree(t->left);
	wrtree(t->right);
	cout << t->key << '-' << t->number << " ";
}
int Depth(Tree* t)
{
	if (t != NULL)
	{
		int A = Depth(t->left);
		int B = Depth(t->right);
		if (A > B) return A + 1;
		else return B + 1;
	}
	else return 0;
}
bool IsBalanced(Tree* t) // �������� ������������������ ������
{
	int l, r;
	if (t == NULL) return true;
	else
	{
		if (IsBalanced(t->left) && IsBalanced(t->right))
		{
			l = Depth(t->left);
			r = Depth(t->right);
			if (l - r == 1 || r - l == 1 || l == r)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}
