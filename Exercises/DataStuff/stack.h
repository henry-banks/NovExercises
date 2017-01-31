#pragma once
#include <iostream>
using namespace std;

template<typename T>
class stack
{

	class thing
	{
	public:
		T value;
		bool isSet = false;
	};
	const static int HSIZE = 1024;
	size_t capacity = HSIZE;
	thing *things = new thing[HSIZE];
	int head = 0;

public:

	void push(T data);
	T pop();
	T peek();
	void reserve(size_t size_a);
	void compact();
	size_t size();

	bool empty();

	void clear();
};

template<typename T>
inline void stack<T>::push(T data)
{
	if (head > capacity)
	{
		reserve(head * 1.5f);
	}
	things[head].value = data;
	things[head].isSet = true;
	head++;
}

template<typename T>
inline T stack<T>::pop()
{
	T n = things[head - 1].value;
	if (!empty())
		things[head - 1].isSet = false;
	head--;
	return n;
}

template<typename T>
inline T stack<T>::peek()
{
	return things[head - 1].value;
}

template<typename T>
inline void stack<T>::reserve(size_t size_a)
{
	thing *temp = new thing[size_a];

	//Copy old array to new array
	for (int i = 0; i < size_a; i++)
		temp[i] = things[i];
	//perform copy
	memcpy_s(temp, sizeof(int) * size_a, things, capacity);

	delete[] things;
	things = temp;
	capacity = size_a;
}

template<typename T>
inline void stack<T>::compact()
{
	capacity = head;
}

template<typename T>
inline size_t stack<T>::size()
{
	int count = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (!things[i].isSet)
			return count;

		count++;
	}
	return count;
}

template<typename T>
inline bool stack<T>::empty()
{
	if (things[0].isSet)
		return false;

	return true;
}

template<typename T>
inline void stack<T>::clear()
{
	for (int i = 0; i < HSIZE; i++)
		things[i].isSet = false;
	head = 0;
}
