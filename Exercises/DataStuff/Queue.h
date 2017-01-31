#pragma once
#include <iostream>
#include <list>
using namespace std;

// FIFO (first in, first out)
template <typename T>
class queue
{
public:
	class Node {
	public:
		T data;
		Node *prev, *next;
		Node() : prev(nullptr), next(nullptr) {}
	};
private:
	size_t capacity;
	Node *head, *tail;

public:

	
	// Removes the frontmost value.
	// Returns the value that was removed.
	T pop();

	// Puts a value on the back of the queue.
	void push(T value);

	// Returns the frontmost value.
	T front();

	// Resizes the capacity of the backing array to accommodate
	// the given number of elements.
	void reserve(size_t size);

	// Resizes the capacity of the backing array to accommodate
	// the current number of elements.
	void compact();

	// Returns the number of elements.
	size_t size();

	// Returns true if there are no elements.
	bool empty();

	// Removes all elements.
	void clear();
};

template<typename T>
inline T queue<T>::pop()
{
	Node *n = head->prev;
	T out = head->data;
	delete head;
	head = n;

	return out;
}

template<typename T>
inline void queue<T>::push(T value)
{

	if (head > capacity)
	{
		reserve(head * 1.5f);
	}

	Node *n = new Node;
	n->data = value;
	n->next = tail;
	tail->prev = n;
	tail = n;
}

template<typename T>
inline T queue<T>::front()
{
	return head->data;
}

template<typename T>
inline void queue<T>::reserve(size_t size)
{

}

template<typename T>
inline void queue<T>::compact()
{
}

template<typename T>
inline size_t queue<T>::size()
{
	return size_t();
}

template<typename T>
inline bool queue<T>::empty()
{
	return false;
}

template<typename T>
inline void queue<T>::clear()
{
}
