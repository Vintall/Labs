#include <iostream>
using namespace std;

void NLO(string text) // Next Line Out
{
	cout << endl << text;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная робота №6 (Вариант №8)";
	int* a; 
	int* b; 
	int* c;
	NLO("Введите кол-во элементов первого вектора = "); 
	int n; cin >> n;
	a = new int[n];
	NLO("Введите первый вектор (По одному элементу за раз)"); cout << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; 
		cout << endl;
	}

	NLO("Введите кол-во элементов второго вектора = ");
	int m; cin >> m;

	if (n <= 0 && m <= 0)
	{
		NLO("Вы ввели пустые вектора");
		return 0;
	}

	b = new int[m];

	NLO("Введите второй вектор (По одному элементу за раз)"); cout << endl;


	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		cout << endl;
	}
	int c_l;
	int condition = -1;
	if (n > m)
	{
		c = new int[m];
		c_l = m;
	}
	else 
	{
		c = new int[n];
		c_l = n;
	}

	int max_a_b;
	if (n > 0)
		max_a_b = a[0];
	else if (m > 0) 
		max_a_b = a[m];

	for (int i = 0; i < m; i++)
		if (a[i] > max_a_b)
			max_a_b = a[i];
	for (int i = 0; i < n; i++)
		if (b[i] > max_a_b)
			max_a_b = b[i];
	
	for (int i = 1; i < m; i++)
		if ((a[i] - a[i - i] > max_a_b) || (a[i - 1] - a[i] > max_a_b))
			condition = 1;
		else condition = 2;
	for (int i = 1; i < n; i++)
		if ((b[i] - b[i - i] > max_a_b) || (b[i - 1] - b[i] > max_a_b))
			condition = 1;
		else condition = 2;
	
	if (condition == 2)
	{
		for (int i = 0; i < c_l; i++)
		{
			c[i] = a[i] + b[i];
		}
	}
	else if (condition == 1)
	{
		if (max_a_b <= n && max_a_b <= m)
		{
			c = new int[max_a_b];
			for (int i = 0; i < max_a_b; i++)
				c[i] = 0;
		}
		else
		{
			int a_zero = 0;
			int b_zero = 0;
			for (int i = 0; i < n; i++)
				if (a[i] == 0) a_zero++;
			for (int i = 0; i < m; i++)
				if (b[i] == 0)b_zero++;

			if (a_zero > b_zero)
				c = new int[a_zero];
			else c = new int[b_zero];
		}
	}
	int dob_a = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			for (int j = i + 1; j < n; j++)
				if (a[j] != 0)
					dob_a *= a[j];
				else break;
			break;
		}
	}
	
	while (1)
	{
		for (int i = 1; i < m; i++)
		{
			if (b[i] - b[i - 1] == -1 * b[i - 1])
			{
				int q = b[i];
				b[i] = b[i - 1];
				b[i - 1] = q;
			}
		}
		int ind = -1;
		for (int i = 1; i < m; i++)
		{
			if (b[i] == 0 && b[i-1] == 0) ind = i+1;
		}
		bool end = true;
		for (int i = ind; i < m; i++)
		{
			if (b[i] == 0) end = false;
		}
		if (end) break;
	}
	NLO("Добуток элементов между первым и вторым нулевым элементом вектора А = "); cout << dob_a;
	cout << endl << endl;
	NLO("Изменённый вектор B = ");
	for (int i = 0; i < m; i++)
		cout << b[i] << endl;
	


	return 0;
}