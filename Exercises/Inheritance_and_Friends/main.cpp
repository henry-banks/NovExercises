#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Animal.h"

using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor Called" << endl; }
	~Base() { cout << "Base Destructor Called" << endl; }
};

class Derived : public Base
{
public:
	Derived() { cout << "Derived Constructor Called" << endl; }
	~Derived() { cout << "Derived Destructor Called" << endl; }
};

class SuperSmol : public Derived
{
public:
	SuperSmol() { cout << "SuperSmol Constructor Called" << endl; }
	~SuperSmol() { cout << "SuperSmol Destructor Called" << endl; }
};

void main()
{
	srand(time(0));

	vector<Animal*> list;

	Animal* ptr;

	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 4)
		{
		case 0: ptr = new Falafal; break;
		case 1: ptr = new Bismuth; break;
		case 2: ptr = new Pikachu; break;
		case 3: ptr = new Derek; break;
		}
		list.push_back(ptr);
	}

	for each(auto a in list)
		a->doNoise();

	printf("\n");
	system("pause");
}