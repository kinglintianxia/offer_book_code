#include <iostream>
#include <vector>
#include <string>

void dfsCore(std::vector<std::vector<std::string>>& res_vec, std::vector<std::string>& str, int index, std::string s)
{
    if (index == s.size())
    {
        res_vec.push_back(str);
        return;
    }

    //
    for (int i = index; i < index + 2 && i < s.size(); i ++)
    {                       // i-index+1: Number of characters in substring
        std::string sub_str = s.substr(index, i-index+1);
        str.push_back(sub_str);
        dfsCore(res_vec, str, i+1, s);
        str.erase(str.end()-1);
    }

}

std::vector<std::vector<std::string>> splitString(std::string& s) {
    // write your code here
    std::vector<std::vector<std::string>> res_vec;
    std::vector<std::string> str;
    if (s.empty())
        return res_vec;
    dfsCore(res_vec, str, 0, s);
    return res_vec;
}

int main(int argc, char** argv)
{
    std::string str = "123";
    std::vector<std::vector<std::string>> res_vec;
    res_vec = splitString(str);
    for (int i = 0; i < res_vec.size(); i ++)
    {
        std::cout << "[";
        for (int j = 0; j < res_vec[i].size(); j ++)
            std::cout <<"\""<<res_vec[i][j] << "\",";
        std::cout << "],";
    }

    return 0;
}
