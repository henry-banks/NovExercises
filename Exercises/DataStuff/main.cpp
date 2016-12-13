#include <iostream>
#include <cassert>
//#include <climits>

#include "IntVector.h"
#include "tvector.h"

void main()
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