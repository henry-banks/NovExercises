#pragma once
#include <cassert>
//THIS IS GOING TO BE VERY CLUTTERED BECAUSE ALL THE TEMPLATES HAVE TO BE DECLARED AND DEFINED IN THE SAME FILE.

template<typename T>
class tvector
{
private:
	T *m_data;
	size_t m_size;

public:

	tvector()
	{
		m_size = 0;
		m_data = new T;
	}

	~tvector()
	{
		m_size = 0;
		if (m_data != nullptr)
			delete[] m_data;
	}


	tvector(const tvector & o)	//Copy Constructor
	{
		m_data = new T[o.m_size];
		size_t i = 0;
		while (i < o.m_size)
			m_data[i] = o.m_data[i++];

		m_size = i;
	}

	tvector(tvector && o)		//Move Constructor
	{
		m_data = o.m_data;
		m_size - o.m_size;

		//Since this is a 'move' operator, we need to clear the other object.
		o.m_data = nullptr;
		o.m_size = 0;
	}


	//Assignment Move
	tvector &operator=(const tvector & o)
	{
		m_size = 0;
		if (m_data != nullptr)
			delete[] m_data;

		//COPY STUFF
		m_data = new T[m_size];
		size_t i = 0;
		for(int j = 0; j < o.m_size; j++)	//For some reason, using a while loop and incrementing i doesn't work; i becomes 1
			m_data[i] = o.m_data[i++];

		m_size = i;

		return *this;
	}

	//Assignment Copy
	tvector &operator=(tvector &o)
	{
		m_size = 0;
		if (m_data != nullptr)
			delete[] m_data;

		//COPY STUFF
		m_data = o.m_data;
		m_size = o.m_size;

		o.m_data = nullptr;
		o.m_size = 0;

		return *this;
	}

	//Mutable
	T&operator[](size_t idx)
	{
		assert(idx < m_size);	//Make sure the index is valid
		return m_data[idx];
	}

	//Const
	T &operator[](size_t idx) const
	{
		assert(idx < m_size);	//Make sure the index is valid
		return m_data[idx];
	}

	size_t append(T val)
	{
		T *tempData = new T[m_size + 1];

		for (int i = 0; i < m_size; i++)
			tempData[i] = m_data[i];

		//tempData[++m_size] = val;	//Finally, we assign the new value to the last index in the array...
		delete[] m_data;				//...delete the old array...
		m_data = tempData;			//..then assign m_data to it.
		m_data[m_size] = val;
		tempData = nullptr;

		m_size++;
		return m_size;
	}

	size_t remove(size_t idx)
	{
		T *tempData = new T[m_size - 1];
		int j = 0;

		for (int i = 0; i < m_size; i++)
		{
			if (i != idx)	//Make sure not to include the deleted value
				tempData[j++] = m_data[i];
		}

		delete[] m_data;		//Finally, we delete the old array...
		m_data = tempData;		//..then assign m_data to it.
		tempData = nullptr;
		m_size--;
		return m_size;
	}

	size_t size();
	T* data();
};

//Getters
template<typename T>
size_t tvector<T>::size() { return m_size; }

template<typename T>
T * tvector<T>::data() { return m_data; }