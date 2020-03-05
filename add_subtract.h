#include <iostream>
//using namespace std;

int get_num_digits(int number);

//this function adds trailing zeros to parameter n 
void add_digits(int &n, int digits_to_add);

//we have to make sure that our two decimals have the same amount of digits
//if they don't, we will shift them so that all of the first digits are being summed, all of the second digits, etc 
void check_common_denominators(int d1, int d2, int &n1, int &n2);

//takes the base to the exponent power
int power(int base, int exponent);

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);