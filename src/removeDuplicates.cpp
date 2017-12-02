#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

int removeDuplicates(std::vector<int>& nums)
{
    // write your code here
    int len = nums.size();
    if (len == 0)
        return 0;
    int size = 0;
    for (int i = 1; i < len; i ++)
    {
        if (nums[i] != nums[size])
        {
            // here '++size' is diff with 'size++'
            nums[++size] = nums[i];
        }

    }
    nums.resize(size+1);
    return size + 1;

}

int removeDuplicatesII(std::vector<int> &nums)
{
    // write your code here
    int len = nums.size();
    if (len == 0)
        return 0;
    int cnt = 1;
    int size = 0;
    for (int i = 1; i < len; i ++)
    {
        if (nums[i] == nums[size] && cnt < 2)
        {
            cnt ++;
            nums[++size] = nums[i];
        }
        else if (nums[size] != nums[i])
        {
            cnt = 1;
            nums[++size] = nums[i];
        }

    }
    nums.resize(size+1);
    return size + 1;


}

int main(int argc, char** argv)
{
    int a[3] = {1, 2, 2};
    std::vector<int> a_vect;
    for (int i = 0; i < 3; i++)
        a_vect.push_back(a[i]);
    std::cout << "removeDuplicates: " << removeDuplicates(a_vect) << std::endl;
    for (int i = 0; i < 3; i ++)
        std::cout << a[i] << " ";

    //
    int b[6] = {1, 1, 1, 2, 2, 3};
    std::vector<int> b_vect;
    for (int i = 0; i < 6; i++)
        b_vect.push_back(b[i]);
    std::cout << "removeDuplicatesII: " << removeDuplicatesII(b_vect) << std::endl;
    for (int i = 0; i < 3; i ++)
        std::cout << b[i] << " ";

    return 0;
}
