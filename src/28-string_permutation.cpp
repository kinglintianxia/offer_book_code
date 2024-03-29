// StringPermutation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;

    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

// ====================²âÊÔ´úÂë====================
void Test(char* pStr)
{
    if(pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char** argv)
{
//    Test(NULL);

//    char string1[] = "";
//    Test(string1);

//    char string2[] = "a";
//    Test(string2);

//    char string3[] = "ab";
//    Test(string3);

    char string4[] = "abc";
    Test(string4);

    //
    char string5[10];
    std::cin >> string5;
    Test(string5);

    return 0;
}

