#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template<typename T>
void printVec(vector<T> vec)
{
	for (int i = 0; i < 20; i++)
		cout << vec[i] << endl;

	printf("\n\n");
}

void randomVector()
{
	srand(time(0));
	vector<int> randVec;

	for (int i = 0; i < 20; i++)
		randVec.push_back(rand());
	
	printVec(randVec);

	sort(randVec.begin(), randVec.end());
	printVec(randVec);

	sort(randVec.rbegin(), randVec.rend());
	printVec(randVec);

	for (int i = 1; i < 20; i += 2)
		randVec[i] = 0;

	printVec(randVec);

	
}

void baseStuff()
{
	vector<int> intVec;

	intVec.push_back(5);
	intVec.push_back(2);
	intVec.push_back(7);

	if(intVec.size() > 2)
		intVec[2] = 10;

	//iterator points to thign in vector
	typedef vector<int>::iterator intVecIterator;
	intVecIterator it = intVec.begin();

	//int iVal = (*it);
	//(*it) = 12;
	//it = intVec.begin();
	//it = it + 2;	//now points to 3rd element in vector

	//for (it = intVec.begin; it != intVec.end; it++)
	//	cout << (*it) << endl;
}

void main()
{
	baseStuff();

	printf("\n");

	randomVector();

	printf("\n\n");
	system("pause");
}