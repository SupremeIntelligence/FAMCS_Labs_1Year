#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	double exp, x, x1;
	double numerator = 3.0;
	double denominator = 1.0;
	double sum = 1.0;
	int k;
	x1 = 1.0;
	cout << "Введите х из диапазона (-1;1):" << endl;
	cin >> x;
	while (abs(x) >= 1)
	{
		cout << "Неверное значение х." << endl << "Введите х: ";
		cin >> x;
	}
	cout << "Введите k:" << endl;
	cin >> k;
	exp = pow(10, -k);
	while (abs(x1) > exp)
	{
		x1 *= (-1) * numerator * x / denominator;
		numerator++;
		denominator++;
		sum += x1;
	}
	double rez1 = sum;
	cout << "Значение, вычисленное через ряд Тейлора:" << endl << setprecision(16) << rez1 << endl;
	double rez2 = 1.0 / (pow((1 + x), 3));
	cout << "Значение, вычисленное через стандартную функцию:" << endl << setprecision(16) << rez2 << endl;
	if (rez1 > rez2)
		cout << "Значение бесконечного ряда больше значения стандартной функции";
	else
		cout << "Значение стандартной функции больше значения бесконечного ряда";
}