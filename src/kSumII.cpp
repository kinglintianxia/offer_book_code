#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& A, int index, int k, int target, int sum, vector<int>& cur, vector<vector<int>> res_vec)
{
    if (cur.size() == k && sum == target)
    {
        res_vec.push_back(cur);
        return;
    }
    if (index == A.size())
        return;
    if (sum > target)
        return;
    cur.push_back(A[index]);
    dfs(A, index+1, k, target, sum+A[index], cur, res_vec);
    cur.pop_back();
    dfs(A, index+1, k, target, sum, cur, res_vec);

}

vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
    // write your code here
    std::vector<std::vector<int>> res_vec;
    std::vector<int> cur;
    dfs(A, 0, k, target, 0, cur, res_vec);
    return res_vec;
}

int main (int argc, char** argv)
{
    int a[4] = {1,2,3,4};
    std::vector<int> A(a, a+4);
    std::vector<std::vector<int>> res;
    res = kSumII(A, 2, 5);
    // print
    for (int i = 0; i < res.size(); i ++)
    {
        std::vector<int> vec = res[i];
        for (int j = 0; j < vec.size(); j ++)
            std::cout << vec[j] << ",";
    }

//    for (auto vec:res)
//        for (auto num:vec)
//            std::cout << num << ",";


    return 0;
}
