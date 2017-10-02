// Power.cpp : Defines the entry point for the console application.
//

// ¡¶½£Ö¸Offer¡ª¡ªÃûÆóÃæÊÔ¹Ù¾«½²µäÐÍ±à³ÌÌâ¡·´úÂë
// Öø×÷È¨ËùÓÐÕß£ººÎº£ÌÎ

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if(equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0 / result;
    std::cout << "pow(" << base << ", "<< exponent << ") = " << result << std::endl;
    return result;
}

/*
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;
    /
    for(int i = 1; i <= exponent; ++i)
        result *= base;

    return result;
}
*/

// Power with unsigned int number
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x01 == 1)
        result *= base;
    return result;
}

bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001)
        && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================²âÊÔ´úÂë====================
void Test(double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if(abs(result - expectedResult) < 0.00000001
        && g_InvalidInput == expectedFlag)
        printf("Test passed.\n\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char** argv)
{
    // µ×Êý¡¢Ö¸Êý¶¼ÎªÕýÊý
    printf("Test1 begins.\n");
    Test(2, 3, 8, false);

    // µ×ÊýÎª¸ºÊý¡¢Ö¸ÊýÎªÕýÊý
    printf("Test2 begins.\n");
    Test(-2, 3, -8, false);

    // Ö¸ÊýÎª¸ºÊý
    printf("Test3 begins.\n");
    Test(2, -3, 0.125, false);

    // Ö¸ÊýÎª0
    printf("Test4 begins.\n");
    Test(2, 0, 1, false);

    // µ×Êý¡¢Ö¸Êý¶¼Îª0
    printf("Test5 begins.\n");
    Test(0, 0, 1, false);

    // µ×ÊýÎª0¡¢Ö¸ÊýÎªÕýÊý
    printf("Test6 begins.\n");
    Test(0, 4, 0, false);

    // µ×ÊýÎª0¡¢Ö¸ÊýÎª¸ºÊý
    printf("Test7 begins.\n");
    Test(0, -4, 0, true);

    return 0;
}

