// MinNumberInRotatedArray.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>


int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
    {
        std::cout << "Input array error, please check it!" << std::endl;
        return -1;
    }

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while(numbers[index1] >= numbers[index2])
    {
        // Èç¹ûindex1ºÍindex2Ö¸ÏòÏàÁÚµÄÁ½¸öÊý£¬
        // Ôòindex1Ö¸ÏòµÚÒ»¸öµÝÔö×ÓÊý×éµÄ×îºóÒ»¸öÊý×Ö£¬
        // index2Ö¸ÏòµÚ¶þ¸ö×ÓÊý×éµÄµÚÒ»¸öÊý×Ö£¬Ò²¾ÍÊÇÊý×éÖÐµÄ×îÐ¡Êý×Ö
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }

        // Èç¹ûÏÂ±êÎªindex1¡¢index2ºÍindexMidÖ¸ÏòµÄÈý¸öÊý×ÖÏàµÈ£¬
        // ÔòÖ»ÄÜË³Ðò²éÕÒ
        indexMid = (index1 + index2) / 2;
        if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return MinInOrder(numbers, index1, index2);

        // ËõÐ¡²éÕÒ·¶Î§
        if(numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }

    std::cout << "The min num: " << numbers[indexMid] << std::endl;
    return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
    int result = numbers[index1];
    for(int i = index1 + 1; i <= index2; ++i)
    {
        if(result > numbers[i])
            result = numbers[i];
    }

    std::cout << "The min num: " << result << std::endl;
    return result;
}

// ====================²âÊÔ´úÂë====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == NULL)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char** argv)
{
    // µäÐÍÊäÈë£¬µ¥µ÷ÉýÐòµÄÊý×éµÄÒ»¸öÐý×ª
    int array1[] = {3, 4, 5, 1, 2};
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // ÓÐÖØ¸´Êý×Ö£¬²¢ÇÒÖØ¸´µÄÊý×Ö¸ÕºÃµÄ×îÐ¡µÄÊý×Ö
    int array2[] = {3, 4, 5, 1, 1, 2};
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // ÓÐÖØ¸´Êý×Ö£¬µ«ÖØ¸´µÄÊý×Ö²»ÊÇµÚÒ»¸öÊý×ÖºÍ×îºóÒ»¸öÊý×Ö
    int array3[] = {3, 4, 5, 1, 2, 2};
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // ÓÐÖØ¸´µÄÊý×Ö£¬²¢ÇÒÖØ¸´µÄÊý×Ö¸ÕºÃÊÇµÚÒ»¸öÊý×ÖºÍ×îºóÒ»¸öÊý×Ö
    int array4[] = {1, 0, 1, 1, 1};
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // µ¥µ÷ÉýÐòÊý×é£¬Ðý×ª0¸öÔªËØ£¬Ò²¾ÍÊÇµ¥µ÷ÉýÐòÊý×é±¾Éí
    int array5[] = {1, 2, 3, 4, 5};
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // Êý×éÖÐÖ»ÓÐÒ»¸öÊý×Ö
    int array6[] = {2};
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // ÊäÈëNULL
    Test(NULL, 0, 0);

    return 0;
}

