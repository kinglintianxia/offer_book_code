#include <iostream>
#include <vector>
#include <string>

int searchInsert(std::vector<int> &A, int target)
{
    // write your code here
    int len = A.size();
    if (len <= 0)
        return 0;
    int begin = 0;
    int end = len-1;
    while (begin <= end)
    {
        int mid = (end-begin)/2 + begin;
        if (A[mid] == target)
            return mid;
        if (A[mid] < target)
            begin = mid+1;

        if (A[mid] > target)
            end = mid-1;
    }
    return begin;

}

int main(int argc, char** argv)
{
    int a[6] = {1,2,3,4,5,9};
    std::vector<int> a_vec(a, a+6);
    std::cout << "searchInsert: " << searchInsert(a_vec, 0) << std::endl;

    return 0;
}
