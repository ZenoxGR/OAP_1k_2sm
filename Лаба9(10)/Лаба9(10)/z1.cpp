#include <iostream>

using namespace std;


int fun(int m, int n){
	if (n == 0 || m == 0) {
		return n + 1;
	}
	else {
		return fun(m - 1, fun(m, n - 1));
	}
}


//float fun2(double x, int n)
//{
//	if (n == 1)
//		return cos(x);
//	else
//		return fun2(x, n - 1) + cos(n * x);
//}


int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Введите m" << endl;
	cin >> m;
	cout << "Введите n" << endl;
	cin >> n;
	cout << "В итоге n = " << fun(m, n) << endl;

	/*float Y = 0;
	float x = 0;
	int N = 0;
	cout << "Введите х " << endl;
	cin >> x;
	cout << "Введите N " << endl;
	cin >> N;
	Y = fun2(x, N);
	cout << "Y = " << Y;*/
}