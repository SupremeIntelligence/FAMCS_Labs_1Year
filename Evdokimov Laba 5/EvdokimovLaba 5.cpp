// EvdokimovLaba 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int M, N;
	cout << "Введите размерность матрицы M*N: " << endl;  //M - строки, N - столбцы
	cin >> M >> N;
	if (M <= 0 || N <= 0)
	{
		cout << "Неверные входные данные";
		return 0;
	}
		
	int** mtrx = new int* [M];
	int** mtrx2 = new int* [N];
	for (int i = 0; i < M; i++)
	{
		mtrx[i] = new int [N];
		
	}
	for (int i = 0; i < N; i++)
	{
		mtrx2[i] = new int [M];
	}
	
	srand(time(NULL));
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			mtrx[i][j] = 32 + rand() % 223;
		}
	}

	cout << "\t\tИсходная матрица:" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char symbol = (char)mtrx[i][j];
			printf("%1.5c ", symbol);
		}
		printf("\n");
	}
	
	int i = M - 1;
	int j = 0;
	for (int r = 0; r < N; r++)
	{
		for (int s = 0; s < M; s++)
		{
			mtrx2[r][s] = mtrx[i][j];
			i--;
		}
		j++;
		i = M - 1;
	}
	
	cout <<endl<< "\t\tMатрица, повернутая на 90 градусов по часовой стрелке:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char symbol = (char)mtrx2[i][j];
			printf("%1.5c ", symbol);
		}
		printf("\n");
	}


	//очистка памяти
	for (int i = 0; i < M; i++) 
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
	for (int i = 0; i < N; i++)
	{
		delete[] mtrx2[i];
	}
	delete[] mtrx2;

	return 0;
}

