#include "stack.h"

int main()
{
	setlocale(LC_ALL, "rus");
	comp* top = NULL;
	bool work = true;
	float n;
	float m;
	while (work)
	{
		switch (menu()) {

		case 0:
			work = false;
			break;
		case 1:
			cout << "¬ведите число: ";
			cin >> n;
			push(&top, n);
			break;
		case 2:
			cout << "¬ведите число, которое нужно удалить: ";
			cin >> n;
			delete_key(&top, n);
			break;
		case 3:
			print(top);
			break;
		case 4:
			cout << "¬ведите начало диапазона поиска: ";
			cin >> n;
			cout << "¬ведите конец диапазона поиска: ";
			cin >> m;
			find(top, n, m);
			break;
		case 5:
			toFile(top);
			break;
		case 6:
			fromFile(&top);
			break;
		case 7:
			clear(&top);
			break;
		}
		
	}
	return 0;
}