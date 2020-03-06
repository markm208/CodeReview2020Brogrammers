#include <iostream>
#include "mantissa.h"

using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;
    
    	int c, n, d, n1, d1, n2, d2, n3, d3, n4, d4, n5, d5, n6, d6;

	char number[] = "123.456"; //regular float to test
	mantissa(number, n, d);
	cout << "The mantissa is " << n << " over " << d << endl;

	char number1[] = "0.456"; //float with leading zero to test
	mantissa(number1, n1, d1);
	cout << "The mantissa is " << n1 << " over " << d1 << endl;

	char number2[] = ".45"; //float with no leading numbers to test
	mantissa(number2, n2, d2);
	cout << "The mantissa is " << n2 << " over " << d2 << endl;

	char number3[] = "-123.456"; //negative float to test
	mantissa(number3, n3, d3);
	cout << "The mantissa is " << n3 << " over " << d3 << endl;

	char number4[] = "1t3.4R6"; //invalid number to test
	mantissa(number4, n4, d4);
	cout << "The mantissa is " << n4 << " over " << d4 << endl;

	char number5[] = "123"; //integer to test
	mantissa(number5, n5, d5);
	cout << "The mantissa is " << n5 << " over " << d5 << endl;

	char number6[] = "1-2+3.456"; //float with plus and minus sign to test
	mantissa(number6, n6, d6);
	cout << "The mantissa is " << n6 << " over " << d6 << endl;

    return 0;
}
