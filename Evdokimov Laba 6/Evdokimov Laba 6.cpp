
#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

bool UniqueSubstringSearch(char* mas1, char** mas2, int size2)
{
	bool result = true;
	for (int i = 0; i < size2; i++)
	{
		if (strstr(mas1, mas2[i]) != nullptr)
		{
			result = false;
			break;
		}
	}
	return result;
}

void insertionSort(string& str)
{
	int size = str.length();
	for (int i = 0; i <= size; i++)
	{
		char temp = str[i];
		int j = i - 1;
		while (j >= 0 && str[j] > temp)
		{
			str[j + 1] = str[j];
			j = j - 1;
		}
		str[j + 1] = temp;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	string line1, line2, line3;
	ifstream input("Input.txt");
	ofstream output("Output.txt");

	//берем данные из файла
	getline(input, line1);
	getline(input, line2);
	getline(input, line3);
	if (!input.is_open())
	{
		cout << "Входной файл не открыт\n";
		return 0;
	}

	//создаем чар строки 
	char* ch_line1 = new char[line1.length() + 1];
	strcpy(ch_line1, line1.c_str());

	char* ch_line2 = new char[line2.length() + 1];
	strcpy(ch_line2, line2.c_str());

	char* ch_line3 = new char[line3.length() + 1];
	strcpy(ch_line3, line3.c_str());

	output << ch_line1 << endl;
	output << ch_line2 << endl;
	output << ch_line3 << endl;

	output << "\tПолученные лексемы:\n";
	//выделение лексем и их занесение в массив строк
	const int max_tokens = 100;
	int counter1 = 0;
	int counter2 = 0;
	char* ch_strings1[max_tokens];
	char* ch_strings2[max_tokens];

	char* token1 = strtok(ch_line1, ch_line3);
	while (token1 != nullptr && counter1 < max_tokens)
	{
		ch_strings1[counter1] = new char[strlen(token1) + 1];
		strcpy(ch_strings1[counter1], token1);
		output << "\t" << token1;
		token1 = strtok(nullptr, ch_line3);
		counter1++;
	}
	cout << endl;

	char* token2 = strtok(ch_line2, ch_line3);
	while (token2 != nullptr && counter2 < max_tokens)
	{
		ch_strings2[counter2] = new char[strlen(token2) + 1];
		strcpy(ch_strings2[counter2], token2);
		output << "\t" << token2;
		token2 = strtok(nullptr, ch_line3);
		counter2++;

	}

	//создание строки с уникальными лексемами из первой строки
	char* unique_tokens[max_tokens];
	int counter3 = 0;
	for (int i = 0; i < counter1; i++)
	{
		for (int j = 0; j < counter2; j++)
		{
			if (UniqueSubstringSearch(ch_strings1[i], ch_strings2, counter2) == true && UniqueSubstringSearch(ch_strings1[i], unique_tokens, counter3) == true)
			{
				unique_tokens[counter3] = new char[strlen(ch_strings1[i]) + 1];
				strcpy(unique_tokens[counter3], ch_strings1[i]);
				counter3++;
			}
		}
	}

	output << "\n\nЛексемы, встречающиеся только в первой строке:\n";
	for (int i = 0; i < counter3; i++)
	{
		output << "\t\t" << unique_tokens[i];
	}

	//определений чисел в 10 с\с в строке с уникальными лексемами
	output << "\n\tЧисла в десятичной с/с:\n";
	for (int i = 0; i < counter3; i++)
	{
		for (int j = 0; j <= strlen(unique_tokens[i]); j++)
		{
			if (isdigit(unique_tokens[i][j]) != 0)
			{
				output << unique_tokens[i][j];
			}
			else
				output << ' ';
		}
	}
	//преобразование 1-й и 2-й строки в string
	string string1, string2;
	for (int i = 0; i < counter1; i++)
	{
		string1.append(ch_strings1[i]);
		string1 += '  ';
	}

	for (int i = 0; i < counter2; i++)
	{
		string2 = string2 + ch_strings2[i] + ' ';
	}

	output << "\n\n\tПервая строка:\n\t" << string1;
	output << "\n\n\tВторая строка:\n\t" << string2;

	//сортировка строки вставками
	insertionSort(string2);

	output << "\n\n\tВторая строка, отсортированная методом вставок:\n" << string2;

	//замена любого числа в строке string на введенное число
	cout << "\n\nВведите число N, на которое хотите заменить число в строке:\t";
	int N;
	cin >> N;
	size_t found = string1.find_first_of("0123456789");
	while (found != string::npos)
	{
		size_t endFound = string1.find_first_not_of("0123456789", found);
		string1.replace(found, endFound - found, to_string(N));
		found = string1.find_first_of("0123456789", endFound);
	}
	output << "\nСтрока с заменными числами на введенное:\t" << string1;

	//Дублирование любой строки типа String
	output << "\nДублирование первой лексемы в первой строке типа String:\t" << string1.substr(0, string1.find(" ", 0));

	//Удаление второго числа
	output << "\n\nВторая строка:\t" << string1;
	int ind_b = 1 + string1.find_first_of("0123456789", 0); //начало первого числа
	ind_b = string1.find_first_not_of("0123456789", ind_b);//начало чего-то между первым и вторым
	ind_b = string1.find_first_of("0123456789", ind_b);//начало второго числа
	int ind_e = string1.find_first_not_of("0123456789", ind_b) - 1;
	output << "\nПервая строка с удаленным вторым числом: \t";
	string1 = string1.erase(ind_b, ind_e);
	output << string1 << endl;

	//освобождение памяти
	for (int i = 0; i < counter1; i++)
	{
		delete[] ch_strings1[i];
	}
	for (int i = 0; i < counter2; i++)
	{
		delete[] ch_strings2[i];
	}
	for (int i = 0; i < counter3; i++)
	{
		delete[] unique_tokens[i];
	}

	delete[] ch_line2;
	delete[] ch_line1;
	delete[] ch_line3;

	return 0;
}

