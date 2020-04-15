#include <iostream>
#pragma once
//using namespace std;

int get_num_digits(int number);

//takes the base to the exponent power
int power(int base, int exponent);

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len); 

//add the number to the result[] array, starting at index start_val
void add_to_array(int number, char result[], int start_val);

int absolute_value(int number);

//parameters are minimum numerator, maximum numerator, minimum denominator, and maximum denominator
//change our n1, n2, d1, and d2 values so that they can be added and subtracted
void make_common_denominators(int &min_num, int &max_num, int &min_denom, int &max_denom);

//make sure that our two fractions have the same denominator - if they dont, we will try to make them the same. Then, make an estimate of what that fraction would be in decimal format
void check_common_denominators(int &n1, int &n2, int &d1, int &d2);

//change the numerator values to have a sign that corresponds with the sign that their characteristic has 
void account_for_negatives(int &c1, int &n1, int &c2, int &n2);

//this function will check if we have enough room to store the characteristic, and if we do, it will add it to the result[] array
bool add_characteristic(int characteristic, int &num_digits, char result[], int len);

//if we have room to store the decimal point in our result[] array, we will do that in this function
void add_period(int num_digits, char result[], int len);

//add as many values past the decimal point as we have room for
void add_mantissa(int mantissa, int digits_used, char result[], int len);