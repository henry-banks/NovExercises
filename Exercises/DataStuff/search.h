#pragma once
#include <iostream>

using namespace std;

//so simple
int *linearSearch(int *data, size_t l, int key)
{
	for (int i = 0; i < l; i++)
		if (data[i] == key)
			return &data[i];

	return nullptr;
}

int *binarySearch(int *data, size_t l, int key)
{
	int min = 0, max = l-1, mid;
	while (min != max)
	{
		mid = (min + max) / 2;
		cout << data[mid] << endl;
		if (data[mid] == key)
			return &data[mid];

		key > data[mid] ? min = mid + 1 : max = mid - 1;
		mid = (min + max / 2);
	}

	return nullptr;
}