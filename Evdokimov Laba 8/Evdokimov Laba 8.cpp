#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
int SearchAmount(int* mas, int size, int element, int count = 0, int index = 0)
{
	if (index == size)
	{
		return count;
	}
	if (element == mas[index])
	{
		++count;
		return SearchAmount(mas, size, element, count, ++index);
	}
	else return SearchAmount(mas, size, element, count, ++index);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	ofstream out ("Output.txt");
	if (!out.is_open())
	{
		cerr<<"Файл вывода не открыт\n";
	}
	int size;
	cout << "Введите размерность массива:\t";
	cin >> size;
	int* mas;
	mas = new int[size];
	srand(time(NULL));
	out << "Массив:\n";
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 100;
		out << mas[i] << "  ";
	}
	int x;
	cout << "\nВведите элемент, количeство повторений которого вы хотите найти:\t";
	out << "\nВведите элемент, количeство повторений которого вы хотите найти:\t";
	cin >> x;

	out << "Количество повторений элемента " << x << ":\t" << SearchAmount(mas, size, x);
}
