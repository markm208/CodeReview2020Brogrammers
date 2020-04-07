#pragma once;
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
int getImproperFractionNum(int& c, int& n, int& d);
void CharacteristicSplicer(int c, char result[], int size, bool totalNegCheck);
void FloatingPointSplicer(int n, int d, char result[], int crntSize, int alwdLen);
bool ValidateNumber(int x);