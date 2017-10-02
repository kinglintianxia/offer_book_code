// ReorderArray.cpp : Defines the entry point for the console application.
//



#include <iostream>
#include <stdio.h>

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

// ====================·½·¨Ò»====================
void ReorderOddEven_1(int *pData, unsigned int length)
{
    if (pData == NULL || length <= 0)
    {
        std::cout << "Invalide input, please check it! " << std::endl;
        return;
    }
    int *pEven = pData;
    int *pOdd = pData + length - 1;
    while (pEven < pOdd)
    {
        while (pEven < pOdd && (*pEven & 0x01)!= 0)
            pEven ++;
        while (pEven < pOdd && (*pOdd & 0x01) == 0)
            pOdd --;
        if (pEven < pOdd)
        {
            int temp = *pEven;
            *pEven = *pOdd;
            *pOdd = temp;
        }
    }
}

// ====================·½·¨¶þ====================
void ReorderOddEven_2(int *pData, unsigned int length)
{
    Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if(pData == NULL || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // ÏòºóÒÆ¶¯pBegin
        while(pBegin < pEnd && !func(*pBegin))
            pBegin ++;

        // ÏòÇ°ÒÆ¶¯pEnd
        while(pBegin < pEnd && func(*pEnd))
            pEnd --;

        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n)
{
    return (n & 1) == 0;
}

// ====================²âÊÔ´úÂë====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", NULL, 0);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

