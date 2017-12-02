#include <iostream>
#include <vector>

int singleNumberII(int a[], int len)
{
    // write your code here
    int bit[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < len; j ++)
        {
            bit[i] += (a[j] >> i) & 0x01;
        }
        bit[i] %= 3;
        result = result | (bit[i] << i);
    }
    return result;
}

std::vector<int> singleNumberIII(int A[], int len)
{
    // write your code here
    long long result_bit = 0;
    int num1 = 0, num2 = 0;
    std::vector<int> num;
    if (len == 2)
    {
        num.push_back(A[0]);
        num.push_back(A[1]);
        return num;
    }

    for (int i = 0; i < len; i++)
        result_bit ^= A[i];
    unsigned int first_bit = 0;
    while ((result_bit & 0x01) == 0 && first_bit < 32)
    {
        result_bit = result_bit >> 1;
        first_bit ++;
    }

    for (int i = 0; i < len; i ++)
    {
        if ((A[i] >> first_bit) & 0x01)
            num1 ^= A[i];
        else
            num2 ^= A[i];
    }

    num.push_back(num1);
    num.push_back(num2);
    return num;
}

int main(int argc, char** argv)
{
//    int a[10] = {1,1,2,3,3,3,2,2,4,1};
//    std::cout << "Single number: " << singleNumberII(a, 10) << std::endl;
    int a[16] = {1,5,-1,1,2,2,3,4,4,5,3,2147483647,8,9,9,8};
    std::vector<int> result(2);
    result = singleNumberIII(a, 16);
    std::cout << "Single number: " << result[0] << ", " << result[1]<< std::endl;

    return 0;
}
