#include <iostream>
#include "multAndDivide.h"

using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;


char answer[10];
int c1, n1, d1;
int c2, n2, d2;
 
c1 = -124;
n1 = 25;
d1 = 88;

c2 = 1;
n2 = 50;
d2 = 100;
 
if(multiply(c1, n1, d1, c2, n2, d2, answer, 7))
{
	cout << "(" << c1 << " * " << n1 << " / " << d1 << ") * (" << c2 << " * " << n2 << " / " << d2 << ") = ";
    char* ptr = answer;
    while (*ptr != '\n') {
        cout << *(ptr);
        ptr++;
    }
    cout << endl;
}
else
{
    cout << "There was an error with multply! :(\n";
}

if (divide(c1, n1, d1, c2, n2, d2, answer, 10))
{
    cout << "(" << c1 << " * " << n1 << " / " << d1 << ") / (" << c2 << " * " << n2 << " / " << d2 << ") = ";
    char* ptr = answer;
    while (*ptr != '\n') {
        cout << *(ptr);
        ptr++;
    }
    cout << endl;
}
else
{}
cout << "There was an error with divide! :((\n";
}
