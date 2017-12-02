#include <iostream>
#include <vector>
#include <string>

int partitionArray(std::vector<int> &nums, int k)
{
    // write your code here
    if (nums.size() == 0)
        return 0;
    int begin = 0;
    int end = nums.size()-1;
    while (begin <= end)
    {
        if (nums[begin] >= k && nums[end] < k)
        {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin ++;
            end --;
        }
        else if (nums[begin] >= k)
            end --;
        else if (nums[end] < k)
            begin ++;
        else
        {
            begin ++;
            end --;
        }

    }
    return begin;
}

int main(int argc, char** argv)
{
    int a[18] = {9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9};
    std::vector<int> a_vec(a, a+18);
    std::cout << "partitionArray: " << partitionArray(a_vec, 9) << std::endl;

    return 0;
}
