#include <iostream>
using namespace std;

class Cond
{
	char* name;
public:
	Cond() {
		char* name;
	}
	Cond(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Cond(const Cond& obj)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		cout << "CONDITION COPY CONSTRUCTOR" << endl;
	}

	void PrintCond() const
	{
		cout << "Cond name: " << name << endl;
	}
	~Cond()
	{
		delete[]name;
	}
	char* GetName() const
	{
		return name;
	}
	void SetName(const char* n)
	{
		if (name != nullptr)
			delete[]name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
};


class Engine
{
	char* name;
public:
	Engine() {
		char* name;
	}
	Engine(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Engine(const Engine& obj)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		cout << "ENGINE COPY CONSTRUCTOR" << endl;
	}

	void PrintEngine() const
	{
		cout << "Engine name: " << name << endl;
	}
	~Engine()
	{
		delete[]name;
	}
	char* GetName() const
	{
		return name;
	}
	void SetName(const char* n)
	{
		if (name != nullptr)
			delete []name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
};

class Car
{
	char* model;
	int year;
	Engine eng;
	Cond cond;
public:
	Car(){
		model = nullptr;
		year = 0;
	} //Створенняде фолтного конструктора явно

	Car(const char* n, int y, const char* e, const char* c) : year(y), eng(e), cond(c)
	{
		model = new char[strlen(n) + 1];
		strcpy_s(model, strlen(n) + 1, n);
	}
	Car(const Car& otherCar) : year(otherCar.year), eng(otherCar.eng), cond(otherCar.cond)
	{
		this->model = new char[strlen(otherCar.model) + 1];
		strcpy_s(this->model, strlen(otherCar.model) + 1, otherCar.model);
		cout << "COPY CONSTRUCTOR" << endl;
		eng.SetName(otherCar.eng.GetName());
		cond.SetName(otherCar.cond.GetName());
	}

	~Car()
	{
		delete[]model;
	}

	void PrintCar() const {
		cout << model << endl;
		cout << year << endl;
		eng.PrintEngine();
		cond.PrintCond();
	}
};

int main()
{
	Car car("Toyota", 2004, "Toyota Enging", "Bosh");
	car.PrintCar();
	cout << endl;
	Car car2 = car;
	car2.PrintCar();
	cout << endl;
	Car car3(car2);
	car3.PrintCar();
}