#include <iostream>
#include "characteristic.h"

//is it good 
//could change to const& ?
bool IsItGood(char numString[], int& c)
{
	char validChars[] = { '0','1','2','3','4','5','6','7','8','9','.' };
	bool retval = true;
	int period_cnter = 0;

	//goes till null character
	for (unsigned int i = 0; numString[i] != '\0'; i++)
	{
		//mini used to determine 
		bool miniTest = false;
		for (unsigned int k = 0; k < 11; k++)
		{
			if (numString[i] == validChars[k])
			{
				miniTest = true;
				break;
			}
		}
		//if there is more than one period
		if (numString[i] == validChars[10])
		{
			period_cnter++;
		}
		if (miniTest == false)
		{
			return false;
		}
	}
	//
	if (period_cnter > 1)
		retval = false;
	return retval;

}

bool characteristic(char numString[], int& c)
{
	if (!IsItGood(numString, c))
	{
		std::cout << "bad c_string " << std::endl;
		return false;
	}

	else
		std::cout << " its fine, it's fine" << std::endl;

	c = atoi(&numString[0]);
		
	return true;
}

