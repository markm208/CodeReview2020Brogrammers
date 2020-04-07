#include <iostream>
#include "multAndDivide.h"
using namespace std;

//This function multplies two numbers using their respective characteristic (c), numerartor (n), and denominator (d)
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {

	bool retVal = false; //initially false, but if it works it becomes true

	//Checks for all the integer values to
	if(!ValidateNumber(c1)){//if not valid
		return retVal;
	}
	else if(n1 < 0 || !ValidateNumber(n1)){//if negative or its not valid
		return retVal;
	}
	else if(d1 < 1 || !ValidateNumber(d1)){//if negative, 0, or not valid
		return retVal;
	}
	else if(!ValidateNumber(c2)){//if not valid
		return retVal;
	}
	else if(n2 < 0 || !ValidateNumber(n2)){//if neg or not valid
		return retVal;
	}
	else if(d2 < 1 || !ValidateNumber(d2)){//if neg, 0, or not valid
		return retVal;
	}
	else if(len <= 0){//if not viable length
		return retVal;
	}

	//taking care of negatives
	bool negCheck1 = false;//is the first ch a neg?
	if (c1 < 0){
		negCheck1 = true;
		c1 = c1 * -1;
	}
	bool negCheck2 = false;//is the second ch a neg?
	if (c2 < 0) {
		negCheck2 = true;
		c2 = c2 * -1;
	}
	bool totalNegCheck = !(negCheck1 && negCheck2);//is the whole thing negative?

	//temps are for holding numerators of improper fractions to complete the needed math
	// c,n, and d are the variables to hold the final results
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

	//this is counting the size of the characteristic
	int size = 1; //we start at 1 because the last division will = 0
				   //but that was a position and we know there will be at least a 0 if no characterisitc

	int tempc = c; //variable to destroy while finding size
	while((tempc/10) != 0){
		tempc = tempc/10;
		size += 1;
	}

	if (totalNegCheck) {//if one of the characteristics were negative and not both.
		size++; // add one to size because we will need to include a '-' symbol
	}

	if(size >= len){ //
		return retVal; //we do not have enough room!
	}

	CharacteristicSplicer(c, result, size, totalNegCheck);

	//We have the characterisitic, but we need to see if we can add a floating point and then a null terminator
	if(size == len - 1){ //if we only have 1 space left for '\n'
		result[size] = '\n';
		retVal = true;
	}
	else if(size == (len - 2)){//if there would only be room for the '.' and no numbers, don't put it in

		result[size] = '\n';
		retVal = true;
	}
	else{//we have room

		FloatingPointSplicer(n, d, result, size, len);

		result[len- 1] = '\n';
		retVal = true;

	}
	
	return retVal;
}
//*************************************************************************************************************************************
//This function divdes the first number by the second number using their respective characteristic (c), numerartor (n), and denominator (d)
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {

	if (!ValidateNumber(c2)){
		return false;
	}
	else if (n2 < 0 || !ValidateNumber(n2)) {
		return false;
	}
	else if (d2 < 1 || !ValidateNumber(d2)) {
		return false;
	}

	//seeing if number 2 is negative
	bool negCheck = false;
	if (c2 < 0) {
		negCheck = true;
		c2 = c2 * -1;

	}
	int tempNum2 = getImproperFractionNum(c2, n2, d2);
	n2 = d2;
	d2 = tempNum2;

	c2 = n2 / d2;
	n2 = n2 - (c2 * d2);

	if (negCheck) {
		c2 = c2 * -1;
	}

	return multiply(c1, n1, d1, c2, n2, d2, result, len);
}

//takes a number's characteristic, numerator, and denominator and returns what would be the numerator of an improper fraction of the entire numer
int getImproperFractionNum(int& c, int &n, int& d) {

	return((c * d) + n);
}

//this function takes in the characteristic (c), the char array (result), 
//and the verified size and puts the characterisitic digits into the result array with NO null terminator behind
void CharacteristicSplicer(int c, char result[], int size, bool totalNegCheck) { 

	if (totalNegCheck) {
		result[0] = '-';
	}

	int iter = size - 1; //We are starting from the back but the index is 1 less than size
	int digit;
	int offset = (int)'0'; //this is the offset of ascii that from the int 0 to the char 0

	while (c % 10 != 0) {//while there still are digits
		digit = c % 10;//peel off last digit
		result[iter] = (char)(digit + offset);//reminder that size is now an iter that just started from the back because we peel from back
		c = c / 10; //shift all digits
		iter--;
	}
}

//this function takes in the numerator (n), denominator (d), the result char array (result), the current size of the result array (drntSize),
//and the allowed length of the result array (alwdLen). It returns the given result char array with a '.' and any following decimals if there are any,
//and if they fit.
void FloatingPointSplicer(int n, int d, char result[], int crntSize, int alwdLen){

	result[crntSize] = '.';
	crntSize++; //size is now functioning as an iter
	int offset = (int)'0';

	//how much room we have
	int room = alwdLen - 1 - crntSize; //-1 for '\n'

	//converting fraction into x/(10^y) notation by multiplying numerator by 10^room so that we get the number of decimal points we can fit to the left of the '.'
	int orderOfMagnitude = 1;
	for (int i = 0; i < room; i++) {
		orderOfMagnitude = orderOfMagnitude * 10;
	}
	n = n * orderOfMagnitude;

	int decimals = n / d; //this is an integer representing the decimals ie 0.123 is 123
	if (decimals < 10) {//if we only had room for one decimal
		result[crntSize] = decimals + offset; //making decimal the char of itself
	}
	else{

		//temp d is a power of 10 used to splice the decimals
		int tempd = 1;
		for (int i = 0; i < room; i++) {
			tempd = tempd * 10;
		}
		while(crntSize != alwdLen-1){
			tempd = tempd / 10; //I want to get the first decimal place
			int digit = (decimals / tempd); //decimal retrieved from front
			result[crntSize] = digit + offset; //making decimal the char of itself

			//post prep
			crntSize++;
			decimals = decimals - (digit * tempd); //this is making the numerator the original without the first number
		}
	}

}

//this function takes in a number and only validats that it is in fact a number. (It does not check for negatives)
bool ValidateNumber(int x){
	bool retVal = true;
	int digit;

	while (x % 10 != 0) {//while there still are digits
		digit = x % 10;//peel off last digit
		if(digit < -9 || digit > 9){
			retVal = false;
			break;
		}
		x = x / 10; //shift all digits
	}
	return retVal;
}