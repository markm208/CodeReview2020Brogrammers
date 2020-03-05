#include <iostream>
#include "add_subtract.h"


using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;


    char values[8] = { };
	if (add(102, 23, 100, 49, 967, 1000, values, 8))
	{
		std::cout << "SUM: " << values << std::endl;

	}
	else
	{

		std::cout << "Those values could not be added" << std::endl;
	}

	char other_values[10] = { };
	if (subtract(102, 23, 100, 49, 156, 1000, other_values, 10))
	{
		std::cout << "DIFFERENCE: " <<  other_values << std::endl;
	}
	else
	{
	std::cout << "Those values could not be subtracted" << std::endl;
	}


    return 0;
}
