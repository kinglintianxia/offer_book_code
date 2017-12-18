#include <iostream>

int leftRotate(int n, int d)
{
    // write code here
    int left = 0;
    for (int i = 0; i < d; ++i)
    {
        left = left * 2 + n & (1 << (31 - i));

    }
    std::cout << "left: " << left << std::endl;
    return n << d + left;

}

int main (int argc, char** argv)
{
    std::cout << "leftRotate: " << leftRotate(123, 4) << std::endl;

    return 0;
}
