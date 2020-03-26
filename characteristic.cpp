#include <iostream>
#include "characteristic.h"

//function to go through and check if there is anything in numstring except for 0-9 and .
//used to count the number of exponents to the period. this is then used in numConverter
bool IsItGood(char numString[], const int& c)
{
	char validChars[] = { '0','1','2','3','4','5','6','7','8','9' };
	bool retval = true;
	int period_cnter = 0;

	
	//goes till null character
	for (unsigned int i = 0; numString[i] != '\0'; i++)
	{
		//mini used to determine if only numbers 0-9 are found
		bool miniTest = false;
		for (unsigned int k = 0; k < 10; k++)
		{
			if (numString[i] == validChars[k]|| numString[i] == '.')
			{
				miniTest = true;
				break;
			}
		}
		//if there is more than one period
		if (numString[i] == '.')
		{
			period_cnter++;
		}
		if (miniTest == false)
		{
			std::cout << " the c_string received a non numeric number and I can't let you do that Dave." << std::endl;
			retval = false;
			return retval;
		}
	}
	//
	if (period_cnter > 1)
	{
		retval = false;
		std::cout << "There were to many periods. They were everywhere man! " << std::endl;
	}
	return retval;

}


//converts everything before the period

int numConverter(char* numString)
{
	char* begin = numString, *ptr = numString;
	int num = 0;
	int convNum = 0;
	int exp = -1; 
	int pwr = 1;

	if (*begin == '.')
		return 0; 

	int size = sizeof(numString);

	//is just used to find the amount of spaces the period. this can then be used to determine exponents. probably a better way though 
	while (*ptr != '.')
	{
		exp += 1;
		ptr++;
	}

	while ( *begin != '.')
	{

		//48 - 57 is the numbers 0-9 on the ascii chart
		convNum = (int)((*begin) - 48);

		//used to calc the power of ten exp times
		for (int i = 0; i < exp; i++)
		{
			pwr *= 10;
		}

		num += convNum * pwr;

		//reset pwrs to use again
		pwr = 1;
		//exp decreases since this loop goes from left to right and grab numbers from the greatest exponent
		exp--;
		std::cout << convNum;
		begin++;

	}

	return num;
}

bool characteristic(char numString[], int& retNum)
{
	
	if (!IsItGood(numString, retNum))
		return false;

	retNum = numConverter(numString);

	return true;
}

