#include <iostream>
#include <vector>
#include <string>

/*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
std::vector<std::string> longestWords(std::vector<std::string> &dictionary) {
    // write your code here
    std::vector<std::string> res_vect;
    if (dictionary.size() == 0)
        return res_vect;
    int max_size = -1;
    for (int i = 0 ; i < dictionary.size(); i ++)
    {
        int k = dictionary[i].size();
        if (max_size < k)
        {
            res_vect.clear();
            max_size = dictionary[i].size();
            res_vect.push_back(dictionary[i]);
        }
        else if (k == max_size)
        {
            res_vect.push_back(dictionary[i]);
        }
    }
    return res_vect;


}

int main(int argc, char** argv)
{
    std::string str[5] = {"dog","google","facebook","internationalization","blabla"};
    std::vector<std::string> str_vect(str, str+5);
    std::vector<std::string> res = longestWords(str_vect);
    for (int i = 0 ; i < res.size(); i ++)
        std::cout << res[i] << " ";
    std::printf("\n");

    return 0;
}
