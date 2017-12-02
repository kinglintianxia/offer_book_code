#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

std::string addBinary(std::string &a, std::string &b)
{
    // write your code here
    char table[] = {'0', '1'};
    std::string result;
    int len = std::min(a.size(), b.size());
    int carry = 0;
    int res = 0;
    for (int i = len-1; i >= 0; i--)
    {
        if (len == a.size() && len < b.size())
            res = (a[i]-'0') + (b[b.size()-a.size()+i]-'0') + carry;
        else if (len == b.size() && len < a.size())
            res = (a[a.size()-b.size()+i]-'0') + (b[i]-'0') + carry;
        else
            res = (a[i]-'0') + (b[i]-'0') + carry;
        carry = 0;
        result.insert(result.begin(), table[res%2]);
        carry = res /= 2;
    }
    if (a.size() > b.size())
    {
        for (int j = a.size()-b.size()-1; j >= 0; j--)
        {
            res = (a[j]-'0') + carry;
            carry = 0;
            result.insert(result.begin(), table[res%2]);
            carry = res /= 2;
            if (j == 0 && carry == 1)
                result.insert(result.begin(), '1');
        }
    }
    else
    {
        for (int j = b.size()-a.size()-1; j >= 0; j--)
        {
            res = (b[j]-'0') + carry;
            carry = 0;
            result.insert(result.begin(), table[res%2]);
            carry = res /= 2;
            if (j == 0 && carry == 1)
                result.insert(result.begin(), '1');
        }
    }
    return result;

}

std::string addBinary1(std::string &a, std::string &b)
{
    // write your code here
    char table[] = {'0', '1'};
    std::string result;
    int len1 = a.size()-1;
    int len2 = b.size()-1;

    int carry = 0;
    int res = 0;
    for (; len1 >= 0 && len2 >= 0; len1--, len2--)
    {
        res = (a[len1]-'0') + (b[len2]-'0') + carry;
        carry = 0;
        result.insert(result.begin(), table[res%2]);
        carry = res/2;
        if(len1 == 0 && len2 == 0 && carry == 1)
            result.insert(result.begin(), '1');
    }
    for (; len1 >= 0; len1--)
    {
        res = (a[len1]-'0') + carry;
        carry = 0;
        result.insert(result.begin(), table[res%2]);
        carry = res/2;
        if (len1 == 0 && carry == 1)
            result.insert(result.begin(), '1');
    }

    for (; len2 >= 0; len2--)
    {
        res = (b[len2]-'0') + carry;
        carry = 0;
        result.insert(result.begin(), table[res%2]);
        carry = res/2;
        if (len2 == 0 && carry == 1)
            result.insert(result.begin(), '1');
    }

    return result;


}

int main(int argc, char** argv)
{
    std::string str1 = "111", str2 = "1111";
    std::cout << " binary add: " << addBinary(str1, str2) << std::endl;
    std::cout << " binary add1: " << addBinary1(str1, str2) << std::endl;


    return 0;
}
