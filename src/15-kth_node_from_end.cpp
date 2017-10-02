// KthNodeFromEnd.cpp : Defines the entry point for the console application.
//

// ¡¶½£Ö¸Offer¡ª¡ªÃûÆóÃæÊÔ¹Ù¾«½²µäÐÍ±à³ÌÌâ¡·´úÂë
// Öø×÷È¨ËùÓÐÕß£ººÎº£ÌÎ

#include <iostream>
#include <stdio.h>
#include "list.h"

// king coding
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if (pListHead == NULL || k <= 0)
    {
        std::cout << "Invalid input, please check it!" << std::endl;
        return NULL;
    }
    //
    ListNode* pFirst = pListHead;
    ListNode* pSecond = pListHead;
    int count = k - 1;
    while (pFirst->m_pNext != NULL && count --)
        pFirst= pFirst->m_pNext;
    // k > List length
    if (count > 0)
        return NULL;

    while (pFirst->m_pNext != NULL)
    {
        pFirst = pFirst->m_pNext;
        pSecond = pSecond->m_pNext;
    }

    return pSecond;


}

// ====================²âÊÔ´úÂë====================
// ²âÊÔÒªÕÒµÄ½áµãÔÚÁ´±íÖÐ¼ä
void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ²âÊÔÒªÕÒµÄ½áµãÊÇÁ´±íµÄÎ²½áµã
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ²âÊÔÒªÕÒµÄ½áµãÊÇÁ´±íµÄÍ·½áµã
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ²âÊÔ¿ÕÁ´±í
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: NULL.\n");
    ListNode* pNode = FindKthToTail(NULL, 100);
    PrintListNode(pNode);
}

// ²âÊÔÊäÈëµÄµÚ¶þ¸ö²ÎÊý´óÓÚÁ´±íµÄ½áµã×ÜÊý
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: NULL.\n");
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ²âÊÔÊäÈëµÄµÚ¶þ¸ö²ÎÊýÎª0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: NULL.\n");
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
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

