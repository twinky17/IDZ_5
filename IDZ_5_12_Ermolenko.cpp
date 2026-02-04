#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	int M;

	cout << "Введите размерность матрицы M (3 <= M <= 10): ";
	cin >> M;

	if (M < 3 || M > 10)
	{
		cout << "Ошибка. Размерность должна быть от 3 до 10.";
		return 1;
	}

	double matrix[10][10];

	cout << "Введите элементы матрицы:" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}
	}

	bool isOrthonormal = true;
	const double eps = 1e-9;

	for (int i = 0; i < M; i++)
	{
		double dot = 0;
		for (int j = 0; j < M; j++)
		{
			dot += matrix[i][j] * matrix[i][j];
		}
		if (fabs(dot - 1.0) > eps)
		{
			isOrthonormal = false;
			break;
		}
	}

	if (isOrthonormal)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = i + 1; j < M; j++)
			{
				double dot = 0;
				for (int k = 0; k < M; k++)
				{
					dot += matrix[i][k] * matrix[j][k];
				}
				if (fabs(dot) > eps)
				{
					isOrthonormal = false;
					break;
				}
			}
			if (!isOrthonormal) break;
		}
	}

	if (isOrthonormal)
	{
		cout << "Матрица ортонормирована." << endl;
	}
	else
	{
		cout << "Матрица не ортонормирована." << endl;
	}

	return 0;
}