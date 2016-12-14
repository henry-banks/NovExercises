// Zomawia Sailo
// zomawia@gmail.com

// problems.md

#include <cstdio>
#include <cmath>

int largest_digit(int digits) {
	// Write a function that, when given a 4-digit value, returns the largest digit of the value. 
	// For example, given 1234, you should return 4 which is the largest digit.
	if (digits == 0) return 0;

	return fmaxf(digits % 10, largest_digit(digits / 10));
}

int reverse(int digits) {
	// Write a function that, when given a 4-digit value, returns a 4-digit value with the individual digits rearranged in descending order. 
	// For example, if given 1234 the expected output should be 4321.
	int num = 0;
	while (digits > 0)
	{
		num = num * 10 + digits % 10;
		digits = digits / 10;
	}

	return num;

}

int desc_digits(int digits) {
	// Write a function that, when given a 4-digit value, returns a 4-digit value with the individual digits rearranged in descending order. 
	// For example, if given 1234 the expected output should be 4321.
	int num = 0;
	while (digits > 0)
	{
		num = num * 10 + digits % 10;
		digits = digits / 10;
	}

	return num;

}

int asc_digits(int digits) {

}

int kaprekar(int value) {
	// Write a function that counts the number of iterations in Kaprekar's Routine, which is as follows. 
	//	Given a 4-digit number that has at least two different digits, take that number's descending digits, and subtract that number's ascending digits. 
	//	For example, given 6589, you should take 9865 - 5689, which is 4176. Repeat this process with 4176 and you'll get 7641 - 1467, which is 6174.

	//	Once you get to 6174 you'll stay there if you repeat the process. In this case we applied the process 2 times before reaching 6174, so our output for 6589 is 2.
	int num = 0;

	while (value != 6174) {
		return kaprekar(desc_digits(value) - desc_digits(desc_digits(value) ) );
	}
	return 0;
}

int main() {

	int d = 1234;
	printf("%i \n", largest_digit(d) );
	printf("%i \n", reverse(d));

	int k = 6589;

	getchar();

}
