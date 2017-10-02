#include <iostream>
#include <string>

void PrintArray(int a[], int n, int i)
{
    std::cout << "\n" << i << "th insert sort:\n";
    for (int j = 0; j < n; j ++)
        std::printf("%d ", a[j]);

}
// king
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


int main(int argc, char** argv)
{
    const int n = 8;
//    std::scanf("%d", &n);
//    int a[n];
//    for (int i = 0; i < n; i ++)
//        std::scanf("%d", &a[i]);
    int a[8] = {3, 1, 5, 7, 2, 4, 9, 6};
    PrintArray(a, n, 0);
    InsertSort(a, n);
    PrintArray(a, n, n);


    return 0;
}
