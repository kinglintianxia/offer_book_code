#include <iostream>
#include <string>



void StringPermutation(char* arr, char* pNext)
{

    if (*pNext == '\0')
        std::cout << arr << std::endl;
    else
    {
        for (char* ch = pNext; *ch != '\0'; ch ++)
        {
            char temp;
            temp = *pNext;
            *pNext = *ch;
            *ch = temp;
            StringPermutation(arr, pNext + 1);
            // ??
            temp = *pNext;
            *pNext = *ch;
            *ch = temp;

        }
    }

}

int main(int argc, char** argv)
{

    std::cout << "Please input a string:" << std::endl;
    char array[10];
    std::cin >> array;
    std::cout << "The permutation: " << std::endl;
    StringPermutation(array, array);

    return 0;
}
