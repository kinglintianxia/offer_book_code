#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

int replaceBlank(char str[], int length)
{
    // write your code here
    int space_cnt = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
            space_cnt ++;
    }
    int new_len = length + space_cnt*2;
    int res = new_len;
    for (; length >= 0 && new_len >= length;)
    {
        if (str[length] == ' ')
        {
            str[new_len--] = '0';
            str[new_len--] = '2';
            str[new_len--] = '%';
            length--;
        }
        else
            str[new_len--] = str[length--];

    }
    return res;

}

int main(int argc, char** argv)
{
    char str[17] = "Mr John Smith";
    std::cout << "replaceBlank: " << replaceBlank(str, 13) << std::endl;
    std::cout << "str: " << str << std::endl;


    return 0;
}
