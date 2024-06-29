#pragma once
#ifndef CLASS_H
#define CLASS_H
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<assert.h>

template<typename T>
struct Students
{
public:
	char Name[50];
	T GPA;

	Students()
	{
		strcpy_s(Name, "NAME");
		T GPA = 0;
	}
	~Students() {};

	template<typename T2>
	bool operator== (const T2& obj)
	{
		if (strcmp(this->Name, obj.Name) == 0) return true;
		else return false;
	}

	//работает с students и smartstudents
	bool operator< (const Students<T>& obj)
	{
		if (this->GPA < obj.GPA) return true;
		else return false;
	}


	bool operator> (const Students<T>& obj)
	{
		if (this->GPA > obj.GPA) return true;
		else return false;
	}
	template<typename T2>
	Students<T> operator=(Students<T2>& obj)
	{
		strcpy_s(this->Name, obj.Name);
		this->GPA = static_cast<T2>(obj.GPA);
		return *this;
	}


	friend std::istream& operator>> (std::istream& in, Students& obj)
	{
		char temp[2] = " ";
		char surname[50];
		in >> obj.Name >> surname;
		strcat_s(obj.Name, temp);
		strcat_s(obj.Name, surname);

		in >> obj.GPA;
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const Students<T>& obj)
	{
		out << std::setw(22) << obj.Name << std::setw(10) << " GPA: " << obj.GPA;
		return out;
	}

};

struct Activists
{
public:
	char Name[50];
	char Space[50];

	Activists()
	{
		strcpy_s(Name, "NAME");
		strcpy_s(Space, "ACTIVITY");
	}
	~Activists() {}

	template<typename T>
	bool operator ==(const T& obj)
	{
		if (strcmp(this->Name, obj.Name) == 0) return true;
		else return false;
	}

	template<typename T>
	Activists& operator= (T& obj)
	{
		strcpy_s(this->Name, obj.Name);
		return *this;
	}
	template<>
	Activists& operator= (Activists& obj)
	{
		strcpy_s(this->Name, obj.Name);
		strcpy_s(this->Space, obj.Space);
		return *this;
	}
	template<typename T>
	bool operator> (T& obj)
	{
		if (strcmp(this->Name, obj.Name) > 0) return true;
		else return false;
	}

	template<typename T>
	bool operator< (T& obj)
	{
		if (strcmp(this->Name, obj.Name) < 0) return true;
		else return false;
	}

	friend std::istream& operator>> (std::istream& in, Activists& obj)
	{

		char temp[2] = " ";
		char surname[50];
		in >> obj.Name >> surname;
		strcat_s(obj.Name, temp);
		strcat_s(obj.Name, surname);

		in >> obj.Space;
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const Activists& obj)
	{
		out << std::setw(22) << obj.Name << std::setw(25) << "Сфера деятельности: " << obj.Space;
		return out;
	}
};

template <typename T>
class MASSIV
{
private:
	T* mas;
	int m_size;
public:
	MASSIV()
	{
		m_size = 0;
		mas = nullptr;
	}
	MASSIV(int size) : m_size(size)
	{
		mas = new T[m_size];
	}
	MASSIV(MASSIV& obj) : m_size(obj.m_size)
	{
		MASSIV(m_size);
	}
	~MASSIV()
	{
		delete[]mas;
	}

	int getSize();
	T* getMas() { return mas; }

	MASSIV operator=(const MASSIV& obj)
	{
		this->m_size = obj.m_size;
		this->mas = new T[this->m_size];
		for (int i = 0; i < this->m_size; i++)
		{
			this->mas[i] = obj.mas[i];
		}
		return *this;
	}
	T& operator[](const size_t index)
	{
		assert(index < this->m_size);
		return this->mas[index];
	}
	const T& operator[](const size_t index) const
	{
		assert(index < this->m_size);
		return this->mas[index];
	}

	friend std::istream& operator>>(std::istream& in, MASSIV& obj)
	{

		in >> obj.m_size;
		obj.mas = new T[obj.m_size];


		for (int i = 0; i < obj.m_size; i++)
		{
			in >> obj.mas[i];
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const MASSIV& obj)
	{
		for (int i = 0; i < obj.m_size; i++)
		{
			out << obj.mas[i];
			out << std::endl;
		}
		return out;
	}

	void ReadBinData(const char* filename)
	{
		std::cout << "\n/////// Чтение данных из бинарного файла ///////\n";
		std::fstream in;
		in.open(filename, std::ofstream::in | std::ofstream::binary);
			if (!in.is_open())
			{
				std::cerr << "\nБинарный файл не открыт\n";
			}
			else
			{
				in.seekg(0, std::ios::beg);
				for (int i = 0; i < this->m_size; i++)
				{
					in.read((char*)&this->mas[i], sizeof(T));
				}
				in.close();
				std::cout << "\n/////// Чтение завершено ///////\n";
			}
	}
	void WriteBinData(const char* filename)
	{
		std::cout << "\n/////// Запись в бинарный файл ///////\n";
		std::fstream out;
		out.open(filename, std::ofstream::out | std::ofstream::binary);
		if (!out.is_open())
		{
			std::cerr << "\nБинарный файл не открыт\n";
		}
		else
		{
			for (int i = 0; i < this->m_size; i++)
			{
				out.write((char*)&this->mas[i], sizeof(T));
			}
			out.close();
			std::cout << "\n/////// Запись завершена ///////\n";
		}
	}   

	template<typename T2>
	void Intersection(MASSIV<Students<T2>>& obj1, MASSIV<Activists>& obj2)
	{
		int inter_size = 0;
		for (int i = 0; i < obj1.getSize(); i++) //считаем количество пересечений
		{
			for (int k = 0; k < obj2.getSize(); k++)
			{
				if (obj1[i] == obj2[k])
				{
					++inter_size;
				}
			}
		}
		int temp = 0;
		this->mas = new T[inter_size];
		std::cout << "\nАктивные студенты с хорошей успеваемостью (пересечение первого и второго массива):\n";
		for (int i = 0; i < obj1.getSize(); i++)
		{
			for (int k = 0; k < obj2.getSize(); k++)
			{
				if (obj1[i] == obj2[k])
				{
					this->mas[temp] = obj1[i];
					std::cout << mas[temp] << std::endl;
					temp++;
				}
			}
		}
	}
	friend void SpaceSort(MASSIV<Activists>& obj);		//дружественная функция вне тела класса
};

template<typename T>		//метод класса шаблона вне его тела
 int MASSIV<T> :: getSize ()	{ return this->m_size; }

#endif