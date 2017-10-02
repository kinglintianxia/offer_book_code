#include <iostream>

void PrintArray(int a[], int n, int i)
{
    std::cout << i << "th sort:\n";
    for (int j = 0; j < n; j ++)
        std::printf("%d ", a[j]);
    std::cout << "\n";
}
// 冒泡法
void BubbleSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

        }
        PrintArray(a, len, i);
    }

}

// Insert Sort
void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; i ++)
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
        PrintArray(a, n, i);

    }

}

// 选择排序
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
void HeapSort(int a[], int len)
{
    BuildHeap(a, len);
    for (int i = len-1; i > 0; i --)
    {
        int temp = a[i]; a[i] = a[0]; a[0] = temp;
        HeapAdjust(a, 0, i);
    }

}


int main(int argc, char** argv)
{
    int a[5] = {8, 5, 6, 9, 1};
    std::cout << "Bubble sort:\n";
    BubbleSort(a, 5);

//    std::cout << "Select sort:\n";
//    SelectSort(a, 5);

//    // Select binary sort
//    std::cout << "Select binary sort:\n";
//    SelectBinarySort(a, 5);
    // Heap sort
    std::cout << "Heap sort\n";
    HeapSort(a, 5);
//    PrintArray(a, 5, 5);
    return 0;
}
