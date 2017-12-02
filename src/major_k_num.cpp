#include <iostream>
#include <vector>
#include <map>

int majorityNumber(int nums[], int len, int k)
{
    // write your code here
    int result = 0, max_count = 0;
    std::map<int, int> hash_map;
    std::map<int, int>::iterator it;
    //
    for (int i = 0; i < len; i ++)
    {
        int size = hash_map.size();

        it = hash_map.find(nums[i]);
        if (it == hash_map.end())
            hash_map.insert(std::pair<int, int>(nums[i], 1));
        else
            (it->second) ++;

        if (hash_map.size() == k)
        {
            for (it = hash_map.begin(); it != hash_map.end(); )
            {
                (it->second) --;
                if (it->second == 0)
                    hash_map.erase(it ++);
                else
                    it ++;

            }

        }

    }

    // zero
    for (it = hash_map.begin(); it != hash_map.end(); it ++)
        it->second = 0;
    for (int i = 0; i < len; i ++)
    {
        it = hash_map.find(nums[i]);
        if (it != hash_map.end())
        {
            (it->second) ++;
            if (it->second > max_count)
            {
                max_count = it->second;
                result = it->first;
            }
        }

    }
    return result;

}


int main(int argc, char** argv)
{
//    int a[10] = {1,1,2,3,3,3,2,2,4,1};
//    std::cout << "Single number: " << singleNumberII(a, 10) << std::endl;
    int a[6] = {1,2,3,4,4,5};

    std::cout << "Major 1/k number: " << majorityNumber(a, 6, 4) << std::endl;

    return 0;
}
