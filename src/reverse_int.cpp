#include <iostream>
#include <string>


int ReverseInteger(int n)
{
    // write your code here
    int temp = n;
    long long a[11] = {1, 10, 100, 1000, 10000,
                       100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    bool flag = false;
    if (temp == 0)
        return 0;
    if (temp / a[1] == 0)
        return temp;
    if (temp < 0)
    {
        temp = -temp;
        flag = true;
    }
    int num_bit = 0;
    for (int i = 0; i < 11; i ++)
    {
        if (temp / a[i] == 0)
        {
            num_bit = i;
            break;
        }
    }
    long long result = 0, num;
    for (int i = 0; i < num_bit; i++)
    {
        num = temp % 10;
        for (int j = 0; j < num_bit - i - 1; j ++)
            num *= 10;
        result += num;
        temp /= 10;
        if (double(result) / double(a[9]) >= 2.147484)
            return 0;
    }
    if (flag)
        return -1 * result;
    else
        return result;


}
//
int ReverseInteger1(int n)
{
    int result = 0;
    while (n != 0)
    {
        int val = n % 10;
        int temp = result;
        result = temp * 10 + val;
        n /= 10;
        if (result / 10 != temp)
            return 0;
    }
    return result;

}

int main(int argc, char** argv)
{
    int test = -1534236469;
    std::cout << "Reverse integer:\"" << test << "\" to: " <<  ReverseInteger1(test) << std::endl;


    return 0;
}
