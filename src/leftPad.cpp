#include <iostream>
#include <vector>
#include <string>

std::string leftPad(std::string &originalStr, int size, char padChar=' ')
{
    // write your code here
    if (size <= originalStr.size())
        return originalStr;
    std::string res_str;
    int ori_size = originalStr.size();
    for (int i = 0; i < size-ori_size; i ++)
    {
        res_str += padChar;
    }
    res_str += originalStr;
    return res_str;
}

int main(int argc, char** argv)
{
    std::string str = "foo";
    char ch = '0';
    std::cout << leftPad(str, 5) << std::endl;

    return 0;
}
