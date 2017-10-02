// ReverseList.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include "list.h"

// king coding
ListNode* ReverseList(ListNode* pHead)
{
    //
    ListNode* pAhead = NULL;
    ListNode* pCurrent = pHead;
    ListNode* pTail = NULL;
    while (pCurrent != NULL)
    {
        ListNode* pNext = pCurrent->m_pNext;
        if (pNext == NULL)
            pTail = pCurrent;
        pCurrent->m_pNext = pAhead;

        pAhead = pCurrent;
        pCurrent = pNext;

    }
    return pTail;

}

// ====================²âÊÔ´úÂë====================
ListNode* Test(ListNode* pHead)
{
    printf("\nThe original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("\nThe reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ÊäÈëµÄÁ´±íÓÐ¶à¸ö½áµã
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ÊäÈëµÄÁ´±íÖ»ÓÐÒ»¸ö½áµã
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ÊäÈë¿ÕÁ´±í
void Test3()
{
    Test(NULL);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();

    return 0;
}

