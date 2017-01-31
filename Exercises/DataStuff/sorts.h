#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printData(const int *data, size_t length)
{
	for (int i = 0; i < length; i++)
		cout << data[i] << ", ";
	cout << endl;
}

void randFill(int *data, size_t length)
{
	for (int i = 0; i < length; i++)
		data[i] = rand();
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

//AKA Exchange Sort
void bubbleSort(int *data, size_t length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 1; j < length; j++)
		{
			if (data[j] < data[j - 1])
				swap(data[j], data[j - 1]);
		}
	}

}

void insertionSort(int *data, size_t length)
{
	for (int i = 1; i < length; i++)
	{
		int j = i;
		while (j > 0 && data[j - 1] > data[j])
		{
			swap(data[j], data[j - 1]);
			j--;
		}
	}
}


//Merge Sort
void merge(int *data, size_t L, size_t M, size_t R)
{
	size_t s = R-L;
	int *A = new int[s + 1];
	size_t l = 0, r = M + 1;
	
	for (int i = 0; i < s; i++)
	{
		if (l < M && r < R)
		{
			A[i] = (data[l] < data[r]) ?
				data[l++] :
				data[r++];
		}
		A[i] = (l == M) ?
			data[r++] :
			data[l++];
	}

	for (int i = 0; i < s; i++)
		data[L + i] = A[i];

	delete[] A;
}

void mergeSortRec(int *data, size_t L, size_t R)
{
	printData(data + L, R + 1 - L);
	if (L < R)
	{
		size_t M = (L + R) / 2;
		mergeSortRec(data, L, M);
		mergeSortRec(data, M + 1, R);
		merge(data, L, M, R);
	}
	
}

void mergeSort(int *data, size_t length)
{
	mergeSortRec(data, 0, length - 1);
}
