#include <iostream>
#include "multAndDivide.h"
using namespace std;

void AutoTest() {
	//testing isInt()
	cout << "Testing isInt()\n";
	int testVals[6] = { 1, 'a', '1'};
	cout << "You should be seeing 1 0 0 : ";
	for (int testVal : testVals) {
		cout << isInt(testVal) << " ";
	}
	cout << endl;

}
//*************************************************************************************************************************************
//determines if val is an integer
bool isInt(int val) {
	//we know it is at least an integer, and we are checking if it is a letter or char version of a number disguised as an int.
	//this does not work for things such as +, -, / etc.
	return (!isalpha(val) && !isdigit(val));
}
//*************************************************************************************************************************************
//This function multplies two numbers using their respective characteristic (c), numerartor (n), and denominator (d)
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
	bool flag = false;

	int tempn1, tempn2, c, n, d;

	//making the numbers improper fractions
	tempn1 = getImproperFractionNum(c1, n1, d1);
	tempn2 = getImproperFractionNum(c2, n2, d2);

	//calculating the answer in an improper fraction
	n = tempn1 * tempn2;
	d = d1 * d2;

	//converting the answer back into a proper fraction
	c = n / d;
	n = n - (c * d);

	int* number = 0;
	number = (numberSplicer(n, number));//doesn't like this or pass by reference




	return flag;
}
//*************************************************************************************************************************************
//This function divdes the first number by the second number using their respective characteristic (c), numerartor (n), and denominator (d)
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
	bool flag = false;
	return flag;
}

//takes a number's characteristic, numerator, and denominator and returns what would be the numerator of an improper fraction of the entire numer
int getImproperFractionNum(int& c, int &n, int& d) {

	return((c * d) + n);
}

int* numberSplicer(int num, int number[]) {
	
	int numLen = 0;
	int digit;
	while (num % 10 != 0 && numLen!= 9) {//while there still are digits and still room in the array
		digit = num % 10;//peel off last digit
		number[numLen] = digit;//is there a way to make it a char instead of an int?
		//cout << number[numLen];
		num = num / 10; //shift all digits
		numLen++;
	}

	number[numLen] = INT_MIN; //acting as "null terminator" for now
	return number;//number will be backwards
}