#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string animalNoise;
public:
	Animal(string inNoise) { animalNoise = inNoise; }

	virtual void doNoise() const = 0;
};

class Falafal : public Animal{
public:
	Falafal() : Animal("gyro") {};
	void doNoise() const override { cout << "gyro" << endl; }
};

class Bismuth : public Animal {
public:
	Bismuth() : Animal("DEATH TO MY ENEMIES") {};
	void doNoise() const override { cout << "DEATH TO MY ENEMIES" << endl; }
};

class Pikachu : public Animal {
public:
	Pikachu() : Animal("Squirtle") {};
	void doNoise() const override { cout << "Squirtle" << endl; }
};

class Derek : public Animal {
public:
	Derek() : Animal("trump") {};
	void doNoise() const override { cout << "trump" << endl; }
};
