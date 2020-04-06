#include <iostream>
#include "add_subtract.h"

using namespace std;
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
    //first, we will check if we need to prep for a repeating decimal(if the denominator is a multiple of 3)
    if(d1 % 3 == 0)
    {
        int num = 0;
        //each of these shows the values of 1/3, 1/6, and 1/9 out to 10 decimal places and sets d1 to be what would correspond
        if(d1 == 3)
        {
            num = 333333333;
        }
        else if(d1 == 6)
        {
            num = 166666666;
        }
        else // if d1 == 9
        {
            num = 111111111;
        }
        n1 = num * n1;
        d1 = 1000000000;
    }
    //do the same thing for d2
   if(d2 % 3 == 0)
    {
        int num = 0;
        //each of these shows the values of 1/3, 1/6, and 1/9 out to 10 decimal places and sets d2 to be what would correspond
        if(d2 == 3)
        {
            num = 333333333;
        }
        else if(d2 == 6)
        {
            num = 166666666;
        }
        else // if d2 == 9
        {
            num = 111111111;
        }
        n2 = num * n2;
        d2 = 1000000000;
    }
   
   
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
bool add_characteristic(int characteristic, int &num_digits, int start_val, char result[], int len)
{
	bool ret_val = true;
	//start val will tell us where to put our number in the array - if it is negative, we have to start at result[1] to leave space for the negative symbol
    if(start_val > 0)
    {
		result[0] = '-';
		num_digits++;

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
        if(characteristic != 0)
        {
            //add the characteristic_sum to the result array
	    	add_to_array(characteristic, result, start_val);
        }
		
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
    int last_digit = 0;
	while (digits_used < len - 1)
		{
			//if we are out of digits in the difference but still have more space in the array, add trailing zeros
			if (mantissa_digits == 0)
			{
                if(last_digit % 3 == 0)
                {
                    add_to_array(last_digit, result, digits_used);

                }
                else
                {
				    add_to_array(0, result, digits_used);   
                }
                
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

                //keep track of our last digit in case we need to use it to make a repeating decimal
                last_digit = next_mantissa_digit;
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

	int mantissa_sum = n1 + n2;
	int mantissa_digits = get_num_digits(mantissa_sum);

	int characteristic_sum = c1 + c2;
    int characteristic_digits = get_num_digits(characteristic_sum);

    // we are formatting it where we don't want the zero in front of the decimal - ex: 0.54 will be written as .54
    if(characteristic_sum == 0)
    {
        characteristic_digits = 0;
    }

    // if the value is going to be negative, we have to add a minus sign on the front
    if(characteristic_sum < 0 || (mantissa_sum < 0 && characteristic_sum == 0))
    {
	    ret_val = add_characteristic(characteristic_sum, characteristic_digits, 1, result, len);
    }
    else
    {
       	ret_val = add_characteristic(characteristic_sum, characteristic_digits, 0, result, len);
    }
    

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

	//change our numerators so that they have the same denominators
	check_common_denominators(n1,n2,d1,d2);

    //add negatives to our mantissa if its characteristic is negative
	account_for_negatives(c1, n1, c2, n2);
	int mantissa_diff = n1 - n2;
	int mantissa_digits = get_num_digits(mantissa_diff);
    
	int characteristic_diff = c1 - c2;
	int characteristic_digits = get_num_digits(characteristic_diff);
    
    //we are formatting it where we do not display the zero before the decimal- ex: 0.54 will be written .54
    if(characteristic_diff == 0)
    {
        characteristic_digits = 0;
    }

    //if the value is negative, we will put a '-' in front of the number 
    if(characteristic_diff < 0 || (mantissa_diff < 0 && characteristic_diff == 0))
    {
	    ret_val = add_characteristic(characteristic_diff, characteristic_digits, 1, result, len);
    }
    else
    {
       	ret_val = add_characteristic(characteristic_diff, characteristic_digits, 0, result, len);
    }
			
	add_period(characteristic_digits, result, len);

	//keep track of how many digits we have used so we don't go past the end of the array
	int digits_used = characteristic_digits + 1;
    mantissa_diff = absolute_value(mantissa_diff);

	add_mantissa(mantissa_diff, digits_used, result, len);

	//make sure the char array is null terminated
	result[len - 1] = '\0';
		
	return ret_val;
}