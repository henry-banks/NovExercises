#include <iostream>
#include "TriangleTriples.h"
#include "fib.h"
using namespace std;

void main()
{
	TriangleTriples test;
	NumberofFiboCalls CallsMade;

	printf("%d\n\n", test.count(1,10,20));

	CallsMade.calls[0] = { 0 }; CallsMade.calls[1] = { 0 };
	CallsMade.fiboCallsMade(22);

	printf("%i %i\n", CallsMade.calls[0], CallsMade.calls[1]);

	printf("\n\n");
	system("pause");
}