#include <iostream>
#include <stdio.h>
#include <cstring>  // strlen; strcpy ...

char* StrCat(char* ch1, char* ch2)
{
    int len1 = std::strlen(ch1);
    int len2 = std::strlen(ch2);
    int len = len1 + len2 + 1;
    char* temp = new char[len];
    std::strcpy(temp, ch1);
    std::strcat(temp, ch2);
    return temp;

}

int main(int argc, char** argv)
{
    char* ch1 = "Hello";
    char* ch2 = "World";
    char * str_cat = StrCat(ch1, ch2);
    std::cout << str_cat << std::endl;


    return 0;
}
