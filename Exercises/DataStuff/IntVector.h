#pragma once
class IntVector
{
	int *m_data;
	size_t m_size;
public:
	IntVector();	//Default Constructor
	~IntVector();	//Destructor

	IntVector(const IntVector &o);	//Copy Constructor
	IntVector(IntVector &&o);		//Move Constructor
	
	IntVector &operator=(const IntVector &o);	//Assignment Operator
	IntVector &operator=(IntVector &o);			//Assignment Copy

	int &operator[](size_t idx);		//Mutable
	int &operator[](size_t idx) const;	//Const

	size_t append(int val);
	size_t remove(size_t idx);

	//Getters
	size_t size();
	int* data();
};

