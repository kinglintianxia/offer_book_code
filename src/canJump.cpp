#include <iostream>
#include <vector>

using namespace std;

bool canJumpDP(vector<int> &A)
{
    // write your code here
    if (A.empty())
        return false;
    if (A.size() == 1)
        return true;
    int dp[A.size()];
    dp[0] = A[0];
    for (int i = 1; i < A.size(); i ++)
    {
        if (dp[i-1] >= i)
            dp[i] = std::max(A[i]+i, dp[i-1]);
        else
            dp[i] = 0;
    }
    // 2 4 4 4 8
    return dp[A.size()-1] >= A.size()-1;

}

int main(int argc, char** argv)
{
    int a[] = {2,3,1,1,4};
    std::vector<int> A(a, a+5);
    std::cout << "can jump: " << (bool)canJumpDP(A) << std::endl;
    return 0;
}
