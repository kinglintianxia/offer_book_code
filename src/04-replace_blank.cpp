// ReplaceBlank.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

void ReplaceBlank(char string[], int length)
{
    if (string == NULL || length < 0)
    {
        std::cout << "Error string! " << std::endl;
        return;
    }

    int origin_str_length = 0;
    int blank_length = 0;
    int replace_length = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        origin_str_length++;
        if (string[i] == ' ')
            blank_length++;
        i++;
    }
    // Calucate total length
    replace_length = origin_str_length + blank_length * 2;
    // Copy
    while (origin_str_length >= 0 && replace_length > origin_str_length)
    {
        if(string[origin_str_length] == ' ')
        {
            string[replace_length --] = '0';
            string[replace_length --] = '2';
            string[replace_length --] = '%';

        }
        else
        {
            string[replace_length --] = string[origin_str_length];
        }
        // Only outside can work
        -- origin_str_length;

    }


    for (int i = 0; i < strlen(string); i++)
    {
        std::cout << "" << string[i] << " ";
    }
}

// Compare and sort array A1 and A2
void sort_array(int* arr1, int* arr2)
{
    if (arr1 == NULL || arr2 == NULL)
    {
        std::cout << "Check the input string!" << std::endl;
        return;
    }
    int arr1_length = 0;
    int arr2_length = 0;
    int i = 0, j = 0;
    while (arr1[i] != '\0')
    {
        arr1_length ++;
        i ++;
    }
    while (arr2[j] != '\0')
    {
        arr2_length ++;
        j ++;
    }
//    std::cout << "arr1_length: " << arr1_length << std::endl;
    // Total length
    int total_length = arr1_length + arr2_length;
    int len = total_length;
//    std::cout << "Total length: " << total_length << std::endl;
    arr1_length -= 1;
    arr2_length -= 1;
    total_length -= 1;
    while (arr2_length >= 0)
    {
        if (arr1[arr1_length] < arr2[arr2_length])
            arr1[total_length --] = arr2[arr2_length --];
        else
            arr1[total_length --] = arr1[arr1_length --];

        // arr1_len < arr2_len
        if (arr1_length <= -1)
        {
            while (arr2_length >= 0)
            {
                arr1[total_length --] = arr2[arr2_length --];
            }

        }

    }
    std::cout << "The sorted string: " << std::endl;
    for (int i = 0; i < len; i++)
    {
        std::cout <<arr1[i] << ",";

    }
    std::cout <<"\n";

}

void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// ¿Õ¸ñÔÚ¾ä×ÓÖÐ¼ä
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// ¿Õ¸ñÔÚ¾ä×Ó¿ªÍ·
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// ¿Õ¸ñÔÚ¾ä×ÓÄ©Î²
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// Á¬ÐøÓÐÁ½¸ö¿Õ¸ñ
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// ´«ÈëNULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// ´«ÈëÄÚÈÝÎª¿ÕµÄ×Ö·û´®
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//´«ÈëÄÚÈÝÎªÒ»¸ö¿Õ¸ñµÄ×Ö·û´®
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// ´«ÈëµÄ×Ö·û´®Ã»ÓÐ¿Õ¸ñ
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// ´«ÈëµÄ×Ö·û´®È«ÊÇ¿Õ¸ñ
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

// Test sort_array
void test_sort()
{
    std::cout << "\nTest sort1 :\n";
    int arr11[10] = {1, 3, 5};
    int arr12[10] = {2, 4, 6};
    sort_array(arr11, arr12);

    std::cout << "\nTest sort2 :\n";
    int arr21[10] = {1, 3, 5, 7};
    int arr22[10] = {2, 4, 6};
    sort_array(arr21, arr22);

    std::cout << "\nTest sort3 :\n";
    int arr31[10] = {1, 3, 5};
    int arr32[10] = {2, 4, 6, 8};
    sort_array(arr31, arr32);

    std::cout << "\nTest sort4 :\n";
    int arr41[10] = {1, 3, 5};
    int arr42[10] = {-2, -1, 3, 5};
    sort_array(arr41, arr42);

    std::cout << "\nTest sort5 :\n";
    int arr51[10] = {-1, 6, 7, 8};
    int arr52[10] = {2, 4, 6};
    sort_array(arr51, arr52);

    std::cout << "\nTest sort5 :\n";
    int arr61[10] = {};
    int arr62[10] = {};
    sort_array(arr61, arr62);
    sort_array(NULL, NULL);

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
    test_sort();
    return 0;
}

