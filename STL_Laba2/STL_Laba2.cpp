#include<iostream>
#include<map>
#include<string>
#include<Windows.h>

using namespace std;
void printmap(const map<string, double> humans)
{
	for (const auto& elem : humans) {
		cout << " [" << elem.first << ", " << elem.second << "]" << endl;
	}
	cout << endl;
}
void Menu(map<string, double> humans, multimap<string, double> multihumans)
{
	cout << "------------------------------------------\n";
	cout << "1.Добавить элемент\n";
	cout << "2.Удалить элементы из заданного диапазона\n";
	cout << "3.Поиск первого элемента меньшего заданного ключа\n";
	cout << "4. Скопировать элементы в новый multimap\n";
	cout << "5.Замена значения элемента\n";
	cout << "6.Вывод map на консоль\n";
	cout << "7.Выход из программы\n";
	cout << "------------------------------------------\n";

	char button;
	string name;
	double age;
	double b_age, e_age;
	map<string, double>::const_iterator it_b, it_e;
	multimap<string, double>::const_iterator multi_it;

	bool temp = false;							

	cin >> button;
	do
	{
		switch (button)
		{
		case '1':
			cout << "Введите имя человека:\t";	cin >> name;
			cout << "Введите возраст:\t";		cin >> age;
			typedef pair<string, double> mypair;
			humans.insert(mypair(name, age));			

			printmap(humans);
			cin >> button;
			break;

		case '2':
			cout << "Введите диапазон номеров пар, которые хотите удалить:\n";
			cout << "От ";		cin >> b_age;
			cout << "до ";		cin >> e_age;
			it_b = humans.begin();
			advance(it_b, b_age - 1);
			it_e = humans.begin();
			advance(it_e, e_age);
			humans.erase(it_b, it_e);

			cin >> button;
			break;

		case '3':
			cout << "Введите имя:\t";		cin >> name;
			for (const auto& elem : humans) {
				if (elem.first < name)
				{
					cout << "Найден элемент, который меньше " << name << ":\t\t[" << elem.first << "," << elem.second << "]\n";
					temp = true;
					break;
				}
				else
				{
					temp == false;
				}
			}
			if (temp == false)
			{
				cout << "Элемент не найден.\n";
			}

			cin >> button;
			break;

		case '4':
			cout << "Копирование элементов map в новый multimap....\n";
			multihumans.clear();

			for (const auto& elem : humans)
			{
				typedef pair<string, double> mypair;
				name = elem.first;
				age = elem.second;
				multihumans.insert(mypair(name, age));
			}
			cout << "Новый multimap:\n";
			for (const auto& elem : multihumans) {
				cout << " [" << elem.first << ", " << elem.second << "]" << endl;
			}
			cout << endl;

			cin >> button;
			break;

		case '5':
			cout << "Введите ключ элемента, значение которого хотите изменить:\t";		cin >> name;
			if (humans.count(name))
			{
				cout << "\nВведите новое значение:\t";		cin >> age;
				humans[name] = age;
			}
			else
			{
				cout << "Элемент с заданным ключом не найден\n";
			}

			cin >> button;
			break;

		case '6':
			printmap(humans);
			cin >> button;
			break;

		case '7':
			cout << "Выход из программы";
			break;

		default:
			cout << "Неккоректный ввод.\n";
			cin >> button;
			break;

		}

	} while (button != '7');
}
int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	typedef pair<string, double> mypair;
	map<string, double> humans
	{
		mypair("Kirill", 18),
		mypair("Vladislav", 23),
		mypair("Vlada", 35),
		mypair("B", 10),
		mypair("A", 34),
	};
	multimap<string, double> multihumans;
	printmap(humans);
	Menu(humans, multihumans);
	return 0;
}