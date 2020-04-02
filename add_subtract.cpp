#include <iostream>
#include "add_subtract.h"

//this function returns the absolute value of a number
int absolute_value(int number)
{
	int ret_val = number;
	if (number < 0)
	{
		ret_val = number * -1;
	}
	return ret_val;
}
//this function returns the number of digits in a number
int get_num_digits(int number)
{
	int num_digits = 0;
	//if the number is zero, we want to return 1
	if (number == 0)
	{
		num_digits = 1;
	}
	//otherwise, we have to do some arithmetic to figure out the number of digits
	else
	{
		int copy = absolute_value(number);
		while (copy > 0)
		{
			copy = copy / 10;
			num_digits++;
		}
	}
	
	return num_digits;
}

//parameters are minimum numerator, maximum numerator, minimum denominator, and maximum denominator
void make_common_denominators(int &min_num, int &max_num, int &min_denom, int &max_denom)
{
	//if they are multiples of each other, we just have to multiply to make them have the same denominators
	if (max_denom % min_denom == 0)
	{
		min_num = min_num * (max_denom / min_denom);
		min_denom = min_denom * (max_denom / min_denom);
		
	}
	//if they are not multiples of each other, we will multiply the denominators to get our new denominator, and adjust the numerators accordingly
	else
	{
		int denominator = min_denom * max_denom;
		min_num = min_num * max_denom;
		max_num = max_num * min_denom;

		min_denom = denominator;
		max_denom = denominator;
	}
}

