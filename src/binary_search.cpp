/*****
二分查找算法是在有序数组中用到的较为频繁的一种算法，在未接触二分查找算法时，最通用的一种做法是，对数组进行遍历，
跟每个元素进行比较，其时间为O(n).但二分查找算法则更优，因为其查找时间为O(lgn)，
譬如数组{1， 2， 3， 4， 5， 6， 7， 8， 9}，查找元素6，用二分查找的算法执行的话，其顺序为：
1.第一步查找中间元素，即5，由于5<6，则6必然在5之后的数组元素中，那么就在{6， 7， 8， 9}中查找，
2.寻找{6， 7， 8， 9}的中位数，为7，7>6，则6应该在7左边的数组元素中，那么只剩下6，即找到了。
******/

#include <iostream>

int BinarySearch(int a[], int len, int target)
{
    int begin = 0;
    int end = len - 1;
    while (begin <= end)
    {
        int mid = (end - begin)/2 + begin;  // 直接使用(high + low) / 2 可能导致溢出
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;

    }
    return -1;

}

int main(int argc, char** argv)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = BinarySearch(a, 10, 6);
    if (index != -1)
        std::cout << "Found 6 in: " << index << std::endl;
    else
        std::cout << "Not found 6!" << std::endl;

    return 0;
}
