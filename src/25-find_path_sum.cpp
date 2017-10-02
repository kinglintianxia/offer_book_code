// PathInTree.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include "binary_tree.h"

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum);

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if(pRoot == NULL)
        return;

    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode*   pRoot,
              int               expectedSum,
              std::vector<int>& path,
              int&              currentSum
              )
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    // Èç¹ûÊÇÒ¶œáµã£¬²¢ÇÒÂ·Ÿ¶ÉÏœáµãµÄºÍµÈÓÚÊäÈëµÄÖµ
    // ŽòÓ¡³öÕâÌõÂ·Ÿ¶
    bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
    if(currentSum == expectedSum && isLeaf)
    {
        printf("A path is found: ");
        std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++ iter)
            printf("%d\t", *iter);

        printf("\n");
    }

    // Èç¹û²»ÊÇÒ¶œáµã£¬Ôò±éÀúËüµÄ×Óœáµã
    if(pRoot->m_pLeft != NULL)
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    if(pRoot->m_pRight != NULL)
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

    // ÔÚ·µ»ØµœžžœáµãÖ®Ç°£¬ÔÚÂ·Ÿ¶ÉÏÉŸ³ýµ±Ç°œáµã£¬
    // ²¢ÔÚcurrentSumÖÐŒõÈ¥µ±Ç°œáµãµÄÖµ
    currentSum -= pRoot->m_nValue;
    path.pop_back();
}

// Only true or false
bool hasPathSum(BinaryTreeNode *root, int sum)
{
    if(root==NULL)
        return NULL;
    if(root->m_pLeft==NULL&&root->m_pRight==NULL&&sum-root->m_nValue==0)
        return true;
    return hasPathSum(root->m_pLeft,sum-root->m_nValue) || hasPathSum(root->m_pRight,sum-root->m_nValue);

}

// ====================²âÊÔŽúÂë====================
void Test(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
//
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);
    std::cout << "Had path sum: \n";
    std::cout << hasPathSum(pNode10, 22) << std::endl;
    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// Ã»ÓÐÂ·Ÿ¶ÉÏµÄœáµãºÍÎª15
void Test2()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

    DestroyTree(pNode10);
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
// ÓÐÒ»ÌõÂ·Ÿ¶ÉÏÃæµÄœáµãºÍÎª15
void Test3()
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

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// Ã»ÓÐÂ·Ÿ¶ÉÏÃæµÄœáµãºÍÎª16
void Test4()
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

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// Ê÷ÖÐÖ»ÓÐ1žöœáµã
void Test5()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// Ê÷ÖÐÃ»ÓÐœáµã
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", NULL, 0);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
