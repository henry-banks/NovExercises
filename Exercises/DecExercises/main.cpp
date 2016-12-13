#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <math.h>
using namespace std;

int largest_digit(int digits)
{
	string dString = to_string(digits);
	int max = -INFINITY;

	for (int i = 0; i < dString.length(); i++)
	{

		string tempStr;
		tempStr += dString[i];
		if (atoi(tempStr.c_str()) > max)
			max = atoi(tempStr.c_str());
	}
	return max;
}

//NOTE: This works for any length of numbers, not just 4-digit
int desc_digits(int digits)
{
	string dString = to_string(digits);
	vector<int> numList;

	//Convert string to int
	for (int i = 0; i < dString.length(); i++)
	{
		string t;
		t += dString[i];
		numList.push_back(atoi(t.c_str()));
	}
	
	for (int i = 0; i < numList.size(); i++)
	{
		int j = i;
		while (j > 0 && numList[j] > numList[j - 1])
		{
			int temp = numList[j];
			numList[j] = numList[j - 1];
			numList[j - 1] = temp;
			j--;
		}
	}

	//convert array to int
	int out = 0;
	int j = numList.size();

	for (int i = 0; i < numList.size(); i++)
	{
		out += numList[i] * pow(10, --j);
	}

	return out;
}

//Not one of the problems, but makes kaprekar easier
int asc_digits(int digits)
{
	string dString = to_string(digits);
	vector<int> numList;

	//Convert string to int
	for (int i = 0; i < dString.length(); i++)
	{
		string t;
		t += dString[i];
		numList.push_back(atoi(t.c_str()));
	}

	for (int i = 0; i < numList.size(); i++)
	{
		int j = i;
		while (j > 0 && numList[j] < numList[j - 1]) //The < is the only difference between this and desc_digits
		{
			int temp = numList[j];
			numList[j] = numList[j - 1];
			numList[j - 1] = temp;
			j--;
		}
	}

	//convert array to int
	int out = 0;
	int j = numList.size();

	for (int i = 0; i < numList.size(); i++)
	{
		out += numList[i] * pow(10, --j);
	}

	return out;
}

//Val MUST be a 4-digit number
int kaprekar(int val)
{
	int out = 0;
	int kap = val;
	
	while (kap != 6174)
	{
		kap = desc_digits(kap) - asc_digits(kap);
		out++;
	}

	return out;
}

void insertArray(char arr[], int size, char val, int pos)
{
	for (int i = 0; i < size; i++)
	{
		char temp = arr[i];
		arr[i] = val;


	}
	//arr[pos] = val;
}


//Helpers for printReflow
bool isLetter(char val)
{
	return true;
}
bool isPunc(char val)
{
	return true;
}
int gedEndofStatement(const char * text, int textLen, int startInd)
{
	for (int i = 0; i < textLen; i++)
	{
		if (text[i] == '\n')
			return i;
	}
	return -1;
}

//void printReflow(char * text, int textLen, int lineLimit)
//{
//	string fullText = text;
//
//	string currentWord;
//	string tempRow;
//	string currentRow;
//	string newText;
//	int rowLength = 0;
//
//	for (int i = 0; i < fullText.length(); i++)
//	{
//		while (text[i] != *" " && text[i] != *"\n")
//		{
//			currentWord += text[i];
//		}
//		//Include the space at the end
//		if(text[i] == *" ")
//			currentWord += text[i];
//		if()
//
//	}
//}



void main()
{
	assert(largest_digit(235134) == 5);
	assert(largest_digit(1111111111) == 1);
	assert(largest_digit(-85) == 8);	//Not sure if this is correct or not...
	
	assert(desc_digits(98357) == 98753);
	assert(desc_digits(11) == 11);
	assert(desc_digits(53321) == 53321);

	assert(kaprekar(6174) == 0);
	assert(kaprekar(6589) == 2);

	char name[10] = "Terry  ";
	insertArray(name, 10, 'N', 6);

	printf("%s", name);
	
	printf("\n\nAll good ;D\n\n");
	system("pause");
}