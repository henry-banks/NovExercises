#include "IntVector.h"
#include <iostream>
#include <cassert>

IntVector::IntVector()
{
	m_size = 0;
	m_data = new int;
}


IntVector::~IntVector()
{
	m_size = 0;
	if(m_data != nullptr)
		delete[] m_data;
}

IntVector::IntVector(const IntVector & o)
{
	//Is this what you meant by 'create a new array and copy the data from the other object'?
	m_data = new int[o.m_size];
	size_t i = 0;
	while(i < o.m_size)
		m_data[i] = o.m_data[i++];

	m_size = i + 1;	//Make it i + 1 because sizes are usually base 1;
}

IntVector::IntVector(IntVector && o)
{
	m_data = o.m_data;
	m_size - o.m_size;

	//Since this is a 'move' operator, we need to clear the other object.
	o.m_data = nullptr;
	o.m_size = 0;
}

IntVector & IntVector::operator=(const IntVector & o)
{
	//Make sure we're working with a clean slate before copying.
	m_size = 0;
	if (m_data != nullptr)
		delete[] m_data;

	//COPY STUFF
	m_data = new int[m_size];
	size_t i = 0;
	while (i < o.m_size);
		m_data[i] = o.m_data[i++];

	m_size = i + 1;

	return *this;	//We ARE supposed to return something, right?
}

IntVector & IntVector::operator=(IntVector &o)
{
	//Is all same.
	m_size = 0;
	if (m_data != nullptr)
		delete[] m_data;

	//COPY STUFF
	m_data = o.m_data;
	m_size = o.m_size;

	o.m_data = nullptr;
	o.m_size = 0;

	return *this;	//We ARE supposed to return something, right?
}

int & IntVector::operator[](size_t idx)
{
	assert(idx < m_size);	//Make sure the index is valid
	return m_data[idx];
}

int & IntVector::operator[](size_t idx) const
{
	assert(idx < m_size);	//Make sure the index is valid
	return m_data[idx];
}

size_t IntVector::append(int val)
{
	//Since arrays are static, we have to make a new array and add everything to that.
	int *tempData = new int[m_size + 1];

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

size_t IntVector::remove(size_t idx)
{
	//Since arrays are static, we have to make a new array and add everything to that.
	int *tempData = new int[m_size - 1];
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

size_t IntVector::size()
{
	return m_size;
}

int * IntVector::data()
{
	return m_data;
}
