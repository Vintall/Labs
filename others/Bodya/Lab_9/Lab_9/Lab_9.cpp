#include <iostream>
#include <ctime>

using namespace std;
//variant-20
int FillMassSize();
int FillMass();
void ShowMass();
int MassSum();

int x[10], y[12], z[8];
int n, m, k;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	cout << "Введите размеры массивов:" << endl;
	while (FillMassSize() == -1);
	while (FillMass() == -1);
	ShowMass();
	cout << endl << "Сумма элементов = " << MassSum();
}

int FillMassSize()
{
	cout << "N (0, 10) - "; cin >> n; cout << endl;
	if (!(n > 0 && n < 10))
	{
		cout << "Ошибка ввода" << endl;
		system("Pause");
		return -1;
	}
	cout << "M (0, 12) - "; cin >> m; cout << endl;
	if (!(m > 0 && m < 12))
	{
		cout << "Ошибка ввода" << endl;
		system("Pause");
		return -1;
	}
	cout << "K (0, 8) - "; cin >> k; cout << endl;
	if (!(k > 0 && k < 12)) 
	{
		cout << "Ошибка ввода" << endl;
		system("Pause");
		return -1;
	}
	return 1;
	system("cls");
}
int FillMass()
{
	int a, b;
	cout << "Введите границы элементов массивов [a, b] " << endl;
	cout << "Введите а - "; cin >> a; cout << endl;
	cout << "Введите b - "; cin >> b; cout << endl;
	if (a > b) //swap(a, b);
	{
		int buff = a;
		a = b;
		b = buff;
	}
	for (int i = 0; i < n; i++)
		x[i] = rand() % (b - a) + a;
	for (int i = 0; i < m; i++)
		y[i] = rand() % (b - a) + a;
	for (int i = 0; i < k; i++)
		z[i] = rand() % (b - a) + a;
	return 1;
}
int MassSum()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (x[i] > 0)
			sum += x[i];
	for (int i = 0; i < m; i++)
		if (y[i] > 0)
			sum += y[i];
	for (int i = 0; i < k; i++)
		if (z[i] > 0)
			sum += z[i];
	return sum;
}
void ShowMass()
{
	cout << "Массив X:" << endl;

	for (int i = 0; i < n; i++)
		cout << x[i] << endl;

	cout << endl << "Массив Y:" << endl;

	for (int i = 0; i < m; i++)
		cout << y[i] << endl;

	cout << endl << "Массив Z:" << endl;

	for (int i = 0; i < k; i++)
		cout << z[i] << endl;

}