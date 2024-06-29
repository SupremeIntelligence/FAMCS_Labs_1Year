#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<assert.h>
#include"Header.h"
using namespace std;

void Search(MASSIV<Activists>& obj, ostream& out) //отдельная функция
{
	char activity[50] = "Спорт";
	out << "\n//////// Поиск студентов активных в спорте ////////\n";
	for (int i = 0; i < obj.getSize(); i++)
	{
		if (strcmp(obj[i].Space, activity) == 0)
		{
			out << obj[i] << endl;
		}
	}
}

int Compare(const void* a, const void* b)
{
	const Activists* A = (const Activists*) a;
	const Activists* B = (const Activists*) b;
	return strcmp(A->Space, B->Space);
}

void SpaceSort(MASSIV<Activists>& obj) //дружественная функция класса шаблона вне класса
{
	cout << "\n//////// Сортировка активистов по сфере деятельности /////////";
	qsort(obj.mas, obj.m_size, sizeof(Activists), Compare);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream students("Students.txt");
	ifstream activists("Activists.txt");
	ofstream out("Output.txt");

	MASSIV<Students<double>> el1;
	students >> el1;
	cout << "Cтуденты факультета:\n" << el1 << endl;
	out << "Cтуденты факультета:\n" << el1 << endl;

	MASSIV<Activists>el2;
	activists >> el2;
	cout << "Студенты активисты:\n" << el2 << endl;
	out << "Студенты активисты:\n" << el2 << endl;

	MASSIV<Students<float>> el3;
	el3.Intersection(el1, el2);		//пересечение el1 и el2
	Search(el2, cout);	
	Search(el2, out);				//поиск спортсменов в el2
	SpaceSort(el2);					//сортировка el2 по полю space
	cout << endl << el2;
	out <<"\nСортировка еl2 по полю Space\n" << el2;

	el1.WriteBinData("Data.txt");
	MASSIV<Students<double>> el4(el1.getSize());
	el4.ReadBinData("Data.txt");
	cout << endl << el4;

	return 0;
}