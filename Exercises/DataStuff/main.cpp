#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
//#include <climits>

#include "IntVector.h"
#include "tvector.h"
#include "Tree.h"
#include "sorts.h"
#include "search.h"
#include "bit_exercises.h"
#include "hashTable.h"
#include "tHash.h"
#include "stack.h"
#include "ObjPool.h"

using namespace std;
using namespace std::chrono;

void tests()
{
	IntVector *testVec = new IntVector;
	assert((testVec->size() == 0));
	delete testVec;
	//assert((testVec->data() == nullptr));	//I'm not really sure how to test this...
	testVec = new IntVector;
	
	testVec->append(1);
	testVec->append(413);
	testVec->append(7);
	testVec->append(42);

	assert((*testVec)[1] == 413);
	assert((*testVec)[3] == 42);

	testVec->remove(2);
	assert((*testVec)[2] == 42);

	IntVector tv2;

	tv2 = *testVec;
	assert(tv2[1] == 413);

	IntVector tv3(tv2);
	assert(tv2[0] == 1);

	/////////////////
	//TEMPLATE VECTOR
	/////////////////

	//Default constructor
	tvector<int> intVec;
	assert(intVec.size() == 0);

	//Append
	intVec.append(55);
	assert(intVec[0] == 55);
	assert(intVec.size() == 1);

	intVec.append(1337);
	assert(intVec[0] == 55);
	assert(intVec[1] == 1337);
	assert(intVec.size() == 2);

	intVec.append(-8);
	assert(intVec[0] == 55);
	assert(intVec[1] == 1337);
	assert(intVec[2] == -8);
	assert(intVec.size() == 3);

	//Copy Assignment
	tvector<int> copy1 = intVec;
	assert(copy1[0] == 55);
	assert(copy1[1] == 1337);
	assert(copy1[2] == -8);
	assert(copy1.size() == 3);

	//Copy Constructor
	tvector<int> copy2(intVec);
	assert(copy2[0] == 55);
	assert(copy2[1] == 1337);
	assert(copy2[2] == -8);
	assert(copy2.size() == 3);

	//Move Assignment
	tvector<int> move1;
	move1 = tvector<int>();
	assert(move1.size() == 0);

	tvector<int> move2((move1));
		
	printf("\nAll Good :D\n\n");
	system("pause");
}

void treeStuff()
{
	Tree t;

t.insert(5);

t.find(5) ? printf("works\n\n") : printf("nah\n");

t.insert(100);
t.insert(3);
t.insert(-4);
t.insert(101);

t.find(100) ? printf("works\n\n") : printf("nah\n");
t.find(3) ? printf("works\n\n") : printf("nah\n");
t.find(-4) ? printf("works\n\n") : printf("nah\n");
t.find(101) ? printf("works\n\n") : printf("nah\n");
}

void basicArray()
{
	srand(time(0));

	int length = 100;
	int* stuff = new int[length];

	randFill(stuff, length);

	int* temp = stuff;
	randFill(temp, length);
	printData(stuff, length);
	printData(temp, length);

	printf("\n\n");
	insertionSort(temp, length);
	printData(temp, length);

	printf("\n\n");
	bubbleSort(stuff, length);
	printData(stuff, length);

	stuff[0] = 800;
	mergeSort(stuff, length);
	bubbleSort(stuff, length);
	printData(stuff, length);
	printf("\n");
	cout << endl << binarySearch(stuff, length, 800) << endl;
}

void timeCheck()
{
	srand(time(0));
	const size_t len = 1024;
	int* stuff = new int[len];

	auto t1 = high_resolution_clock::now();
	auto t2 = high_resolution_clock::now();
	auto duration = duration_cast<chrono::microseconds>(t2 - t1).count();

	randFill(stuff, len);

	t1 = high_resolution_clock::now();
	bubbleSort(stuff, len);
	t2 = high_resolution_clock::now();
	duration = duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Bubble Time: " << duration << endl;

	randFill(stuff, len);

	t1 = high_resolution_clock::now();
	insertionSort(stuff, len);
	t2 = high_resolution_clock::now();
	duration = duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Insertion Time: " << duration << endl;
}

void hashTests()
{
	hashTable t1;
	t1.set(24, 42);
	t1.set(96, 69);
	t1.set(314, 413);
	t1.set(7331, 1337);

	assert((t1.get(24)) == 42);
	//cout << t1.get(24) << endl;
	t1.printIndex(7331);
}

void stackTests()
{
	stack<int> s1;

	s1.push(5);
	s1.push(55);
	s1.push(423);
	s1.push(69);
	s1.push(42);
	s1.push(909);
	s1.push(911);
	s1.push(404);
	s1.push(1998);

	assert((s1.peek()) == 1998);
	assert(s1.size() == 9);
	s1.pop();
	assert((s1.peek()) == 404);
	s1.pop();
	s1.pop();
	assert((s1.peek()) == 909);
	assert(!s1.empty());

	assert(s1.size() == 6);
	s1.clear();
	assert(s1.empty());
	assert(s1.size() == 0);

	stack<char> s2;

	s2.push('2');
	s2.push('5');
	s2.push('x');
	s2.push('.');
	s2.push('\n');
	s2.push('\\');
	s2.push(8);

	assert((s2.peek()) == 8);
	assert((s2.size()) == 7);
	s2.pop();
	//cout << s2.peek() << endl;
	assert(s2.peek() == '\\');
	s2.pop();
	s2.pop();
	assert((s2.peek()) == '.');
	assert(!s2.empty());

	assert(s2.size() == 4);
	s2.clear();
	assert(s2.empty());
	assert(s2.size() == 0);
}

void poolTests()
{
	obpool<int> iPool;

	obpool<int>::handle h1 = iPool.push(5);
	assert(h1.value() == 5);
	assert(h1.isValid());

	obpool<int>::handle h2 = iPool.push(3);
	assert(h2.value() == 3);
	assert(h2.isValid());

	h1.free();
	assert(!h1.isValid());

	iPool.push(66);
	iPool.push(124);
	obpool<int>::handle h3 = iPool.push(70);

	h2.free();
	assert((iPool.begin().value()) == 66);
	assert((h2.value()) == 124);

	
	obpool<int> pool;

	auto han = pool.push(3);
	assert(han.value() == 3);
	assert(han.isValid());

	auto han2 = pool.push(5);
	assert(han.value() == 5);
	assert(han.isValid());

	auto han3 = pool.push(7);
	assert(han.value() == 7);
	assert(han.isValid());

	auto han4 = pool.push(9);
	assert(han.value() == 9);
	assert(han.isValid());

	han3.free();

	int expected[] = { 3,5,9 };

	size_t i;
	for (auto iter = pool.begin(); iter != pool.end(); iter++)
	{
		int val = *iter;
		assert(expected[i] == val);
		i++;
	}
}

void main()
{
	poolTests();

	printf("\nAll good :D\n\n");
	system("pause");
}

/*
Manual sorts

Base Array:
8 7 4 2 1 3 6 5

BUBBLE SORT:

8,7->7,8
7 8 4 2 1 3 6 5

[8,4]->4,8
7 4 8 2 1 3 6 5

7 4 2 8 1 3 6 5
7 4 2 1 8 3 6 5
7 4 2 1 3 8 6 5
7 4 2 1 3 6 8 5
7 4 2 1 3 6 5 8
7 steps


MERGE SORT

7 4 2 8 1 3 6 5
4,7 2,8 1,3 5,6
2,4,7,8 1,3,5,6



*/