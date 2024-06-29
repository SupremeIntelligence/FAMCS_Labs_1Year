
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<list>
#include<iterator>

using namespace std;

void Menu(list<double>mylist)
{
	cout << "---------------------------------------------------------- \n";
	cout << "1.Просмотреть состояние списка\n" << "2.Добавить элемент в заданную позицию\n" << "3.Удалить элемент в заданной позиции\n";
	cout << "4.Изменить размер списка\n" << "5.Увеличить все элементы на Х, использовать алгоритм(transform).\n";
	cout << "6.Удалить элементы по условию(remove_if)\n" << "7.Выход из программы\n";
	cout << "---------------------------------------------------------- \n";
	int button;
	size_t pos, new_size;
	double value;
	list<double>::iterator itr;
	ostream_iterator<double> itr_out(cout, "\n");
	cin >> button;
	do {

		switch (button)
		{
		case 1:
			cout << "Состояние списка:\n";
			copy(mylist.begin(), mylist.end(), itr_out);
			cin >> button;
			break;

		case 2:
			cout << "Введите элемент и позицию:\t";
			cin >> value >> pos;
			if (pos > mylist.size())
			{
				cout << "Неверное указание позиции.\n";
				cin >> button;
				break;
			}
			itr = mylist.begin();
			advance(itr, pos);
			mylist.insert(itr, value);
			cin >> button;
			break;

		case 3:
			cout << "Введите позицию элемента, который хотите удалить:\t";
			cin >> pos;
			if (pos > mylist.size())
			{
				cout << "Неверное указание позиции.\n";
				cin >> button;
				break;
			}
			itr = mylist.begin();
			advance(itr, pos);
			mylist.erase(itr);
			cin >> button;
			break;

		case 4:
			cout << "Введите новый размер списка: \t";
			cin >> new_size;
			if (new_size < mylist.size())		mylist.resize(new_size);
			else								mylist.resize(new_size, 0.00);

			cin >> button;
			break;

		case 5:
			cout << "Введите число, на которое хотите увеличить все элементы списка: \t";
			cin >> value;
			transform(mylist.begin(), mylist.end(), mylist.begin(), [value](double x) {return x + value;});
			cin >> button;
			break;

		case 6:
			cout << "Введите значение элемента, который хотите удалить:\t";
			cin >> value;
			mylist.remove_if([value](double x) {return x == value;});
			cin >> button;
			break;

		case 7:
			
			cout << "Выход из программы";
			break;

		default:
			cout << "Некорректный ввод\n";
			cin >> button;
			break;
		}
	} while (button != 7);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	list<double> mylist{ 1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99 };
	Menu(mylist);
	return 0;
}