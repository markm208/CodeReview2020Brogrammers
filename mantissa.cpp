#include "mantissa.h"
#include <iostream>

using namespace std;

bool mantissa(char numString[], int & numerator, int & denominator)
{
	bool isValid = false;
	int cstringLength = 0;
	int cstringIterator = 0;
	int nonNumericCounter = 0; //will count random symbols in cstring

	char filteredNumString['0']; //new cstring with filtered values

	while (numString[cstringIterator]) //looping through unfiltered cstring
	{
		if (numString[cstringIterator] > 64 && numString[cstringIterator] < 123) //checking for letters
		{
			isValid = false;
			break;
		}
		else if (numString[cstringIterator] > 45 && numString[cstringIterator] < 58) //making sure only numbers and decimals get passed through
		{
			filteredNumString[cstringLength] = numString[cstringIterator]; //adding the valid characters to the new cstring
			cstringLength++; 
		}
		else
		{
			nonNumericCounter++; 
		}

		cstringIterator++;

		isValid = true;
	}
	
	cstringLength = cstringLength + nonNumericCounter; 

	if (isValid) 
	{
		int decimalPosition;
		denominator = 1; //power of ten that will be multiplied by individual character number

		for (int i = 0; i < cstringLength; i++) //Finding position of decimal point
		{
			if (numString[i] == '.')
			{
				decimalPosition = i;
				numerator = 0;

				for (int i = cstringLength - 1; i > decimalPosition; i--) //Calculating numerator
				{
					numerator = ((numString[i] - '0') * denominator) + numerator; //converting character to integer 
					denominator = denominator * 10;
				}
				return true;
			}				
		}
		numerator = 0; //if no decimal is found, automatically gets set to 0 over 10
		denominator = 10;

		return true;
	}
	else
	{
		return false;
	}
	return false;
}

