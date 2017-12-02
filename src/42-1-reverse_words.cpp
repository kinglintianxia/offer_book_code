// ReverseWordsInSentence.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

void Reverse(char* begin, char* end)
{
    if (begin == NULL || end == NULL)
        return;
    while (begin < end)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin ++;
        end --;
    }

}


char* ReverseSentence(char *pData)
{
    if(pData == NULL)
        return NULL;

    char *pBegin = pData;

    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd--;

    // reverse total sentence
    Reverse(pBegin, pEnd);

    // reverse every word
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
        {
            pEnd ++;
        }
    }

    return pData;
}
// Left rotate string
char* LeftRoatateString(char* pStr, int n)
{
    if (pStr != NULL)
    {
        int len = strlen(pStr);
        if (len > 0 && n > 0 && n < len)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + len - 1;
            // Reverse first part
            Reverse(pFirstStart, pFirstEnd);
            // Reverse second part
            Reverse(pSecondStart, pSecondEnd);
            // Reverse total string
            Reverse(pFirstStart, pSecondEnd);

        }

    }
    return pStr;

}

// Reverse string
void ReveseStr(std::string& str, int begin, int end)
{
    while (begin < end)
    {
        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;
        begin ++;
        end --;
    }
}

// C++ string
std::string ReverseWords(std::string &s)
{
    // Remove space
    std::string str;
    std::string word;
    int begin = s.size() - 1;
    int end = s.size() - 1;
    int i = begin;
    while (i >= 0)
    {
        while (s[i] == ' ' && i >= 0)
        {
            begin --;
            end --;
            i --;
        }
        while (s[i] != ' ' && i >=0)
        {
            begin --;
            i --;
        }
        word.clear();
        word = s.substr(begin + 1, end - begin);
        if (begin == -1)
            str = str + word;
        else
            str = str + word + " ";
        end = begin;

    }
    return str;

}


// ====================²âÊÔ´úÂë====================
void Test(char* testName, char* input, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ¹¦ÄÜ²âÊÔ£¬¾ä×ÓÖÐÓÐ¶à¸öµ¥´Ê
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";
    std::string string= "I am a student";
//    char a[] = "abcdefg";
//    Test("Test1", input, expected);
//    LeftRoatateString(a, 2);
//    for (int i = 0; i < strlen(a); i++)
//        std::cout << a[i];
//    std::cout << std::endl;
    // string
    std::cout << "Reverse in string: \n";
    std::cout << "After reverse: " << ReverseWords(string) << std::endl;

}

// ¹¦ÄÜ²âÊÔ£¬¾ä×ÓÖÐÖ»ÓÐÒ»¸öµ¥´Ê
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// Â³°ôÐÔ²âÊÔ
void Test3()
{
    Test("Test3", NULL, NULL);
}

// ±ß½çÖµ²âÊÔ£¬²âÊÔ¿Õ×Ö·û´®
void Test4()
{
    Test("Test4", "", "");
}

// ±ß½çÖµ²âÊÔ£¬×Ö·û´®ÖÐÖ»ÓÐ¿Õ¸ñ
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

