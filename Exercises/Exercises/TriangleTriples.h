#pragma once
class TriangleTriples
{
public:
	TriangleTriples();
	~TriangleTriples();
	/*
	*Returns number of triples with sides a,b,c, where all sides are POSITIVE INTEGERS (1 or greater)
	*limA: maximum side a
	*limB: maximum side b
	*limC: maximum side c
	*/
	int count(int limA, int limB, int limC);
};


