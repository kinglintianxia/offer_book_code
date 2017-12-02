#include <iostream>
#include <string>
#include <vector>

void MakeQuote(int size, int left, int right, std::string& str, std::vector<std::string>& res_str)
{
    if (size == 0)
    {
        res_str.push_back(str);
        return;
    }
    if (left > 0)
    {
        str.insert(str.size(), "(");
        MakeQuote(size-1, left-1, right, str, res_str);
        str = str.substr(0, str.size()-1);
    }
    if (right > 0 && left < right)
    {
        str.insert(str.size(), ")");
        MakeQuote(size-1, left, right-1, str, res_str);
        str = str.substr(0, str.size()-1);
    }

}

std::vector<std::string> generateParenthesis(int n)
{
    // write your code here
    std::vector<std::string> res_str;
    std::string temp_str;
    MakeQuote(2*n, n, n, temp_str, res_str);
    return res_str;

}

int main(int argc, char** argv)
{
    int n = 2;
    std::vector<std::string> result_str;
//    std::cin >> n;

    result_str = generateParenthesis(n);
    for (int i = 0; i < result_str.size(); i ++)
        std::cout << result_str[i] << " ";
    std::printf("\n");



    return 0;
}
