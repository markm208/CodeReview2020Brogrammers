#include <iostream>

#include "characteristic.h"

int main()
{
	//std::string yoooooooo = "was upppppp";
	//CString aCString = "A string";
	char badPerString[] = { '1','2','.','.','6','\0' };
	// .2345 = 0?
	char goodString[] = {'4' ,'.','2','3','4','5','\0' };
	char badAlphaString[] = { '1','2','3','4','l','.','0','\0' };
	int c;

	if (characteristic(goodString, c))
	{
		std::cout << " the final number is " << c;
	}
	else
	{
		std::cout << "Game over man, Game over......" << std::endl;
	}
}