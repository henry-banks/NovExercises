#include <iostream>
#include "fib.h"


int NumberofFiboCalls::fiboCallsMade(int n)
{
	// Constraints
	// n will be between 0 and 40, inclusive.
	if (n == 0) {
		//printf("0\n");
		calls[0]++;
		return 0;
	}

	if (n == 1) {
		//printf("1\n");
		calls[1]++;
		return 1;
	}

	//printf("%i %i\n", calls[0], calls[1]);
	return fiboCallsMade(n - 1) + fiboCallsMade(n - 2);
}
