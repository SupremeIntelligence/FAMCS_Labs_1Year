// Evdokimov Laba 2 Dop.zadanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;
char operation;
int x, y;
char choose_op()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выберите знак операции (/,%,&,|,^,~,!,<<,>>)" << endl;
	cin >> operation;
	return operation;
}
int second_variable()
{
	cout << "Введите второе число:" << endl;
	cin >> y;
	return y;
}
int calculation()
{
	switch (operation)
	{
	case '/':
		second_variable();
		return x / y;
		break;

	case '%':
		second_variable();
		return x % y;
		break;

	case '&': 
		second_variable();
		return x & y;
		break;

	case '|': 
		second_variable();
		return x | y;
		break;

	case '^': 
		second_variable();
		return x ^ y;
		break;

	case '~': return ~x;
		break;

	case '!': return !x;
		break;

	case '>>':
		second_variable();
		return x >> y;
		break;

	case '<<':
		second_variable();
		return x << y;
		break;
	default: cout << "Ошибка"<<endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char ex = 'E';
	choose_op();
	cout << "Введите первое число: " << endl;
	cin >> x;
	int rez = calculation();
	cout << "Результат в десятеричном виде равен:" << rez << endl;
	cout << "Результат в восьмеричном виде равен:" << oct << rez << endl;
	cout << "Результат в шестнадцатиричном виде равен:" << hex << rez << endl;
	cout << "Нажмите Е, если хотите выйти" << endl;
	cin >> ex;
	if (ex == 'E')
		return 0;
		

}

