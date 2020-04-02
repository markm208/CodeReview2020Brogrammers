#include <iostream>
#include "add_subtract.h"

void testCharacteristicAndMantissa();
void shouldConvert(char number[], int expectedCharacteristic, int expectedNumerator, int expectedDenominator);
void shouldNotConvert(char number[]);

void testMath();
void testAdd();
void testSubtract();
void testMultiply();
void testDivide();

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


	//return 0;
    //characteristic and mantissa test
    testCharacteristicAndMantissa();
    
    //math function tests
    testMath();
    system("pause");
    return 0;
//>>>>>>> main-tests
}
//--
void testCharacteristicAndMantissa()
{
    //number with a non-zero characteristic a decimal point and a non-zero mantissa
    shouldConvert("123.456", 123, 456, 1000);
    shouldConvert("    123.456", 123, 456, 1000);
    shouldConvert("123.456    ", 123, 456, 1000);
    shouldConvert("    123.456    ", 123, 456, 1000);
    //unary plus/minus
    shouldConvert("+123.456", 123, 456, 1000);
    shouldConvert("   +123.456", 123, 456, 1000);
    shouldConvert("+123.456   ", 123, 456, 1000);
    shouldConvert("   +123.456   ", 123, 456, 1000);
    shouldConvert("-123.456", -123, 456, 1000);
    shouldConvert("   -123.456", -123, 456, 1000);
    shouldConvert("-123.456   ", -123, 456, 1000);
    shouldConvert("    -123.456   ", -123, 456, 1000);

    //number with a zero characteristic and a non-zero mantissa
    shouldConvert("0.456", 0, 456, 1000);
    shouldConvert("   0.456", 0, 456, 1000); 
    shouldConvert("0.456   ", 0, 456, 1000);
    shouldConvert("   0.456   ", 0, 456, 1000);
    //unary plus/minus
    shouldConvert("-0.456", 0, -456, 1000);
    shouldConvert("   -0.456", 0, -456, 1000);
    shouldConvert("-0.456   ", 0, -456, 1000);
    shouldConvert("   -0.456   ", 0, -456, 1000);
    shouldConvert("+0.456", 0, -456, 1000);
    shouldConvert("   +0.456", 0, -456, 1000);
    shouldConvert("+0.456   ", 0, -456, 1000);
    shouldConvert("   +0.456   ", 0, -456, 1000);

    //number with no characteristic digits and a non-zero mantissa
    shouldConvert(".456", 0, 456, 1000);
    shouldConvert("    .456", 0, 456, 1000);
    shouldConvert(".456   ", 0, 456, 1000);
    shouldConvert("   .456   ", 0, 456, 1000);
    //unary plus/minus
    shouldConvert("-.456", 0, -456, 1000);
    shouldConvert("    -.456", 0, -456, 1000);
    shouldConvert("-.456   ", 0, -456, 1000);
    shouldConvert("   -.456   ", 0, -456, 1000);
    shouldConvert("+.456", 0, -456, 1000);
    shouldConvert("    +.456", 0, -456, 1000);
    shouldConvert("+.456   ", 0, -456, 1000);
    shouldConvert("   +.456   ", 0, -456, 1000);

    //number with a non-zero characteristic and no mantissa
    shouldConvert("123456", 123456, 0, 10);
    shouldConvert("   123456", 123456, 0, 10);
    shouldConvert("123456   ", 123456, 0, 10);
    shouldConvert("   123456   ", 123456, 0, 10);
    //unary plus/minus
    shouldConvert("-123456", -123456, 0, 10);
    shouldConvert("   -123456", -123456, 0, 10);
    shouldConvert("-123456   ", -123456, 0, 10);
    shouldConvert("   -123456   ", -123456, 0, 10);
    shouldConvert("+123456", -123456, 0, 10);
    shouldConvert("   +123456", -123456, 0, 10);
    shouldConvert("+123456   ", -123456, 0, 10);
    shouldConvert("   +123456   ", -123456, 0, 10);

    //number with a non-zero characteristic and a zero mantissa
    shouldConvert("123456.0", 123456.0, 0, 10);
    shouldConvert("   123456.0", 123456.0, 0, 10);
    shouldConvert("123456.0   ", 123456.0, 0, 10);
    shouldConvert("   123456.0   ", 123456.0, 0, 10);
    //unary plus/minus
    shouldConvert("-123456.0", -123456, 0, 10);
    shouldConvert("   -123456.0", -123456, 0, 10);
    shouldConvert("-123456.0   ", -123456, 0, 10);
    shouldConvert("   -123456.0   ", -123456, 0, 10);
    shouldConvert("+123456.0", -123456, 0, 10);
    shouldConvert("   +123456.0", -123456, 0, 10);
    shouldConvert("+123456.0   ", -123456, 0, 10);
    shouldConvert("   +123456.0   ", -123456, 0, 10);

    //check leading and trailing zeros
    shouldConvert("000123.456", 123, 456, 1000);
    shouldConvert("123.45600000", 123, 456, 1000);
    shouldConvert("00000123.45600000", 123, 456, 1000);
    //unary plus/minus
    shouldConvert("-000123.456", -123, 456, 1000);
    shouldConvert("-123.45600000", -123, 456, 1000);
    shouldConvert("-00000123.45600000", -123, 456, 1000);
    shouldConvert("+000123.456", -123, 456, 1000);
    shouldConvert("+123.45600000", -123, 456, 1000);
    shouldConvert("+00000123.45600000", -123, 456, 1000);

    //significant zeros in mantissa
    shouldConvert("123.00000456", 123, 456, 100000000);
    shouldConvert("-123.00000456", -123, 456, 100000000);
    shouldConvert("+123.00000456", 123, 456, 100000000);

    //these should fail
    shouldNotConvert("");
    shouldNotConvert("+");
    shouldNotConvert("-");
    shouldNotConvert(".");
    shouldNotConvert("cat");
    shouldNotConvert("    ");
    shouldNotConvert("123.cat");
    shouldNotConvert("cat.123");
    shouldNotConvert("-cat");
}
//--
void shouldConvert(char number[], int expectedCharacteristic, int expectedNumerator, int expectedDenominator)
{
    int c, n, d;

    //if the conversion from C string to integers can take place
    if (characteristic(number, c) && mantissa(number, n, d))
    {
        if (c == expectedCharacteristic && n == expectedNumerator && d == expectedDenominator)
        {
            //test passes, do not print anything on a successful test
        }
        else
        {
            cout << "Test failed: '" << number << "' "
                << "was parsed but did not produce the expected results" << endl;

            if (expectedCharacteristic != c)
            {
                cout << "expected characteristic: " << expectedCharacteristic << " "
                    << "actual characteristic: " << c << endl;
            }

            if (expectedNumerator != n)
            {
                cout << "expected numerator: " << expectedNumerator << " "
                    << "actual numerator: " << n << endl;

            }

            if (expectedDenominator != d)
            {
                cout << "expected denominator: " << expectedDenominator << " "
                    << "actual denominator: " << d << endl;
            }
        }
    }
    else
    {
        cout << "Test failed: '" << number << "' "
            << "was NOT parsed when it should have been." << endl;
    }
}
//--
void shouldNotConvert(char number[])
{
    int c, n, d;

    //if the conversion from C string to integers can take place
    if (characteristic(number, c) && mantissa(number, n, d))
    {
        cout << "Test failed: '" << number << "' "
            << "was parsed when it should NOT have been." << endl;
    }
}
//--
void testMath()
{
    //add
    testAdd();
    testSubtract();
    testMultiply();
    testDivide();
}
//--
void testAdd()
{
    const int SHORT_ARRAY_LENGTH = 5;
    char shortArray[SHORT_ARRAY_LENGTH];

    const int MEDIUM_ARRAY_LENGTH = 10;
    char mediumArray[MEDIUM_ARRAY_LENGTH];

    const int LARGE_ARRAY_LENGTH = 20;
    char largeArray[LARGE_ARRAY_LENGTH];

    //should not be enough space in the array for the result
    if (add(INT_MAX, 0, 10, INT_MAX, 0, 10, shortArray, SHORT_ARRAY_LENGTH))
    {
        cout << "Error: not enough space in array" << endl;
    }

    //0 + 0 = "0"
    add(0, 0, 10, 0, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, 0, 10);
    add(0, 0, 10, 0, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, 0, 10);
    add(0, 0, 10, 0, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 0, 0, 10);

    //1 + 1 = "2"
    add(1, 0, 10, 1, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 2, 0, 10);
    add(1, 0, 10, 1, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 2, 0, 10);
    add(1, 0, 10, 1, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 2, 0, 10);

    //1 + -1.5 = "-.5"
    add(1, 0, 10, -1, 1, 2, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, -5, 10);
    add(1, 0, 10, -1, 1, 2, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, -5, 10);
    add(1, 0, 10, -1, 1, 2, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 0, -5, 10);

    //1.125 + 1.6R = "2.79"
    add(1, 1, 8, 1, 2, 3, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 2, 79, 100);

    //1.125 + 1.6R = "2.7916666"
    add(1, 1, 8, 1, 2, 3, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 2, 7916666, 10000000);

    //1.125 + 1.6R = "2.79166666666666666"
    add(1, 1, 8, 1, 2, 3, largeArray, LARGE_ARRAY_LENGTH);
    //can't use the convert function because the num/denom would overflow
    char expectedResult[] = "2.79166666666666666";
    for (int i = 0; i < LARGE_ARRAY_LENGTH; i++)
    {
        if (expectedResult[i] != largeArray[i])
        {
            cout << "Error: mismatch in C strings in add()." << endl
                << "Expected: " << expectedResult << " "
                << "Actual: " << largeArray
                << endl;
        }
    }
}
//--
void testSubtract()
{
    const int SHORT_ARRAY_LENGTH = 5;
    char shortArray[SHORT_ARRAY_LENGTH];

    const int MEDIUM_ARRAY_LENGTH = 10;
    char mediumArray[MEDIUM_ARRAY_LENGTH];

    const int LARGE_ARRAY_LENGTH = 20;
    char largeArray[LARGE_ARRAY_LENGTH];

    //should not be enough space in the array for the result
    if (subtract(INT_MIN, 0, 10, INT_MAX, 0, 10, shortArray, SHORT_ARRAY_LENGTH))
    {
        cout << "Error: not enough space in array" << endl;
    }

    //0 - 0 = "0"
    subtract(0, 0, 10, 0, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, 0, 10);
    subtract(0, 0, 10, 0, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, 0, 10);
    subtract(0, 0, 10, 0, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 0, 0, 10);

    //2 - 1 = "1"
    subtract(2, 0, 10, 1, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 1, 0, 10);
    subtract(2, 0, 10, 1, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 1, 0, 10);
    subtract(2, 0, 10, 1, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 1, 0, 10);

    //1 - -1.5 = "2.5"
    subtract(1, 0, 10, -1, 1, 2, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 2, 5, 10);
    subtract(1, 0, 10, -1, 1, 2, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 2, 5, 10);
    subtract(1, 0, 10, -1, 1, 2, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 2, 5, 10);

    //1.125 - 1.6R = "-.54"
    subtract(1, 1, 8, 1, 2, 3, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, -54, 100);

    //1.125 - 1.6R = "-.5416666"
    subtract(1, 1, 8, 1, 2, 3, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, -5416666, 10000000);

    //1.125 - 1.6R = "-.54166666666666666"
    subtract(1, 1, 8, 1, 2, 3, largeArray, LARGE_ARRAY_LENGTH);
    //can't use the convert function because the num/denom would overflow
    char expectedResult[] = "-.54166666666666666";
    for (int i = 0; i < LARGE_ARRAY_LENGTH; i++)
    {
        if (expectedResult[i] != largeArray[i])
        {
            cout << "Error: mismatch in C strings in subtract()." << endl
                << "Expected: " << expectedResult << " "
                << "Actual: " << largeArray
                << endl;
        }
    }
}
//--
void testMultiply()
{
    const int SHORT_ARRAY_LENGTH = 5;
    char shortArray[SHORT_ARRAY_LENGTH];

    const int MEDIUM_ARRAY_LENGTH = 10;
    char mediumArray[MEDIUM_ARRAY_LENGTH];

    const int LARGE_ARRAY_LENGTH = 20;
    char largeArray[LARGE_ARRAY_LENGTH];

    //should not be enough space in the array for the result
    if (multiply(INT_MAX, 0, 10, INT_MAX, 0, 10, shortArray, SHORT_ARRAY_LENGTH))
    {
        cout << "Error: not enough space in array" << endl;
    }

    //0 * 0 = "0"
    multiply(0, 0, 10, 0, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, 0, 10);
    multiply(0, 0, 10, 0, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, 0, 10);
    multiply(0, 0, 10, 0, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 0, 0, 10);

    //3 * 2 = "6"
    multiply(3, 0, 10, 2, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 6, 0, 10);
    multiply(3, 0, 10, 2, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 6, 0, 10);
    multiply(3, 0, 10, 2, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 6, 0, 10);

    //3 * -1.5 = "-4.5"
    multiply(3, 0, 10, -1, 1, 2, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, -4, 5, 10);
    multiply(3, 0, 10, -1, 1, 2, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, -4, 5, 10);
    multiply(3, 0, 10, -1, 1, 2, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, -4, 5, 10);

    //1.125 * 1.6R = "1.87"
    multiply(1, 1, 8, 1, 2, 3, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 1, 87, 100);

    //1.125 * 1.6R = "1.875"
    multiply(1, 1, 8, 1, 2, 3, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 1, 875, 1000);

    //1.125 * 1.6R = "1.875"
    multiply(1, 1, 8, 1, 2, 3, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 1, 875, 1000);
}
//--
void testDivide()
{
    const int SHORT_ARRAY_LENGTH = 5;
    char shortArray[SHORT_ARRAY_LENGTH];

    const int MEDIUM_ARRAY_LENGTH = 10;
    char mediumArray[MEDIUM_ARRAY_LENGTH];

    const int LARGE_ARRAY_LENGTH = 20;
    char largeArray[LARGE_ARRAY_LENGTH];

    //should not be enough space in the array for the result
    if (divide(INT_MAX, 0, 10, 1, 0, 10, shortArray, SHORT_ARRAY_LENGTH))
    {
        cout << "Error: not enough space in array" << endl;
    }

    //cannot divide by zero
    if (divide(10, 0, 10, 0, 0, 10, shortArray, SHORT_ARRAY_LENGTH))
    {
        cout << "Error: cannot divide by zero" << endl;
    }

    //0 / 1 = "0"
    divide(0, 0, 10, 1, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, 0, 10);
    divide(0, 0, 10, 1, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, 0, 10);
    divide(0, 0, 10, 1, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 0, 0, 10);

    //6 / 3 = "2"
    divide(6, 0, 10, 3, 0, 10, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 2, 0, 10);
    divide(6, 0, 10, 3, 0, 10, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 2, 0, 10);
    divide(6, 0, 10, 3, 0, 10, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 2, 0, 10);

    //1 / -1.5 = "-.66"
    divide(1, 0, 10, -1, 1, 2, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, -66, 100);
    
    //1 / -1.5 = "-.6666666"
    divide(1, 0, 10, -1, 1, 2, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, -6666666, 10000000);
    
    //1 / -1.5 = "-.66666666666666666"
    divide(1, 0, 10, -1, 1, 2, largeArray, LARGE_ARRAY_LENGTH);
    char expectedResult1[] = "-.66666666666666666";
    for (int i = 0; i < LARGE_ARRAY_LENGTH; i++)
    {
        if (expectedResult1[i] != largeArray[i])
        {
            cout << "Error: mismatch in C strings in divide()." << endl
                << "Expected: " << expectedResult1 << " "
                << "Actual: " << largeArray
                << endl;
        }
    }

    //1.125 / 1.6R = "0.67"
    divide(1, 1, 8, 1, 2, 3, shortArray, SHORT_ARRAY_LENGTH);
    shouldConvert(shortArray, 0, 67, 100);

    //1.125 / 1.6R = "0.675"
    divide(1, 1, 8, 1, 2, 3, mediumArray, MEDIUM_ARRAY_LENGTH);
    shouldConvert(mediumArray, 0, 675, 1000);

    //1.125 / 1.6R = "0.675"
    divide(1, 1, 8, 1, 2, 3, largeArray, LARGE_ARRAY_LENGTH);
    shouldConvert(largeArray, 0, 675, 1000);
}
