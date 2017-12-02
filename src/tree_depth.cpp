#include <iostream>
#include "binary_tree.h"

int maxDepth(BinaryTreeNode *root)
{
    // write your code here
    if (root == NULL)
        return 0;
    int left = maxDepth(root->m_pLeft);
    int right = maxDepth(root->m_pRight);
    return left>right ? left + 1:right + 1;

}
/****
与二叉树的最大深度不同，不能单纯地使用递归，因为二叉树的深度必须是根结点到叶子结点的距离，
不能单纯的比较左右子树的递归结果返回较小值，因为对于有单个孩子为空的节点，为空的孩子会返回0，
但这个节点并非叶子节点，故返回的结果是错误的。
*****/
int minDepth(BinaryTreeNode *root)
{
    // write your code here
    if (root == NULL)
        return 0;
    if (root->m_pLeft == NULL && root->m_pRight == NULL)
        return 1;
    int left = minDepth(root->m_pLeft) + 1;
    int right = minDepth(root->m_pRight) + 1;
    left = (left == 1 ? INT32_MAX : left);
    right = (right == 1 ? INT32_MAX : right);

    return left<right ? left:right;
}


//            10
//          /    \
//         6      14
//        /\       /\
//       4  8    12  16
int Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    int result = maxDepth(pNode10);
//    int result = minDepth(pNode10);
    DestroyTree(pNode10);

    return result;
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
int Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    int result = minDepth(pNode5);
//    int result = minDepth(pNode10);

    DestroyTree(pNode5);
    return result;
}

int main(int argc, char** argv)
{

    std::cout << "Tree maxDepth: " << Test1() << std::endl;
    std::cout << "Tree minDepth: " << Test2() << std::endl;
    return 0;
}
