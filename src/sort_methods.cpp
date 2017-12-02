#include <iostream>
#include <vector>

// 不稳定: 快选堆希
// 稳  定: 插冒归基

void PrintArray(int a[], int n, int i)
{
    std::cout << i << "th sort:\n";
    for (int j = 0; j < n; j ++)
        std::printf("%d ", a[j]);
    std::cout << "\n";
}

void PrintArray(int a[], int n)
{
    for (int j = 0; j < n; j ++)
        std::printf("%d ", a[j]);
    std::cout << "\n";
}

void Swap(int* a, int i, int j)
{
    int temp = *(a+i);
    *(a+i) = *(a+j);
    *(a+j) = temp;

}

void Swap(std::vector<int>& a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

}
/////////////////////////////////////////////
/// \brief BubbleSort
/// \param a[]
/// \param len
/// Time: best O(n); worst: O(n2)
/// 稳定 Stable
void BubbleSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] > a[j])
                Swap(a, i, j);

        }
        PrintArray(a, len, i);
    }

}

// 冒泡法
void BubbleSort1(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if (a[j] > a[j+1])
                Swap(a, j, j+1);

        }
        PrintArray(a, len, i);
    }
}

/////////////////***Insert Sort***//////////////////////////
/// \brief InsertSort
/// \param a[]
/// \param len
/// Time: best O(n); worst: O(n2)
/// 稳定 Stable
void InsertSort(int a[], int len)
{
    for (int i = 1; i < len; i ++)
    {
        if (a[i] < a[i-1])
        {
            int x = a[i];
            int j = i - 1;
            while (x < a[j] && j >= 0)
            {
                a[j+1] = a[j];
                j --;

            }
            a[j+1] = x;

        }
        PrintArray(a, len, i);

    }

}

//希尔排序
//不稳定
void ShellSort(int *a,int len)
{
    int gap = len ;
    while (gap>1)
    {
        gap = gap / 3 + 1;
        for (int i = gap; i < len; ++i)
        {
            int temp = a[i]; //暂存关键数据
            int j = i;
            while (j - gap >= 0 && temp < a[j - gap])
            {
                a[j] = a[j - gap];   //后移
                j = j - gap;     //前置索引
            }
            a[j] = temp;
            PrintArray(a, len, i);
        }
    }
}

/////////////////////////////////////////////////////
// 选择排序
/// Time: best O(n2); worst: O(n2)
/// 不稳定 Unstable
void SelectSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = a[i];
        int min_pos = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                min_pos = j;
            }

        }
        // Swap
        int temp = a[i];
        a[i] = min;
        a[min_pos] = temp;
        PrintArray(a, len, i);
    }

}

// 二元选择排序
// 改进后对n个数据进行排序，最多只需进行[n/2]趟循环
void SelectBinarySort(int r[],int n)
{
    int i ,j , min ,max, tmp;
    for (i = 0 ;i < n/2;i++)
    {
        // 做不超过n/2趟选择排序
        min = i; max = i ; // 分别记录最大和最小关键字记录位置
        for (j= i+1; j< n-i; j++)
        {
            if (r[j] > r[max])
            {
                max = j ; continue ;
            }
            if (r[j]< r[min])
            {
                min = j ;
            }
        }
//        // 该交换操作还可分情况讨论以提高效率
//        tmp = r[i-1]; r[i-1] = r[min]; r[min] = tmp;
//        tmp = r[n-i]; r[n-i] = r[max]; r[max] = tmp;
        //
        tmp = r[i]; r[i] = r[min]; r[min] = tmp;
        tmp = r[n-i-1]; r[n-i-1] = r[max]; r[max] = tmp;
        //
        PrintArray(r, n, i);
    }
}

////////////////////////////////////////////////////////////////
// 选择排序—堆排序（Heap Sort）
void HeapAdjust(int a[], int s, int len)
{
    int temp = a[s];
    int child = 2*s + 1;    // left child
    while (child < len)
    {
        if (child+1 < len && a[child] < a[child+1]) // left < right
        {
            ++child;    // point right

        }
        if (a[s] < a[child])    // root < left or root < right
        {
            a[s] = a[child];    // root = max child
            s = child;          // record order
            child = 2*s + 1;    // next iteration

        }
        else    // 如果当前待调整结点大于它的左右孩子，则不需要调整，直接退出
            break;
        a[s] = temp;    //当前待调整的结点放到比其大的孩子结点位置上

    }
//    PrintArray(a, len, 0);

}

