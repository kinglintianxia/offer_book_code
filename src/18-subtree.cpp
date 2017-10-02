#include "binary_tree.h"

// SubstructureInTree.cpp : Defines the entry point for the console application.
//



bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

// king coding test
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    //
    if (pRoot1 != NULL && pRoot2 != NULL)
    {
        // Find the same root node
        if (pRoot1->m_nValue == pRoot2->m_nValue)
            // Step 2: is subtree?
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        // Not find the same root node, recursively find in pLeft and pRight
        if (!result)
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        if (!result)
            result = HasSubtree(pRoot1->m_pRight, pRoot2);

    }

    return result;

}
// Step 2: is subtree?
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    // Subtree end, IS subtree!
    if (pRoot2 == NULL)
        return true;
    // Root tree end, not subtree.
    if (pRoot1 == NULL)
        return false;
    // left subtree or right subtree != pRoot2->m_nValue, NOT THE SUBTREE!
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    // Continue next node
    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
        && DoesTree1HaveTree2(pRoot1->m_pRight , pRoot2->m_pRight);
}

// ====================²âÊÔ´úÂë====================
void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
    if(HasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

// Ê÷ÖÐ½áµãº¬ÓÐ·Ö²æ£¬Ê÷BÊÇÊ÷AµÄ×Ó½á¹¹
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test("Test1", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// Ê÷ÖÐ½áµãº¬ÓÐ·Ö²æ£¬Ê÷B²»ÊÇÊ÷AµÄ×Ó½á¹¹
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test("Test2", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// Ê÷ÖÐ½áµãÖ»ÓÐ×ó×Ó½áµã£¬Ê÷BÊÇÊ÷AµÄ×Ó½á¹¹
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    2
//         /
//        2
//       /
//      5
void Test3()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
    ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
    ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
    ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
    ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

    Test("Test3", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// Ê÷ÖÐ½áµãÖ»ÓÐ×ó×Ó½áµã£¬Ê÷B²»ÊÇÊ÷AµÄ×Ó½á¹¹
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    3
//         /
//        2
//       /
//      5
void Test4()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
    ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
    ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
    ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
    ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

    Test("Test4", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// Ê÷ÖÐ½áµãÖ»ÓÐÓÒ×Ó½áµã£¬Ê÷BÊÇÊ÷AµÄ×Ó½á¹¹
//       8                   8
//        \                   \
//         8                   9
//          \                   \
//           9                   2
//            \
//             2
//              \
//               5
void Test5()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
    ConnectTreeNodes(pNodeA2, NULL, pNodeA3);
    ConnectTreeNodes(pNodeA3, NULL, pNodeA4);
    ConnectTreeNodes(pNodeA4, NULL, pNodeA5);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
    ConnectTreeNodes(pNodeB2, NULL, pNodeB3);

    Test("Test5", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// Ê÷AÖÐ½áµãÖ»ÓÐÓÒ×Ó½áµã£¬Ê÷B²»ÊÇÊ÷AµÄ×Ó½á¹¹
//       8                   8
//        \                   \
//         8                   9
//          \                 / \
//           9               3   2
//            \
//             2
//              \
//               5
void Test6()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
    ConnectTreeNodes(pNodeA2, NULL, pNodeA3);
    ConnectTreeNodes(pNodeA3, NULL, pNodeA4);
    ConnectTreeNodes(pNodeA4, NULL, pNodeA5);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test("Test6", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// Ê÷AÎª¿ÕÊ÷
void Test7()
{
    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test("Test7", NULL, pNodeB1, false);

    DestroyTree(pNodeB1);
}

// Ê÷BÎª¿ÕÊ÷
void Test8()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
    ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

    Test("Test8", pNodeA1, NULL, false);

    DestroyTree(pNodeA1);
}

// Ê÷AºÍÊ÷B¶¼Îª¿Õ
void Test9()
{
    Test("Test9", NULL, NULL, false);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

