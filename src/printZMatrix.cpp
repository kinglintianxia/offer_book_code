#include <iostream>
#include <vector>
#include <string>


std::vector<int> printZMatrix(std::vector<std::vector<int>>& matrix)
{
    // write your code here
    std::vector<int> res_vec;
    if (matrix.empty() || matrix[0].empty())
        return res_vec;
    int n = matrix.size();
    int m = matrix[0].size();
    // 类似于层序遍历，设(x,y)是二维数组索引
    // 依次遍历x+y = 0,1,2,...,n+m-2的元素
    // x+y是奇数，y从min(x+y, m-1)开始减
    // x+y是偶数，x从min(x+y, n-1)开始减
    int i, j;
    for (int cnt = 0; cnt <= n+m-2; ++cnt)
    {
        // odd
        if (cnt%2 != 0)
        {
            for (j = std::min(cnt, m-1), i = cnt-j; i < n && j >= 0; ++i, --j)
                res_vec.push_back(matrix[i][j]);
        }
        // even
        else
        {
            for (i = std::min(cnt, n-1), j = cnt-i; i >= 0 && j < m; --i, ++j)
                res_vec.push_back(matrix[i][j]);
        }
    }
    return res_vec;

}


int main(int argc, char** argv)
{
    int a[3][4] = {{1, 2,  3,  4}, {5, 6,  7,  8}, {9,10, 11, 12}};
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < 3; i ++)
    {
        std::vector<int> tmp(a[i], a[i]+4);
        matrix.push_back(tmp);
    }

    std::vector<int> res;
    res = printZMatrix(matrix);
    std::cout << "[";
    for (int i = 0; i < res.size(); i ++)
        std::cout << res[i] << ",";
    std::cout << "]" << std::endl;
    return 0;
}
