#include <iostream>

using namespace std;
int Menu();
int FillArr();
int Task8();

char arr[200];
int arr_len = -1;

int Menu()
{
	cout << "1) Ввести массив символов (<200)" << endl;
	cout << "2) Вывод по заданию (8 вариант)" << endl;
	cout << "Введите номер пункта, к которому желаете перейти - ";
	int n; cin >> n; cout << endl;

	switch (n)
	{
	case 0:
		return -1;
		break;
	case 1:
		FillArr();
		system("Pause");
		break;
	case 2:
		Task8();
		system("Pause");
		break;
	default:
		break;
	}
	return 0;
}
int FillArr()
{
	system("cls");
	cout << "Введите строку (<200) символов" << endl;
	//cin >> arr; 
	cin.ignore();
	cin.getline(arr, 200);
	arr_len = strlen(arr);
	return 0;
}
int Task8()
{
	system("cls");
	if (arr_len < 0)
		return -1;

	cout << arr << endl << endl;

	char first_ch = arr[0];

	for (int i = 2; i < arr_len; i++)
	{
		if (arr[i - 1] == ' ')
		{
			if (arr[i] == first_ch)
			{
				for (int j = i; j < arr_len; j++)
				{
					if (arr[j] != ' ')
					{
						cout << arr[j];
						arr[j] = ' ';
					}
					else
					{
						i = j-1;
						break;
					}
				}
				cout << endl;
			}
		}
	}

	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu_sw = 0;
	while (menu_sw != -1)
		Menu();
	return 0;
}

//8. Вивести на екран слова, які починаються з тієї ж літери, що й перше слово речення. Надрукувати строку після вилучення цих слів. 