#include <iostream>
#include <vector>
#include <string>

#include "binary_tree.h"

bool isSubtreeCore(BinaryTreeNode* T1, BinaryTreeNode* T2)
{
    if (T1 == NULL && T2 == NULL)
        return true;
    if (T1 == NULL || T2 == NULL)
        return false;

    if (T1->m_nValue == T2->m_nValue)
        return isSubtreeCore(T1->m_pLeft, T2->m_pLeft) && isSubtreeCore(T1->m_pRight, T2->m_pRight);
    return false;

}

bool isSubtree(BinaryTreeNode * T1, BinaryTreeNode * T2)
{
    // write your code here
    if (T2 == NULL)
        return true;
    bool res = false;
    if (T1 != NULL && T2 != NULL)
    {
        if (T1->m_nValue == T2->m_nValue)
            res = isSubtreeCore(T1, T2);
        if (!res)
            res = isSubtree(T1->m_pLeft, T2);
        if (!res)
            res = isSubtree(T1->m_pRight, T2);
    }
    return res;
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
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    std::cout << isSubtree(pNode1, pNode3) << std::endl;

}

int main(int argc, char** argv)
{
    Test();

    return 0;
}
