// Evdokimov Laba 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int dimensions;

	while (true)
	{
		try 
		{
			cout << "Введите количество координат: ";
			cin >> dimensions;
			if (dimensions <= 0)
			{
				throw 0;
			}
			break;
		}
		catch (int a)
		{
			cerr << "\nВВЕДИТЕ ПОЛОЖИТЕЛЬНОЕ ЗНАЧЕНИЕ\t";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	

	Point p1(dimensions); 
	cout << "\nВведите координаты точки: ";
	cin >> p1;
	cout << p1;

	Point p2(dimensions);
	cout << "\nВведите координаты второй точки: ";
	cin >> p2;
	cout << p2;

	cout << "\nРавны ли координаты двух точек через '!=' : ";
	if (p1 != p2) cout << "Не равны";
	else cout << "Равны";

	cout << "\nРавны ли координаты двух точек через '==' : ";
	if (p1 == p2) cout << "Равны";
	else cout << "Не равны";

	cout << "\nСравнение координат двух точек: ";
	if (p1 >= p2) cout << "Координаты первой точки больше или равны";
	else cout << "Координаты первой точки меньше";
	cout << "\nСложение координат двух точек:\n" << p1 + p2;
	cout << "\nВычитание координат двух точек:\n" << p1 - p2;
	cout << "\nУмножение координат двух точек:\n" << p1 * p2;
	int mltr;
	try
	{
		
		cout << "\n\tВведите множитель и делитель координат: ";
		cin >> mltr;
		if (mltr == 0) throw mltr;
		cout << "\nДеление координат первой точки на " << mltr << ": \n" << p1 / mltr;
	}
	catch (int mltr)
	{
		cerr << "ДЕЛЕНИЕ НА НОЛЬ!";
	}
	cout << "\nУмножение координат первой точки на " << mltr <<": \n" << p1 * mltr;
	
	cout << "\nПостфиксный оператор инкрементирования первой точки:\n" << p1++;
	cout << "\nПрефиксный оператор инкрементирования первой точки:\n" << ++p1;
	cout << "\nПостфиксный оператор декрементирования первой точки:\n" << p1--;
	cout << "\nПрефиксный оператор декрементирования первой точки:\n" << --p1;
	cout << "\n\tВведите номер координаты первой точки:\n";
	try
	{
		int i; cin >> i;
		if (i < 1 || i > dimensions) throw "НЕВЕРНЫЙ ИНДЕКС КООРДИНАТЫ";
		cout << "\n" << i << "-я координата первой точки : \n" << p1[i - 1];
	}
	catch (const char* exception)
	{
		cerr << exception;
	}
	cout << "\nПобитовое инвертирование первой точки:\n" << ~p1;
}

