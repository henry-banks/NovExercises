#pragma once
#include <iostream>
#include <string>
using namespace std;

//Hashing function
inline int knuth(int value)
{
	return value * INT_MAX >> 2 ^ 32;
}
inline int shmid(int value)
{
	int s = (int)'s' + (int)'h' + (int)'m' + (int)'i' + (int)'d';
	return (value * s);
}

class hashTable
{
	const static int TBSIZE = 128;

	class pair
	{
	public:
		int key;
		int value;
		bool isSet = false;
	};

	pair things[TBSIZE];

	int getIndex(int key);

public:
	void set(int key, int value);
	int get(int key);

	bool isSet(int key);

	int count();
	bool isEmpty();
	void clear();

	inline void printIndex(int key)
	{
		cout << getIndex(key);
	}
};