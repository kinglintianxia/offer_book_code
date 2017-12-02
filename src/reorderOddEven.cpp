#include <iostream>
#include <vector>
#include <string>

void swap(std::vector<int>& nums, int i, int j)
{
    if (i >= j)
        return;
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void partitionArray(std::vector<int> &nums)
{
    // write your code here
    if (nums.empty())
        return;
    int p1 = 0;
    int p2 = nums.size()-1;
    while (p1 < p2)
    {
        // p1 points to even
        while (p1 < p2 && (nums[p1]&0x01) != 0)
            p1 ++;
        // p2 points to odd
        while (p1 < p2 && (nums[p2]&0x01) == 0)
            p2 --;
        swap(nums, p1, p2);
    }
}

int main(int argc, char** argv)
{
    int a[4] = {1, 2, 3, 4};
    std::vector<int> a_vec(a, a+4);
    partitionArray(a_vec);
    for (int i = 0; i < a_vec.size(); i++)
        std::cout << a_vec[i] << " ";

    return 0;
}
