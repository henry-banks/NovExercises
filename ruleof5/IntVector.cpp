#include <assert.h>

class IntVector {
private:
	int *m_data;
	size_t m_size;

public:
	int &operator[](size_t idx);
	int &operator[](size_t idx) const;

	size_t append(int val);
	size_t remove(size_t idx);

	void resize(size_t newSize);

	//Rule of 5
	IntVector();
	~IntVector();

	// Copy Constructor
	IntVector(const IntVector &o);


	IntVector(IntVector &&o);

	IntVector &operator=(const IntVector &o);
	IntVector &operator=(IntVector &&o);
};

// Mutable subscript operator
int & IntVector::operator[](size_t idx){	
	assert(idx < m_size);
	return m_data[idx];
}

// Constant subscript operator
int & IntVector::operator[](size_t idx) const{
	assert(idx < m_size);
	return m_data[idx];
}

size_t IntVector::append(int val)
{
	resize(m_size + 1);
	m_data[m_size - 1] = val;
	return m_data[val];
}

size_t IntVector::remove(size_t idx){	
	assert(idx < m_size);
	int * temp = m_size - 1 > 0 ? new int[m_size - 1] : nullptr;

	// copy all elements up to index
	for (int i = 0; i < idx; ++i) {
		temp[i] = m_data[i];
	}
	// copy all elements after the index
	for (int i = idx +1; i < m_size; ++i) {
		temp[i-1] = m_data[i];
	}
	if (m_data != nullptr) delete[] m_data;
	m_data = temp;
	m_size--;
	return m_size;

}

void IntVector::resize(size_t newSize){
	int * temp = nullptr;

	if (newSize > 0) {
		temp - new int[newSize];
		for (int i = 0; i < m_size; ++i)
			temp[i] = m_data[i];
	}
	if (m_data != nullptr) delete[] m_data;

	// update bookkeeping
	m_data = temp;
	m_size = newSize;
}

// Default Constructor
IntVector::IntVector()
{
	m_data = nullptr;
	m_size = 0;
}

IntVector::~IntVector()
{
	m_size = 0;
	if (m_data != nullptr) {
		delete[] m_data;
	}
	m_data = nullptr;
}

// Copy Constructor
IntVector::IntVector(const IntVector & o){	
	
	m_size = o.m_size;
	m_data = new int[m_size];

	for (int i = 0; i < m_size; ++i) {
		m_data[i] = o.m_data[i];
	}
}

// Move Constructor
IntVector::IntVector(IntVector && o){
	int *copyData;
	copyData = new int[o.m_size];
	for (int i = 0; i < o.m_size; ++i) {
		copyData[i] = o.m_data[i];
	}

	m_data = copyData;
	m_size = o.m_size;

	// reset
	o.m_size = 0;
	o.m_data = nullptr;
}

// Copy Assignment
IntVector & IntVector::operator=(const IntVector & o){
	if (m_data != nullptr) {
		m_data = nullptr;
		m_size = 0;
	}
	
	int *copyData;
	copyData = new int[o.m_size];
	for (int i = 0; i < o.m_size; ++i) {
		copyData[i] = o.m_data[i];
	}
	m_data = copyData;
	m_size = o.m_size;
}

// Move Assignment
IntVector & IntVector::operator=(IntVector && o)
{
	if (m_data != nullptr) {
		m_data = nullptr;
		m_size = 0;
	}

	int *copyData;
	copyData = new int[o.m_size];
	for (int i = 0; i < o.m_size; ++i) {
		copyData[i] = o.m_data[i];
	}
	m_data = copyData;
	m_size = o.m_size;

	// reset
	o.m_size = 0;
	o.m_data = nullptr;
}
