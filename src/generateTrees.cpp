#include <iostream>
#include <vector>
#include <string>

#include "binary_tree.h"
using namespace std;

std::vector<BinaryTreeNode*> generateTreesCore(int start, int end)
{
    std::vector<BinaryTreeNode*> res;
    std::vector<BinaryTreeNode*> left;
    std::vector<BinaryTreeNode*> right;
    if (start > end)
    {
        res.push_back(nullptr);
        return res;
    }
    if (start == end)
    {
        res.push_back(new BinaryTreeNode(start));
        return res;
    }
    for (int i = start; i <= end; i ++)
    {
        left = generateTreesCore(start, i-1);
        right = generateTreesCore(i+1, end);
        for (auto l:left)
        {
            for (auto r:right)
            {
                BinaryTreeNode* head = new BinaryTreeNode(i);
                head->m_pLeft = l;
                head->m_pRight = r;
                res.push_back(head);
            }
        }
    }
    return res;

}


vector<BinaryTreeNode *> generateTrees(int n) {
    // write your code here
    return generateTreesCore(1,n);

}


int main(int argc, char** argv)
{
    std::vector<BinaryTreeNode*> res;
    res = generateTrees(3);
    for (auto tree:res)
        PrintTree(tree);

    return 0;
}
