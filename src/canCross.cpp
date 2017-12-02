#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "list.h"
using namespace std;

bool canCross(vector<int> &stones)
{
    // write your code here
    unordered_map<int, unordered_set<int>> dp;
    for (auto position : stones)
        dp[position] = unordered_set<int>();
    dp[0].insert(0);
    for (auto position : stones)
    {
        for (auto k : dp[position])
        {
            // k - 1
            if (k - 1 > 0 && dp.find(position + k - 1) != dp.end())
                dp[position + k - 1].insert(k - 1);
            // k
            if (dp.find(position + k) != dp.end())
                dp[position + k].insert(k);
            // k + 1
            if (dp.find(position + k + 1) != dp.end())
                dp[position + k + 1].insert(k + 1);
        }
    }
    return !dp[stones.back()].empty();

}

int main(int argc, char** argv)
{
    int a[8] = {0,1,3,5,6,8,12,17};
    std::vector<int> stones(a, a+8);
    std::cout << "Can cross: " << canCross(stones) << std::endl;

    return 0;
}
