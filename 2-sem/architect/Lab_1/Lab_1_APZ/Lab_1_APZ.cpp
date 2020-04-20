#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

const int n = 3;
int a[n][n];
int b[n];
int c[n];
int main()
{
	srand(time(0));
		cout << "N = " << n << endl;

	//for (int g = 1000; g <= n; g += 1000)
	//{
		int g = 3;
		cout << "True Matrix Size = " << g << endl;

		double clock1, clock2;
		clock1 = clock();
		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < g; j++)
				a[i][j] = rand() % 10 + 1;
			b[i] = rand() % 10 + 1;
		}
		clock2 = clock();
		cout << "Pulling time: " << (clock2 - clock1) / 1000 << endl;
		clock1 = clock();
		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < g; j++)
			{
				c[i] += a[i][j] * b[j];
			}
		}
		clock2 = clock();

		double res = (clock2 - clock1) / 1000;
		cout << "Matrix * VEC: " << res << endl;
		for (int i = 0; i < g; i++)
			c[i] = 0;

		clock1 = clock();

		for (int i = 0; i < g; i++)
			for (int j = 0; j < g; j++)
				c[i] += b[j] * a[j][i];
		clock2 = clock();

		res = (clock2 - clock1) / 1000;
		cout << "VEC * Matrix: " << res << endl;
		for (int i = 0; i < g; i++)
			c[i] = 0;

		clock1 = clock();
		for (int i = 0; i < g; i++)
			for (int j = 0; j < g; j++)
				c[j] += b[i] * a[i][j];

		clock2 = clock();

		res = (clock2 - clock1) / 1000;
		cout << "VEC * Matrix(Optimisation): " << res << endl;

		cout << endl << endl << endl;
	//}
	return 0;
}