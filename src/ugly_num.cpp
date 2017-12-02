#include <iostream>
#include <vector>
#include <map>


int nthSuperUglyNumber(int n, int primes[], int len)
{
    // write your code here
    if (n == 1)
        return 1;
    int ugly_cnt = 0;
    unsigned int num = 1;
    unsigned int temp = num;
    while (ugly_cnt < n)
    {
        num ++;
        temp = num;
        for (int i = 0; i < len; i ++)
        {
            while (num % primes[i] == 0)
                num /= primes[i];
        }
        if (num == 1)
            ugly_cnt ++;
        num = temp;
    }
    return temp;

}


int main(int argc, char** argv)
{
//    int a[10] = {1,1,2,3,3,3,2,2,4,1};
//    std::cout << "Single number: " << singleNumberII(a, 10) << std::endl;
    int a[4] = {2, 7, 13, 19};
    int n = 6;
    std::cout << "Super ugly number: " << nthSuperUglyNumber(6, a, 4) << std::endl;

    return 0;
}
