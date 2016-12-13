extern int glob;

static int cache[1000];


void clear_cache(int val)
{
	for (int i = 0; i < val; i++)
	{
		cache[i] = 0;
	}
}

int other_fib(int val)
{
	glob++;

	if (val == 0)
		return 0;
	else if (val == 1)
		return 1;

	if (cache[val] != 0)
		return cache[val];

	return cache[val] = (other_fib(val - 1) + other_fib(val - 2));

}

int fib(int val)
{
	glob++;

	if (val == 0)
		return 0;
	else if (val == 1)
		return 1;
	else
		return (fib(val - 1) + fib(val - 2));
}