extern int count;

//const int SIZE = 640000;

static int * stuff;

void clearCache(int a_size){

	stuff = new int[a_size];
	
	if (stuff != nullptr)
		delete[] stuff;

	if (a_size != 0)
		for (int i = 0; i < a_size; ++i)
			stuff[i] = 0;
		
}

int fib(int x)
{
	count++;

	if (x == 0)
		return 0;

	if (x == 1)
		return 1;

	return fib(x - 1) + fib(x - 2);
}

int newFib(int x)
{	
	count++;	

	if (x == 0)
		return 0;

	if (x == 1)
		return 1;

	if (stuff[x] != 0)
		return stuff[x];

	return stuff[x] = newFib(x - 1) + newFib(x - 2);
}