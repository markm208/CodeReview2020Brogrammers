#include <iostream>
#include "characteristic.h"

//function to go through and check if there is anything in numstring except for 0-9 and .
//used to count the number of exponents to the period. this is then used in numConverter
bool IsItGood(const char numString[], int& c)
{
	
	char validChars[] = { '0','1','2','3','4','5','6','7','8','9',' ','-', '+'};
	bool retval = true,is_neg = false, has_num = false;
	int period_cnter = 0;
	int cnt = 0;
	char arr[2000],*ptr = arr;
	
	//goes till null character
	for (unsigned int i = 0; numString[i] != '\0'; i++)
	{
		if (numString[i] == '-')
		{
			is_neg = true;
		}
		//mini used to determine if only numbers 0-9 are found
		bool miniTest = false;
		for (unsigned int k = 0; k < 13; k++)
		{
			if (numString[i] == validChars[k]|| numString[i] == '.')
			{
				if (numString[i] != ' ' && numString[i] != '+' && numString[i] != '-')
				{
					if (numString[i] != '.')
					{
						has_num = true;
					}
					*ptr = numString[i];
					miniTest = true;
					ptr++;
				    break;
				}
				else
				{
					miniTest = true;
					break;
				}
			}
		}
		
		//if there is more than one period
		if (numString[i] == '.')
		{
			period_cnter++;
		}
		if (miniTest == false)
		{
		//	std::cout << " the c_string received a non numeric number and I can't let you do that Dave." << std::endl;
			retval = false;
			return retval;
		}
		cnt++;
	}
	//
	if (period_cnter > 1)
	{
		retval = false;
		std::cout << "There were to many periods. They were everywhere man! " << std::endl;
	}
	*ptr = '\0';
	c = numConverter(arr,is_neg);
	return (retval && has_num);

}


//converts everything before the period

int numConverter(const char* numString, bool isneg)
{
	const char* begin = numString, *ptr = numString;
	int num = 0;
	int convNum = 0;
	int exp = -1; 
	int pwr = 1;
	//bool isneg = false; 

	if (*begin == '.')
		return 0; 
	int size = sizeof(numString);

	//is just used to find the amount of spaces after the period. this can then be used to determine exponents. probably a better way though 
	while (*ptr != '.' && *ptr != '\0' )
	{
		exp += 1;
		ptr++;
	}

	while ( *begin != '.' && *begin != '\0')
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
		//std::cout << convNum;
		begin++;

	}
	if (isneg == true)
		num = num * -1;
	return num;
}

bool characteristic(const char numString[], int& retNum)
{
	
	if (!IsItGood(numString, retNum))
		return false;;

	return true;
}

