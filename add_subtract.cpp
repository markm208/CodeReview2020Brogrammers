#include <iostream>
#include "add_subtract.h"

int get_num_digits(int number)
{
	int copy =abs(number);
	int num_digits = 0;
	while (copy > 0)
	{
		copy = copy / 10;
		num_digits++;
	}
	return num_digits;
}

//this function adds trailing zeros to parameter n 
void add_digits(int &n, int digits_to_add)
{
	for (int i = 0; i < digits_to_add; i++)
	{
		n *= 10;
	}
}

//we have to make sure that our two decimals have the same amount of digits
//if they don't, we will shift them so that all of the first digits are being summed, all of the second digits, etc 
void check_common_denominators(int d1, int d2, int &n1, int &n2)
{
	int difference_between_digits = 0;

	int d1_num_digits = get_num_digits(d1);
	int d2_num_digits = get_num_digits(d2);
	if (d1_num_digits > d2_num_digits)
	{
		difference_between_digits = d1_num_digits - d2_num_digits;
		//we want to add as many zeros as we need to d2 so that it has the same number of digits as d1
		add_digits(n2, difference_between_digits);
	}
	//if d2_digits is greater than or equal to d1_digits 
	//if they are equal, difference_between_digits will be zero and we will not enter our for loop
	else
	{
		difference_between_digits = d2_num_digits - d1_num_digits;
		//we want to add as many zeros as we need to d2 so that it has the same number of digits as d1
		add_digits(n1, difference_between_digits);
	}

}

//takes the base to the exponent power
int power(int base, int exponent)
{
	int total = 1;
	for (int i = 0; i < exponent; i++)
	{
		total = total * base;
	}
	return total;
}

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool ret_val = true;
	int characteristic_sum = c1 + c2;

	int characteristic_digits = get_num_digits(characteristic_sum);

	//if we don't even have enough room in len to store the characteristic sum, we know we will return false
	if (characteristic_digits >= len)
	{
		ret_val = false;
	}
	else //if we have enough room to add our characteristic digits
	{

		check_common_denominators(d1, d2, n1, n2);
		int mantissa_sum = n1 + n2;
		int mantissa_digits = get_num_digits(mantissa_sum);

		int max_mantissa_input_digits;

		//figure out how many digits our input mantissa had
		if (get_num_digits(n1) > get_num_digits(n2))
		{
			max_mantissa_input_digits = get_num_digits(n1);
		}
		else
		{
			max_mantissa_input_digits = get_num_digits(n2);
		}

		//if our addition of the mantissa will end up greater than 1, we add 1 to our characteristic
		if (get_num_digits(mantissa_sum) > max_mantissa_input_digits)
		{
			characteristic_sum++;
			mantissa_sum = mantissa_sum - power(10, mantissa_digits - 1);
			mantissa_digits--;
		}

		//add the characteristic_sum to the result array
		sprintf_s(result, sizeof result, "%d", characteristic_sum);

		//if we have room to store the decimal point and some digits past the decimal, we will do that
		if (characteristic_digits + 1 < len)
		{
			result[characteristic_digits] = '.';
			//keep track of how many digits we have used so we don't go past the end of the array
			int digits_used = characteristic_digits + 1;
			
			
			while (digits_used < len - 1)
			{
                //if we are out of digits in the sum but still have more space in the array, add trailing zeros
				if (mantissa_digits == 0)
				{
					snprintf(result + digits_used, len - digits_used, "%d", 0);
				}
                //if we still have digits to add to the array, add them here
                else
                {
                    //extract the next digit in the mantissa
                    int next_mantissa_digit = mantissa_sum / power(10, mantissa_digits - 1);

                    //add it to the result array
                    snprintf(result + digits_used, len - digits_used, "%d", next_mantissa_digit);

                    //strip the digit we just added from our mantissa_sum so that we will move to the next digit
                    mantissa_sum = mantissa_sum - next_mantissa_digit * power(10, mantissa_digits - 1);


                    mantissa_digits--;
                }
                
				//keep track of how many digits we have used so we don't go past the length of the array
				digits_used++;
			}

		}

		//make sure the char array is null terminated
		result[len - 1] = '\0';
	}
	
	return ret_val;
}

bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool ret_val = add(c1, n1, d1, c2 * -1, n2 * -1, d2, result, len);
	return ret_val;
}