//
void BuildHeap(int a[], int len)
{
    // 最后一个有孩子的节点的位置 i=  (length -1) / 2
    for (int i = (len-1)/2; i >= 0; i--)
    {
        HeapAdjust(a, i, len);
        PrintArray(a, len, i);
    }

}
// Heap sort
/////////////////
/// \brief HeapSort
/// \param a
/// \param len
/// Time: best O(nlogn); worst: O(nlogn)
/// 不稳定 Unstable
void HeapSort(int a[], int len)
{
    BuildHeap(a, len);
    for (int i = len-1; i > 0; i --)
    {
        int temp = a[i]; a[i] = a[0]; a[0] = temp;
        HeapAdjust(a, 0, i);
    }

}
////////////////////////////////////////////////////////
/// \brief QuickPartion
/// \param a[]
/// \param low
/// \param high
/// \return index i
///
int QuickPartion(std::vector<int>& nums, int start, int end)
{
    int rand_num = std::rand() % (end-start+1) + start;
    Swap(nums, rand_num, end);
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (nums[j] < nums[end])
        {
            Swap(nums, ++i, j);
        }
    }
    Swap(nums, ++i, end);
    return i;
}
///////////////////////////
/// \brief QuickSort
/// \param a[]
/// \param start
/// \param end = len(a) -1
/// Time: best O(nlogn); worst: O(n2)
/// 不稳定 Unstable
void QuickSort(std::vector<int>& nums, int start, int end)
{
    if (start < end)    // !!!
    {
        int mid = QuickPartion(nums, start, end);
        if (start < mid)
            QuickSort(nums, start, mid - 1);
        if (end > mid)
            QuickSort(nums, mid + 1, end);
    }
//    PrintArray(nums, 10, start);
}

////////////////////////////////////////////////////
// Merge sort
/// Time: best O(nlogn); worst: O(nlogn)
/// 稳定 Stable
void Merge(int a[], int low, int mid, int high)
{
    int left_len = mid - low + 1;
    int right_len = high - mid;
    int *l = new int[left_len + 1];
    int *r = new int[right_len + 1];
    l[left_len] = INT8_MAX;
    r[right_len] = INT8_MAX;
    //
    for (int i = 0; i < left_len; i++)
        l[i] = a[low + i];
    for (int j = 0; j < right_len; j++)
        r[j] = a[mid + j + 1];
    // sort
    for (int k = low, i = 0, j = 0; k <= high; k ++)
    {
        if (l[i] <= r[j])
            a[k] = l[i ++];
        else
            a[k] = r[j ++];

    }
    delete[] l;
    delete[] r;

}
/////////////////////
/// \brief MergeSort
/// \param a[]
/// \param low
/// \param mid
/// \param high
///
void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);

    }
    PrintArray(a, 10, 9);
}

//////////////////////////////////////////////////
// Count sort
void CountSort(int a[], int len)
{
    //申请空间,用于计数,被排序的数一定要是[0,len-1]之间的数（可包括）
    int* count = new int[len];
    // Init to 0
    for (int i = 0; i < len; i++)
    {
        count[i] = 0;
    }
    // Count each number
    for (int i = 0; i < len; i++)
        count[a[i]] ++;
    //
    for (int i = 1; i < len; i++)
    {
        count[i] += count[i -1];

    }
    //
    int* sort = new int[len];
    for (int i = 0; i < len; i++)
    {
        //把数据放在指定位置。因为pCout[pData[i]]的值就是不比他大数据的个数。
        //为什么要先减一，因为pCout[pData[i]]保存的是不比他大数据的个数中包括了
        //他自己，我的下标是从零开始的!所以要先减一。
        --count[a[i]];    //因为有相同数据的可能，所以要把该位置数据个数减一。
        sort[count[a[i]]] = a[i];

    }

    // Copy to origin array
    for (int i = 0; i < len; i ++)
        a[i] = sort[i];
    // Delete
    delete[] count;
    delete[] sort;

}

