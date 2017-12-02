#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(vector<int>& colors, int i, int j)
{
    if (i == j)
        return;
    int tmp = colors[i];
    colors[i] = colors[j];
    colors[j] = tmp;
}
void sortColors2(vector<int> &colors, int k)
{
    //write your code here
    int i = 0, j = 0, n = colors.size();
    for (int color = 1; color <= k; color ++)
    {
        j = i+1;
        while (j < n)
        {
            while (i < n && colors[i] == color)
                i ++;
            //reset the second pointer
            j = j>i ? j:i+1;
            while (j < n && colors[j] != color)
                j ++;
            if (j < n)
                swap(colors, i, j);
        }
    }

}

int main(int argc, char** argv)
{
    int a[5] = {3, 2, 2, 1, 4};
    std::vector<int> nums(a, a+5);
    sortColors2(nums, 4);
    std::cout << "[";
    for (int i = 0; i < nums.size(); i ++)
        std::cout << nums[i] << ",";
    std::cout << "]" << std::endl;
    return 0;
}
