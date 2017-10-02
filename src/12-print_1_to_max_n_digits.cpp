// Print1ToMaxOfNDigits.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================·½·¨Ò»====================
void Print1ToMaxOfNDigits_1(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number))
    {
        PrintNumber(number);
    }

    delete[] number;
}

// Use array holds numbers
//
bool Increment(char* number)
{
// Print out
//    int len = strlen(number);
//    for (int i = 0; i < len; i++)
//        std::cout << number[i];
//    return true;

    bool done_flag = false;
    int carry_flag = 0;
    int len = strlen(number);
    for (int i = len - 1; i >= 0; i--)
    {
        int sum = 0;
        sum = number[i] - '0' + carry_flag;
        if (i == len - 1)
            sum++;
        if (sum >= 10)
        {
            if (i == 0)
                done_flag = true;
            else
            {
                carry_flag = 1;
                sum -= 10;
                number[i] = sum + '0';
            }

        }
        else
        {
            number[i] = sum + '0';
            break;
        }

    }

    return done_flag;

}

// ====================·½·¨¶þ====================
void Print1ToMaxOfNDigits_2(int n)
{
    if(n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    int index = -1;
//    for(int i = 0; i < 10; ++i)
//    {
////        number[0] = i + '0';
//        Print1ToMaxOfNDigitsRecursively(number, n, index + 1);
//    }
    Print1ToMaxOfNDigitsRecursively(number, n, index + 1);

    delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for(int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

// ====================¹«¹²º¯Êý====================
// ×Ö·û´®number±íÊ¾Ò»¸öÊý×Ö£¬Êý×ÖÓÐÈô¸É¸ö0¿ªÍ·
// ´òÓ¡³öÕâ¸öÊý×Ö£¬²¢ºöÂÔ¿ªÍ·µÄ0
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i = 0; i < nLength; ++ i)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if(!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}

// ====================²âÊÔ´úÂë====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    std::cout << "First method:\n";
    Print1ToMaxOfNDigits_1(n);
//    std::cout << "\nSecond method:\n";
//    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n\n", n);
}

int main(int argc, char** argv)
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}