////////////////****基数排序*****///////////////////////////
/// \brief GetDigit
/// \param x
/// \param d
/// \return x=15, d = 2, -> 1; d=1 ->5
/// Time: best O(d(n+rd)); worst: O(d(n+r)
/// 稳定 Stable
int GetDigit(int x, int d)
{
    int a[] = {1, 1, 10, 100};
    return (x/a[d])%10;     //  确定桶号

}
// https://www.cnblogs.com/Braveliu/archive/2013/01/21/2870201.html
// 最大桶
void MSDRadixSort(int a[], int begin, int end, int d)
{
    const int radix = 10;
    int count[radix];
    // Empty
    for (int i = 0; i < radix; i ++)
        count[i] = 0;
    //
    int* bucket = new int[end-begin+1];
    //统计各桶需要装的元素的个数
    for (int i = begin; i<=end; i++)
        count[GetDigit(a[i], d)] ++;
    //求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
    for (int i = 1; i < radix; i++)
        count[i] += count[i-1];
    //这里要从右向左扫描，保证排序稳定性
    int j;
    for (int i = end; i >= begin; i--)
    {
        j = GetDigit(a[i], d);
        bucket[count[j]-1] = a[i];
        -- count[j];
    }
    //注意：此时count[i]为第i个桶左边界
    //从各个桶中收集数据
    for (int i = begin, j = 0; i <= end; ++i, ++j)
    {
        a[i] = bucket[j];

    }
    //对各桶中数据进行再排序
    for (int i = 0; i < radix; i++)
    {
        int p1 = begin + count[i];          //第i个桶的左边界
        int p2 = begin + count[i+1] - 1;    //第i个桶的右边界
        if (p1 < p2 && d > 1)
        {
            MSDRadixSort(a, p1, p2, d-1);

        }
        PrintArray(a, 10, i);
    }

    delete[] bucket;
}

// 最小桶
void LSDRadixSort(std::vector<int>& a, int begin, int end, int d)
{
    const int radix = 10;
    int count[radix];
    std::vector<int> bucket(end-begin+1, 0);

    for (int k = 1; k <= d; k++)
    {
        // Empty
        for (int i = 0; i < radix; i ++)
            count[i] = 0;
        //
        //统计各桶需要装的元素的个数
        for (int i = begin; i<=end; i++)
            count[GetDigit(a[i], k)] ++;
        //求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
        for (int i = 1; i < radix; i++)
            count[i] += count[i-1];
        //这里要从右向左扫描，保证排序稳定性; 分配时由末位向首位进行
        int j;
        for (int i = end; i >= begin; i--)
        {
            --count[GetDigit(a[i], k)];
            bucket[count[GetDigit(a[i], k)]] = a[i];

        }
        //注意：此时count[i]为第i个桶左边界
        //从各个桶中收集数据
        for (int i = begin, j = 0; i <= end; ++i, ++j)
        {
            a[i] = bucket[j];

        }

    }

}

//
// 不稳定: 快选堆希
// 稳  定: 插冒归基
int main(int argc, char** argv)
{
    int a[10] = {5,1,5,7,2,4,9,6,3,8};
    int a1[10] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89};
    std::vector<int> a_vec(a1, a1+10);
    std::vector<int> nums(a, a+10);
//////////////////////////////////////////
//    std::cout << "Bubble sort:\n";
//    BubbleSort1(a, 10);

//    std::cout << "Select sort:\n";
//    SelectSort(a, 5);

    // Insert sort
//    std::cout << "Shell sort:\n";
//    ShellSort(a, 10);

//    // Select binary sort
//    std::cout << "Select binary sort:\n";
//    SelectBinarySort(a, 5);

    // Heap sort
//    std::cout << "Heap sort\n";
//    HeapSort(a, 5);
/////////////////////////////////////////
    //
    std::cout << "Quick sort:\n";
    QuickSort(nums, 0, 9);
//    PrintArray(a, 10, 5);

    // Merge sort
//    std::cout << "Merge sort:\n";
//    MergeSort(a, 0, 9);

//    std::cout << "Count sort:\n";
//    CountSort(a, 10);
//    PrintArray(a, 10, 9);

//    std::cout << "Radix sort:\n";
////    MSDRadixSort(a1, 0, 9, 2);
    LSDRadixSort(a_vec, 0, 9, 2);
//    std::printf("After sort:\n");
//    PrintArray(a1, 10);

    return 0;
}
