#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y;
	int k;
	cout << "Введите x(x>0)=";
	cin >> x; cout << endl;
	cout << "Введите y(y>1)=";
	cin >> y; cout << endl;
	if (x > 0 && y > 1)
	{
		k = log10(x) / log10(y) + 0.5;
		cout << "k=" << k << endl;
		cout << "y^k-1 <= x < y^k" << endl;
		cout << "y^" << k - 1 << "<= x < y^" << k << endl;
		system("pause");
	}
	else
	{
		cout << "Ошибка ввода!!!" << endl << endl << endl << endl;
		main();
	}
}