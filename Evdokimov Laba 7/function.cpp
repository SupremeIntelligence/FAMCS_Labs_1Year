
#include"Header.h"
using namespace std;
Point:: Point(int masSize) : size(masSize)
{
	mas = new int[size];
}
Point:: Point(const Point& obj)
{
	size = obj.size;
	mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = obj.mas[i];
	}
}
Point::~Point()
{
	delete[] mas;
}
Point Point :: operator=(const Point& obj)
{
	for (int i = 0; i < size; i++)
	{
		this->mas[i] = obj.mas[i];
	}
	return *this;
}
Point Point :: operator*(int x) const
{
	Point result(size);
	for (int i = 0; i < size; i++)
	{
		result.mas[i] = this->mas[i] * x;
	}
	return result;
}
Point Point :: operator/(int x) const //проблема
{
	Point result(size);
	for (int i = 0; i < size; i++)
	{
		if (x != 0) result.mas[i] = this->mas[i] / x;

	}
	return result;
}
Point Point :: operator++(int x)
{
	x = 1;
	for (int i = 0; i < size; i++)
	{
		this->mas[i] += x;
	}
	return *this;
}
Point Point :: operator++()
{
	for (int i = 0; i < size; i++)
	{
		++mas[i];
	}
	return *this;
}
Point Point :: operator--(int x)
{
	x = 1;
	for (int i = 0; i < size; i++)
	{
		this->mas[i] -= x;
	}
	return *this;
}
Point Point :: operator--()
{
	for (int i = 0; i < size; i++)
	{
		--mas[i];
	}
	return *this;
}
Point Point :: operator~()	
{
	for (int i = 0; i < size; i++)
	{
		this->mas[i] = ~this->mas[i];
	}
	return *this;
}
bool Point :: operator!=(const Point& obj) const
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != obj.mas[i]) { counter++; }
	}
	if (counter == size) return true;
	else return false;
}
bool Point :: operator==(const Point& obj) const
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == obj.mas[i]) { counter++; }
	}
	if (counter == size) return true;
	else return false;
}
bool Point :: operator>=(const Point& obj) const
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] >= obj.mas[i]) { counter++; }
	}
	if (counter == size) return true;
	else return false;
}
bool Point :: operator<=(const Point& obj) const
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] <= obj.mas[i]) { counter++; }
	}
	if (counter == size) return true;
	else return false;
}
int Point :: operator[](int x) const
{
	return this->mas[x];
}
Point operator+(const Point& obj1, const Point& obj2)
{
	Point result(obj1);
	for (int i = 0; i < obj1.size; i++)
	{
		result.mas[i] = obj1.mas[i] + obj2.mas[i];
	}
	return result;
}
Point operator-(const Point& obj1, const Point& obj2)
{
	Point result(obj1);
	for (int i = 0; i < obj1.size; i++)
	{
		result.mas[i] = obj1.mas[i] - obj2.mas[i];
	}
	return result;
}
Point operator*(const Point& obj1, const Point& obj2)
{
	Point result(obj1);
	for (int i = 0; i < obj1.size; i++)
	{
		result.mas[i] = obj1.mas[i] * obj2.mas[i];
	}
	return result;
}
istream& operator>>(istream& in, Point& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		cin >> obj.mas[i];
	}
	return in;
}
ostream& operator<<(ostream& out, const Point& obj)
{
	if (obj.size > 1)
	{
		for (int i = 0; i < obj.size; i++)
		{

			if (i == 0)
			{
				out << '(' << obj.mas[i] << ", ";
			}
			else if (i == obj.size - 1)
			{
				out << obj.mas[i] << ')';
			}
			else
			{
				out << obj.mas[i] << ", ";
			}
		}
	}
	else
	{
		out << "( "<< obj.mas[0]<<" )";
		}
	return out;
}
