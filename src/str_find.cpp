#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>

int strStr(const char *source, const char *target)
{
    // write your code here
    if (source == NULL || target == NULL)
        return -1;
    if (*(source) == '\0' && *(target) == '\0')
        return 0;
    if (*(source) == '\0')
        return -1;
    if (*(target) == '\0')
        return 0;
    int source_len = strlen(source);
    int target_len = strlen(target);
    int i = 0;
    int j = 0;
    while (i < source_len)
    {
        if (source[i] == target[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i+1-j;
            j = 0;
        }
        if (target[j] == '\0')
            return i-j;
    }
    return -1;
}


int main(int argc, char** argv)
{
    char str1[] = "tartarget"; //"abcdabcdefg";
    char str2[] = "target"; //"ba";
    std::cout << "Index: " << strStr(str1, str2) << std::endl;

    return 0;
}
