#include <iostream>
#include <vector>
#include <string>

#include "binary_tree.h"

using namespace std;
std::vector<std::vector<int>> res_vec;


void findPath(BinaryTreeNode * root, std::vector<int>& path, int target)
{
    // current target
    target -= root->m_nValue;
    path.push_back(root->m_nValue);
    if (target == 0 && root->m_pLeft == NULL && root->m_pRight == NULL)
        res_vec.push_back(path);

    if (root->m_pLeft != NULL)
        findPath(root->m_pLeft, path, target);
    if (root->m_pRight != NULL)
        findPath(root->m_pRight, path, target);
    // back to delete current val !!!
    path.pop_back();

}

vector<vector<int>> binaryTreePathSum(BinaryTreeNode * root, int target)
{
    // write your code here
    if (root == NULL)
        return res_vec;
    std::vector<int> path;
    findPath(root, path, target);
    return res_vec;

}

//            1
//          /    \
//         2      4
//        /\
//       2  3
void Test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);


    ConnectTreeNodes(pNode1, pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5, pNode3);

    std::vector<std::vector<int>> res;
    res = binaryTreePathSum(pNode1, 5);
    // print
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < res[i].size(); j ++)
        {
            std::printf("%d,", res[i][j]);
        }
        std::cout << "] \n";
    }

}

int main(int argc, char** argv)
{
    Test();

    return 0;
}
