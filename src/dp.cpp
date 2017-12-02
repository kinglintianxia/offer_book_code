#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>

//////////////////////////////////////////////////
// lint code back pack
int backPack(int m, int A[], int len)
{
    // write your code here
    bool f[m+1];
    for (int i = 0; i <= m; i++)
        f[i] = false;
    f[0] = true;

    for (int j = 0; j < len; j ++)
    {
        for (int i = m; i >= A[j]; i --)
            f[i] = f[i] || f[i - A[j]];
    }

    for (int i = m; i >= 0; i --)
    {
        if (f[i])
            return i;
    }
    return 0;
}

//
int backPackII(int m, int A[], int V[], int len)
{
    // write your code here
    int dp[m+1];
    std::fill(dp, dp+m+1, 0);
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = m; j >=A[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j-A[i]] + V[i]);
            result = std::max(result, dp[j]);
        }

    }
    return result;

}

/////////////////////////////////////////////////////////
//最长递增子序列（Longest Increasing Subsequence）。
// 给定长度为N的数组A，计算A的最长单调递增的子序列（不一定连续）。
// 如给定数组A{5，6，7，1，2，8}，则A的LIS为{5，6，7，8}，长度为4.
int LIS(int a[], int len)
{
    int* b = new int[len];
    b[0] = 1;
    int max = -1;
    int result = 1;
    for (int i = 1; i < len; i ++)
    {
        for (int j = 0; j < i; j ++)
        {
            if (a[i] > a[j] && b[j] > max)
            {
                max = b[j];
            }
        }
        b[i] = max + 1;
        result = std::max(result, b[i]);
    }
    delete[] b;
    return result;
}

// 如果不仅是求LIS的长度，而要求LIS本身呢？我们可以通过记录前驱的方式，从该位置找到其前驱，进而找到前驱的前驱
int LIS1(int a[], int len)
{
    int* b = new int[len];
    int* c = new int[len];
    b[0] = 1;
    c[0] = -1;
    int max = -1;
    int result = 1;
    int index = 0;
    for (int i = 1; i < len; i ++)
    {
        bool flag = false;
        for (int j = 0; j < i; j ++)
        {
            if (a[i] > a[j] && b[j] > max)
            {
                flag = true;
                max = b[j];
                c[i] = j;
            }

        }
        if (flag == false)
            c[i] = -1;
        b[i] = max + 1;
        if (b[i] > result)
        {
            result = b[i];
            index = i;
        }

    }
    //
    std::vector<int> res_vector;
    for (; index >= 0;)
    {
        res_vector.push_back(a[index]);
        index = c[index];
    }
    for (int i = res_vector.size()-1; i >= 0; i --)
        std::cout << res_vector[i] << " ";
    return result;

    delete[] b;
    delete[] c;
}
/////////////////////////////////////////////////////////////
// 数塔问题
int DigitTow(int a[][5], int n)
{
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j <= i; j ++)
        {
            a[i-1][j] += std::max(a[i][j], a[i][j+1]);

        }
    }
    return a[0][0];

}

// 最长上升公共子序列问题: LCS
int LCS(int a[], int b[], int len1, int len2)
{
    int dp[100][100];
    memset(dp, 0, 100);
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <=len2; j++)
        {
           if (a[i-1] == b[j-1])
               dp[i][j] = dp[i-1][j-1] + 1;
           else
               dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[len1][len2];

}


int main(int argc, char** argv)
{
    // back pack
//    int a[4] = {3,4,8,5};
//    int m = 10;
//    std::cout << "The full size: " << backPack(m, a, 4) << std::endl;

        int a[4] = {2, 3, 5, 7};
        int v[4] = {1, 5, 2, 4};
        int m = 10;
        std::cout << "The largest value: " << backPackII(m, a, v, 4) << std::endl;

    // Longest Increasing Subsequence
//    int a1[7] = {1, 4, 6, 2, 8, 9, 7};
////    std::cout << "Longest Increasing Subsequence: " << LIS(a1, 7) << std::endl;
//    std::cout << "Longest Increasing Subsequence: " << LIS1(a1, 7) << std::endl;

//    // // 数塔问题
//    int tow[5][5] = {{7},{3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
//    std::cout << "Digit Tow: " << DigitTow(tow, 5) << std::endl;

    // LCS
//    int a[5] = {1, 3, 4, 5, 5};
//    int b[6] = {2, 4, 5, 5, 7, 6};
//    std::cout << "LCS: " << LCS(a, b, 5, 6) << std::endl;


    return 0;
}