//make sure that our two fractions have the same denominator - if they dont, we will try to make them the same. Then, make an estimate of what that fraction would be in decimal format
void check_common_denominators(int &n1, int &n2, int &d1, int &d2)
{
	//if d1 and d2 are already equal, we don't have to do anything
	if (d1 != d2)
	{
		//pass into our function the smaller denominator first, and its corresponding numerator
		if (d1 > d2)
		{
			make_common_denominators(n2, n1, d2, d1);
		}
		else
		{
			make_common_denominators(n1, n2, d1, d2);
		}
	}
	
	//make the denominators as close to a multiple of 10 as possible
	int next_multiple = 10;
	while (next_multiple % d1 != 0)
	{
		next_multiple = next_multiple * 10;

		//if we have tried to find a denominator that works this many times, we will assume that the decimal is irrational, and we will give our best estimation of it
		if (next_multiple > 100000000)
		{
			break;
		}
	}
	int multiplier = next_multiple / d1;
	d1 = d1 * multiplier;
	d2 = d2 * multiplier;
	n1 = n1 * multiplier;
	n2 = n2 * multiplier;

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

//add the number to the result[] array, starting at index start_val
void add_to_array(int number, char result[], int start_val)
{
	int num_digits = get_num_digits(number);
	
	while (num_digits > 0)
	{
		int next_char = number / power(10, num_digits - 1);
		if (next_char == 0)
		{
			result[start_val] = '0';
		}
		else
		{
			// '0' will give us the ascii code for 0, and then we want to add next_char to that 
			result[start_val] = next_char + '0';
		}
		start_val++;
		number = number - next_char * power(10, num_digits - 1);
		num_digits--;

	}

}

//this function will check if we have enough room to store the characteristic, and if we do, it will add it to the result[] array
bool add_characteristic(int characteristic, int &num_digits, char result[], int len)
{
	bool ret_val = true;
	//start val will tell us where to put our number in the array - if it is negative, we have to start at result[1] to leave space for the negative symbol
	int start_val = 0;
	if (characteristic < 0)
	{
		result[0] = '-';
		num_digits++;
		start_val++;
		//now that we have added our negative sign, we dont need to worry about the sign of the characteristic anymore
		characteristic = absolute_value(characteristic);
	}
	//if we don't even have enough room in len to store the characteristic difference, we know we will return false
	if (num_digits >= len - 1)
	{
		ret_val = false;
	}
	else //if we have enough room to add our characteristic digits
	{
		//add the characteristic_sum to the result array
		add_to_array(characteristic, result, start_val);
	}
	return ret_val;
}

//if we have room to store the decimal point in our result[] array, we will do that in this function
void add_period(int num_digits, char result[], int len)
{
	if (num_digits + 1 < len)
	{
		result[num_digits] = '.';
	}
}

//add as many values past the decimal point as we have room for
void add_mantissa(int mantissa, int digits_used, char result[], int len)
{
	int mantissa_digits = get_num_digits(mantissa);
	while (digits_used < len - 1)
		{
			//if we are out of digits in the difference but still have more space in the array, add trailing zeros
			if (mantissa_digits == 0)
			{
				add_to_array(0, result, digits_used);
			}
			//if we still have digits to add to the array, add them here
			else
			{
				//extract the next digit in the mantissa
				int next_mantissa_digit = mantissa / power(10, mantissa_digits - 1);
				//add it to the result array
				add_to_array(next_mantissa_digit, result, digits_used);
				//strip the digit we just added from our mantissa_sum so that we will move to the next digit
				mantissa = mantissa - next_mantissa_digit * power(10, mantissa_digits - 1);

				mantissa_digits--;
			}

			//keep track of how many digits we have used so we don't go past the length of the array
			digits_used++;
		}

}

//change the numerator values to have a sign that corresponds with the sign that their characteristic has 
void account_for_negatives(int &c1, int &n1, int &c2, int &n2)
{
	if (c1 < 0)
	{
		n1 = n1 * -1;
	}
	
	if (c2 < 0)
	{
		n2 = n2 * -1;
	}
}
//adds two numbers together - the characteristics(c1 and c2), the numerators of the matissa(n1 and n2),  the denominators of the two numbers (d1 and d2), a character array to return the result, and the length that we have to store it
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool ret_val = true;	
	//change our fractions to make sure they have the same denominator
	check_common_denominators(n1, n2, d1, d2);
	account_for_negatives(c1, n1, c2, n2);
	int input_digits = get_num_digits(d1 - 1);

	int mantissa_sum = n1 + n2;

	int mantissa_digits = get_num_digits(mantissa_sum);


	bool changed_characteristic = false;
	//if one of our two inputs was negative and the other was not, we have to look at the sum of the mantissas to see if we have to modify the characteristic
	if (((n1 > 0 && n2 < 0) || (n2 > 0 && n1 < 0)))
	{
		if (mantissa_sum < 0)
		{
			if (n1 > 0)
			{
				c1--;
				mantissa_sum = power(10, mantissa_digits) - absolute_value(mantissa_sum);
			}

		}
		else if (mantissa_sum > 0)
		{
			if (n2 < 0)
			{
				c1++;
				mantissa_sum = power(10, mantissa_digits) - absolute_value(mantissa_sum);
			}
		}
	}


	//at this point, if we change our characteristic, we know that the n1 and n2 must have been the same size
	if (mantissa_digits > input_digits)
	{
		if (n1 < 0)
		{
			c1--;
			changed_characteristic = true;
		}
		else //if n1 is positive
		{
			c1++;
			changed_characteristic = true;

		}
	}
	if (changed_characteristic)
	{
		mantissa_sum = absolute_value(mantissa_sum) - power(10, mantissa_digits - 1);
	}
	

	int characteristic_diff = c1 + c2;
	int characteristic_digits = get_num_digits(characteristic_diff);
	ret_val = add_characteristic(characteristic_diff, characteristic_digits, result, len);
	
	add_period(characteristic_digits, result, len);
	//keep track of how many digits we have used so we don't go past the end of the array
	int digits_used = characteristic_digits + 1;
	add_mantissa(absolute_value(mantissa_sum), digits_used, result, len);

	//make sure the char array is null terminated
	result[len - 1] = '\0';

	return ret_val;

}
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool ret_val = true;

	//change our mantissa so that they have the same values
	check_common_denominators(n1,n2,d1,d2);
	account_for_negatives(c1, n1, c2, n2);
	int mantissa_diff = n1 - n2;
	int mantissa_digits = get_num_digits(mantissa_diff);
	int input_digits = get_num_digits(d1 - 1);
	//in certain cases, we will need to change our characteristic depending on our new mantissa
	if ((n1 < 0 && n2 > 0) || (n2 < 0 && n1 > 0))
	{
		if (mantissa_digits > input_digits)
		{
			mantissa_diff = power(10, mantissa_digits - 1) - absolute_value(mantissa_diff);
			if (n1 < 0)
			{
				c1--;
			}
			else
			{
				c1++;
			}
		}
	}

	if (mantissa_diff < 0)
	{
		if (n1 > 0)
		{
			c1--;
			mantissa_diff = power(10, mantissa_digits - 1) - absolute_value(mantissa_diff);
		}

	}
	else if (mantissa_diff > 0)
	{
		if (n1 < 0)
		{
			c1++;
			mantissa_diff = power(10, mantissa_digits - 1) - absolute_value(mantissa_diff);
		}
	}
	
	mantissa_diff = absolute_value(mantissa_diff);
	int characteristic_diff = c1 - c2;
	int characteristic_digits = get_num_digits(characteristic_diff);
	ret_val = add_characteristic(characteristic_diff, characteristic_digits, result, len);
			
	add_period(characteristic_digits, result, len);
	//keep track of how many digits we have used so we don't go past the end of the array
	int digits_used = characteristic_digits + 1;
	add_mantissa(mantissa_diff, digits_used, result, len);

	//make sure the char array is null terminated
	result[len] = '\0';
		
	return ret_val;
}