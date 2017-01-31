#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class tHash
{
	const static int TBSIZE = 1024;

	class pair
	{
	public:
		T key;
		T value;
		bool isSet = false;
	};

	pair things[TBSIZE];

	int getIndex(T key);

public:
	void set(T key, T value);
	T get(T key);
	bool isSet(T key);

	int count();
	bool isEmpty();
	void clear();

	inline void printIndex(T key)
	{
		cout << getIndex[key];
	}

};

template<typename T>
inline int tHash<T>::getIndex(T key)
{
	return 0;
}

template<typename T>
inline void tHash<T>::set(T key, T value)
{
	auto& n = things[getIndex(key)];
	n.key = key;
	n.value = value;
	n.isSet = true;
}

template<typename T>
inline T tHash<T>::get(T key)
{
	return things[getIndex(key)].value;
}

template<typename T>
inline bool tHash<T>::isSet(T key)
{
	return things[getIndex(key)].isSet;
}

template<typename T>
inline int tHash<T>::count()
{
	int count = 0;
	while (isSet(things[count].key))
		count++;

	return count;
}

template<typename T>
inline bool tHash<T>::isEmpty()
{
	return isSet(things[0].key);
}

template<typename T>
inline void tHash<T>::clear()
{
	int c = this->count();
	for (int i = 0; i < c; i++)
	{
		things[i].key = things[i].value = T{};
		things[i].isSet = false;
	}
}
