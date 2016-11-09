#include "TriangleTriples.h"
#include <iostream>


TriangleTriples::TriangleTriples()
{
}


TriangleTriples::~TriangleTriples()
{
}

int TriangleTriples::count(int limA, int limB, int limC)
{
	//Each variable represents the side of a triangle
	int a = 1, b = 1, c = 1;
	//Number of possible triples
	int count = 0;

	for (int i = 1; i <= limA; i++)
	{
		for (int j = 1; j <= limB; j++)
		{
			for (int k = 1; k <= limC; k++)
			{
				if (i + j > k &&
					i + k > j &&
					k + j > i)
				{
					printf("%d, %d, %d\n", i, j, k);
					count++;
				}
			}
		}
	}
	return count;
}
