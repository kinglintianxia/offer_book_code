#include <iostream>
#include <vector>

using namespace std;

int findMinInOrder(std::vector<int> nums)
{
    int min = INT32_MAX;
    for (auto num:nums)
    {
        if (num < min)
            min = num;
    }
    return min;
}

int findMin(vector<int> nums) {
    // write your code here
    int p1 = 0, p2 = nums.size()-1;
    int mid = 0;
    while (nums[p1] >= nums[p2])
    {
        // [5,4]
        if (p2-p1 == 1)
        {
            return nums[p2];
        }
        //
        mid = (p1+p2)/2;
        if (nums[p1] == nums[p2] && nums[p1] == nums[mid])
            return findMinInOrder(nums);
        if (nums[mid] >= nums[p1])
            p1 = mid;
        else if (nums[mid] <= nums[p2])
            p2 = mid;
    }
    return nums[mid];
}

int main (int argc, char** argv)
{
    int a[7] = {4,5,6,7,0,1,2};
    int a1[7] = {1,1,1,1,0,1,1};
    std::vector<int> A(a1, a1+7);
    int res = findMin(A);
    std::cout << res << std::endl;


    return 0;
}
