#include <iostream>
#include "add_subtract.h"

int main()
{
	//----------------------------------------both numbers positive -------------------------------------------------------------------
	char answer[10];
	int c1, n1, d1;
	int c2, n2, d2;

	c1 = 1;
	n1 = 1;
	d1 = 2;

	c2 = 2;
	n2 = 2;
	d2 = 3;

	//if the C string could hold at least the characteristic
	if (add(c1, n1, d1, c2, n2, d2, answer, 10))
	{
		//display string with answer 4.1666666
		std::cout << "SUM: " << answer << std::endl;
	}
	else
	{
		//display error message
		std::cout << "Those values could not be added" << std::endl;

	}

	//----------------------------------------first num negative, second positive ----------------------------------------------------
	char values[12] = { '0','0','0','0','0','0','0','0','0','0','0','0' };
	// i need to change this so that it works for any denominators
	if (add(-10, 1, 2, 2, 1, 4, values, 6))
	{
		std::cout << "SUM: " << values << std::endl;

	}
	else
	{

		std::cout << "Those values could not be added" << std::endl;
	}


	//----------------------------------------first num positive, second negative ----------------------------------------------------
	char values_2[12] = { '0','0','0','0','0','0','0','0','0','0','0','0' };
	if (add(1, 1, 2, -2, 1, 2, values_2, 9))
	{
		std::cout << "SUM: " << values_2 << std::endl;
	}
	else
	{
		std::cout << "Those values could not be added" << std::endl;
	}

	//---------------------------------------------both numbers negative ------------------------------------------------------------------
	char values_3[12] = { '0','0','0','0','0','0','0','0','0','0','0','0' };
	if (add(-3, 1, 6, -1, 1, 2, values_3, 9))
	{
		std::cout << "SUM: " << values_3 << std::endl;
	}
	else
	{
		std::cout << "Those values could not be added" << std::endl;
	}

	std::cout << std::endl;
	//-----------------------------------Subtract - both numbers positive ----------------------------------------------------------------------
	char other_values[10] = { };
	//the value passed for len must be at most the size of the array - 1 ...
	if (subtract(32, 34, 100, 1, 76, 100, other_values, 9))
	{
		std::cout << "DIFFERENCE: " <<  other_values << std::endl;
	}
	else
	{
	std::cout << "Those values could not be subtracted" << std::endl;
	}

	//-----------------------------------Subtract - first number negative, second number positive ----------------------------------------------------------------------
	char other_values_2[10] = { };
	//the value passed for len must be at most the size of the array - 1 ...
	if (subtract(-3, 2, 5, 1, 7, 8, other_values_2, 9))
	{
		std::cout << "DIFFERENCE: " << other_values_2 << std::endl;
	}
	else
	{
		std::cout << "Those values could not be subtracted" << std::endl;
	}

	//-----------------------------------Subtract - first number positive, second number negative ----------------------------------------------------------------------
	char other_values_3[10] = { };
	//the value passed for len must be at most the size of the array - 1 ...
	if (subtract(6, 1, 6, -4, 2, 3, other_values_3, 9))
	{
		std::cout << "DIFFERENCE: " << other_values_3 << std::endl;
	}
	else
	{
		std::cout << "Those values could not be subtracted" << std::endl;
	}
	

	//check that it returns false when the array is too small -----------------------------------------------------------------------------------------------------------
	char invalid[3] = {};
	if (add(12, 2, 5, 298, 4, 9, invalid, 2))
	{
		std::cout << "INVALID: " << invalid << std::endl;
	}
	else
	{
		std::cout << "Could not add - not enough space in array" << std::endl;
	}
	if (subtract(97, 2, 7, 32, 1,2, invalid, 2))
	{
		std::cout << "INVALID: " << invalid << std::endl;
	}
	else
	{
		std::cout << "Could not subtract - not enough space in array " << std::endl;
	}

	system("pause");
	return 0;
}
