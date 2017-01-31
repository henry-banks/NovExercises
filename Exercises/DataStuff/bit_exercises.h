#pragma once
#include <iostream>

using namespace std;

/*
# Binary Exercises

Create a program where you can write and test the following functions.

## Checking My Bits

```bool IsLeftMostBitSet(unsigned int value)```

Returns `true` if the left most bit(MSB) of the `value` is set.
Otherwise, this returns `false`.

```bool IsRightMostBitSet(unsigned int value)```

Returns `true` if the right most bit(LSB) of the `value` is set.
Otherwise, this returns `false`.

```bool IsBitSet(unsigned int value, unsigned char bitToCheck)```

Returns `true` if the specified `bitToCheck` is set.The bits are
zero indexed starting from the right most bit.

```int GetRightMostSetBit(unsigned int value)```

Input | Output
-------- - | ------ -
00000001 | 0
10011100 | 2
01010000 | 4
00000000 | -1

## Pimp My Bits

```void PrintBinary(unsigned char value)```

Prints the `value` in binary.

## Pow My Bits

```bool IsPowerOf2(unsigned int value)```

Using only bitwise arithmetic operators, determine if the given `value` is
a power of two.
*/




bool IsRightMostBitSet(unsigned int value)
{
	return (value & 1);
}

bool IsLeftMostBitSet(unsigned int value)
{
	return (value & 2147483648);
}

bool IsBitSet(unsigned int value, unsigned char bitToCheck)
{
	return (value & bitToCheck);
}

int GetRightMostSetBit(unsigned int value)
{
	return true;
}

void PrintBinary(unsigned char value)
{
	int count = sizeof(unsigned char) * 8;
	char *buffer = new char[count];

	for (int i = 0; i < count; i++)
		buffer[count - i - 1] = ((value >> i) & 1) ? '1' : '0';

	for (int i = 0; i < count; i++)
		cout << buffer[i];
}

bool IsPowerOf2(unsigned int value)
{
	return true;
}