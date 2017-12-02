// NumberOfK.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stdio.h>


int GetFirstK(int* data, int length, int k, int start, int end);
int GetLastK(int* data, int length, int k, int start, int end);

int GetNumberOfK(int* data, int length, int k)
{
    int number = 0;

    if(data != NULL && length > 0)
    {
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);

        if(first > -1 && last > -1)
            number = last - first + 1;
    }

    return number;
}

//////*****king code*******//////////
int GetFirstK(int *data, int length, int k, int start, int end)
{
    if (data[0] > k || data[end] < k)
        return -1;
    int mid = (end - start)/2 + start;
    while (start < end)
    {
        if (data[mid] < k)
            start = mid + 1;
        if (data[mid] >= k)
            end = mid;
        mid = (end - start)/2 + start;
    }
    return mid;

}

int GetLastK(int* data, int length, int k, int start, int end)
{
    if (data[0] > k || data[end] < k)
        return -1;
    if (data[end] == k)
        return end;
    int mid = (end - start) / 2 + start;
    while (start < end)
    {
        if (data[mid] <= k)
            start = mid;
        if (data[mid] > k)
            end = mid - 1;
        mid = (end - start) / 2 + start;
    }
    return mid;
}

////
//int GetFirstK(int* data, int length, int k, int start, int end)
//{
//    if(start > end)
//        return -1;

//    int middleIndex = (start + end) / 2;
//    int middleData = data[middleIndex];

//    if(middleData == k)
//    {
//        if((middleIndex > 0 && data[middleIndex - 1] != k)
//            || middleIndex == 0)
//            return middleIndex;
//        else
//            end  = middleIndex - 1;
//    }
//    else if(middleData > k)
//        end = middleIndex - 1;
//    else
//        start = middleIndex + 1;

//    return GetFirstK(data, length, k, start, end);
//}

//// ÕÒµœÊý×éÖÐ×îºóÒ»žökµÄÏÂ±ê¡£Èç¹ûÊý×éÖÐ²»ŽæÔÚk£¬·µ»Ø-1
//int GetLastK(int* data, int length, int k, int start, int end)
//{
//    if(start > end)
//        return -1;

//    int middleIndex = (start + end) / 2;
//    int middleData = data[middleIndex];

//    if(middleData == k)
//    {
//        if((middleIndex < length - 1 && data[middleIndex + 1] != k)
//            || middleIndex == length - 1)
//            return middleIndex;
//        else
//            start  = middleIndex + 1;
//    }
//    else if(middleData < k)
//        start = middleIndex + 1;
//    else
//        end = middleIndex - 1;

//    return GetLastK(data, length, k, start, end);
//}



// ====================²âÊÔŽúÂë====================
void Test(char* testName, int data[], int length, int k, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ²éÕÒµÄÊý×Ö³öÏÖÔÚÊý×éµÄÖÐŒä
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// ²éÕÒµÄÊý×é³öÏÖÔÚÊý×éµÄ¿ªÍ·
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// ²éÕÒµÄÊý×é³öÏÖÔÚÊý×éµÄœáÎ²
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// ²éÕÒµÄÊý×Ö²»ŽæÔÚ
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// ²éÕÒµÄÊý×Ö±ÈµÚÒ»žöÊý×Ö»¹Ð¡£¬²»ŽæÔÚ
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// ²éÕÒµÄÊý×Ö±È×îºóÒ»žöÊý×Ö»¹Žó£¬²»ŽæÔÚ
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// Êý×éÖÐµÄÊý×ÖŽÓÍ·µœÎ²¶ŒÊÇ²éÕÒµÄÊý×Ö
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// Êý×éÖÐµÄÊý×ÖŽÓÍ·µœÎ²Ö»ÓÐÒ»žöÖØžŽµÄÊý×Ö£¬²»ÊÇ²éÕÒµÄÊý×Ö
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// Êý×éÖÐÖ»ÓÐÒ»žöÊý×Ö£¬ÊÇ²éÕÒµÄÊý×Ö
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// Êý×éÖÐÖ»ÓÐÒ»žöÊý×Ö£¬²»ÊÇ²éÕÒµÄÊý×Ö
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// Â³°ôÐÔ²âÊÔ£¬Êý×é¿ÕÖžÕë
void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}
