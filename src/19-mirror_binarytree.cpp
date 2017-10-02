// MirrorOfBinaryTree.cpp : Defines the entry point for the console application.
//


#include "binary_tree.h"

#include <iostream>
#include <stdio.h>
#include <stack>

// Recursively
void MirrorRecursively(BinaryTreeNode *pNode)
{
    // Input NULL binary tree
    if (pNode == NULL)
        return;
    // Leaf node, recursively over
    if (pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
        return;
    // Exchange left and right node
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if (pNode->m_pLeft != NULL)
        MirrorRecursively(pNode->m_pLeft);
    if (pNode->m_pRight != NULL)
        MirrorRecursively(pNode->m_pRight);

}

// Iteratively
void MirrorIteratively(BinaryTreeNode* pRoot)
{
    // Invalid input
    if (pRoot == NULL)
        return;

    std::stack<BinaryTreeNode* > stack_tree_node;
    stack_tree_node.push(pRoot);

    while (stack_tree_node.size() > 0)
    {
        BinaryTreeNode* pCurrent = stack_tree_node.top();
        stack_tree_node.pop();
        // Exchange
        BinaryTreeNode* pTemp = pCurrent->m_pLeft;
        pCurrent->m_pLeft = pCurrent->m_pRight;
        pCurrent->m_pRight = pTemp;

        if (pCurrent->m_pLeft != NULL)
            stack_tree_node.push(pCurrent->m_pLeft);
        if (pCurrent->m_pRight != NULL)
            stack_tree_node.push(pCurrent->m_pRight);

    }

    std::cout << "\nMirrorIteratively test!\n" << std::endl;
    PrintTree(pRoot);


}

// ====================²âÊÔ´úÂë====================
// ²âÊÔÍêÈ«¶þ²æÊ÷£º³ýÁËÒ¶×Ó½Úµã£¬ÆäËû½Úµã¶¼ÓÐÁ½¸ö×Ó½Úµã
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintTree(pNode8);

    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ²âÊÔ¶þ²æÊ÷£º³öÒ¶×Ó½áµãÖ®Íâ£¬×óÓÒµÄ½áµã¶¼ÓÐÇÒÖ»ÓÐÒ»¸ö×ó×Ó½áµã
//            8
//          7
//        6
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, NULL);
    ConnectTreeNodes(pNode7, pNode6, NULL);
    ConnectTreeNodes(pNode6, pNode5, NULL);
    ConnectTreeNodes(pNode5, pNode4, NULL);

    PrintTree(pNode8);

    printf("=====Test2: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test2: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ²âÊÔ¶þ²æÊ÷£º³öÒ¶×Ó½áµãÖ®Íâ£¬×óÓÒµÄ½áµã¶¼ÓÐÇÒÖ»ÓÐÒ»¸öÓÒ×Ó½áµã
//            8
//             7
//              6
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, NULL, pNode7);
    ConnectTreeNodes(pNode7, NULL, pNode6);
    ConnectTreeNodes(pNode6, NULL, pNode5);
    ConnectTreeNodes(pNode5, NULL, pNode4);

    PrintTree(pNode8);

    printf("=====Test3: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test3: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ²âÊÔ¿Õ¶þ²æÊ÷£º¸ù½áµãÎª¿ÕÖ¸Õë
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = NULL;

    PrintTree(pNode);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode);
    PrintTree(pNode);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode);
    PrintTree(pNode);
}

// ²âÊÔÖ»ÓÐÒ»¸ö½áµãµÄ¶þ²æÊ÷
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);

    printf("=====Test5: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test5: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
}

int main(int argc, char** argv)
{
    Test1();
//    Test2();
//    Test3();
//    Test4();
//    Test5();

    return 0;
}

