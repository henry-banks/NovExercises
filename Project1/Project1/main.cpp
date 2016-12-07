#include <iostream>

int count;

int fib(int x);
int newFib(int x);
void clearCache(int a_size);

void main()
{		
	count = 0;
	clearCache(22);


	//fib(6);
	newFib(6);
	printf("%i\n", count);
	system("pause");
}