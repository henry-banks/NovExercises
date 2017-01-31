#include "hashTable.h"

int hashTable::getIndex(int key)
{
	return shmid(key) % TBSIZE;
}

void hashTable::set(int key, int value)
{
	auto& n = things[getIndex(key)];
	n.key = key;
	n.value = value;
	n.isSet = true;
}

int hashTable::get(int key)
{
	return things[getIndex(key)].value;
}

bool hashTable::isSet(int key)
{
	return things[getIndex(key)].isSet;
}

int hashTable::count()
{
	int count = 0;
	for (int i = 0; i < TBSIZE; i++)
	{
		if(things[i].isSet)
			count++;
	}
		

	return count;
}

bool hashTable::isEmpty()
{
	for (int i = 0; i < TBSIZE; i++)
	{
		if (things[i].isSet)
			return false;
	}
}

void hashTable::clear()
{
	for (int i = 0; i < TBSIZE; i++)
		things[i].isSet = false;
}
