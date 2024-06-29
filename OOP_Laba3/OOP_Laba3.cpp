#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Vehicle
{
protected:
	const int id;
	static int count;
	Vehicle() : id(++count) {};
public:

	virtual int getCount() { return count; };
	virtual int getID() { return id; };
	virtual ~Vehicle() {};
};

int Vehicle::count = 0;


class Car : public Vehicle
{
protected:
	string brand;
	int cylinders;
	int power;

public:
	Car(string name = "Car brand", int engine = 0, int power_val = 0) : brand(name), cylinders(engine), power(power_val) {};

	
	void Display()
	{
		cout << "�����: " << brand << "\t\t���������� ���������: " << cylinders << "\t\t��������: " << power << " ��������� ���";
	};
	virtual void ChangeBrand()
	{
		cout << "������� ����� �������� ����� ����:\t";
		string name;
		cin >> name;
		brand = name;
	};
};


class Truck : public Car
{
private:
	int cargoCapacity;
public:
	Truck(int capacity) : cargoCapacity(capacity) {};
	Truck(string name = "Truck brand", int engine = 0, int power_val = 0, int capacity = 0) : Car(name, engine, power_val), cargoCapacity(capacity) {};

	void Display()
	{
		Car::Display();
		cout << "\t����������������: " << cargoCapacity;
	};
	void ChangeCapacity()
	{
		int new_value;
		cout << "������� ����� �������� ��������������:\t";
		cin >> new_value;
		cargoCapacity = new_value;
	}
	virtual void ChangeBrand()
	{
		cout << "������� ����� �������� ����� ���������:\t";
		string name;
		cin >> name;
		brand = name;
	}
	

};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RUS");
	Car BMW("BMW", 12, 500);
	Truck Harvester;
	Truck BELAZ("BELAZ", 16, 2000, 450);
	cout << "Vehicles IDs:\n" << BMW.getID() << endl << Harvester.getID() << endl << BELAZ.getID() << endl;

	BMW.Display();		cout << endl;
	BELAZ.Display();	cout << endl;
	Harvester.Display(); cout << endl;

	Harvester.ChangeBrand();
	Harvester.ChangeCapacity();
	Harvester.Display();	cout << endl;

	BMW.ChangeBrand();
	BMW.Display();		cout << endl;

	cout<<endl<<"����� ���������� �����:\t"<<BMW.getCount();
	return 0;
}