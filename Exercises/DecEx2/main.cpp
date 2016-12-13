#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <math.h>
using namespace std;

int glob = 0;

int fib(int val);
int other_fib(int val);
void clear_cache(int val);

void main()
{
	clear_cache(1000);

	cout << other_fib(6) << endl;
	cout << glob << endl;

	printf("\n\nAll Good :D\n\n");
	system("pause");
}

/* Fib(6) call stack
1 fib(6)
2 	fib(5)
3		fib(4)
4			fib(3)
5				fib(2)
6					fib(1)*
7					fib(0)*
8				fib(1)*
9			fib(2)
10				fib(1)*
11				fib(0)*
12		fib(3)
13			fib(2)
14				fib(1)*
15				fib(0)*
16			fib(1)*
17	fib(4)
18		fib(3)
19			fib(2)
20				fib(1)*
21				fib(0)*
22			fib(1)*
23		fib(2)
24			fib(1)*
25			fib(0)*
*/