#pragma once
#ifndef CLASS_H
#define CLASS_H
#include<iostream>
class Point
{
private:
	int* mas;
	int size;
public:

	Point(int masSize);

	Point(const Point& obj);

	~Point();


	friend Point operator+(const Point& obj1, const Point& obj2);
	friend Point operator-(const Point& obj1, const Point& obj2);
	friend Point operator*(const Point& obj1, const Point& obj2);

	Point operator=(const Point& obj);
	Point operator*(int x) const;
	Point operator/(int x) const;
	Point operator++(int x);
	Point operator++();
	Point operator--(int x);
	Point operator--();
	Point operator~();
	bool operator!=(const Point& obj) const;
	bool operator==(const Point& obj) const;
	bool operator>=(const Point& obj) const;
	bool operator<=(const Point& obj) const;
	int operator[](int x) const;
	friend std::istream& operator>>(std::istream& in, Point& obj);
	friend std::ostream& operator<<(std::ostream& out, const Point& obj);
};
#endif