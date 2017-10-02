// MergeSortedLists.cpp : Defines the entry point for the console application.
//

// ¡¶½£Ö¸Offer¡ª¡ªÃûÆóÃæÊÔ¹Ù¾«½²µäÐÍ±à³ÌÌâ¡·´úÂë
// Öø×÷È¨ËùÓÐÕß£ººÎº£ÌÎ

#include <iostream>
#include <stdio.h>
#include "list.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* pSortedList = NULL;
    if (pHead1 == NULL)
        return pHead2;
    if (pHead2 == NULL)
        return pHead1;
    //
    ListNode* pList1 = pHead1;
    ListNode* pList2 = pHead2;
    if (pList1->m_nValue < pList2->m_nValue)
    {
        pSortedList = pList1;
        pSortedList->m_pNext = Merge(pList1->m_pNext, pList2);

    }
    else
    {
        pSortedList = pList2;
        pSortedList->m_pNext = Merge(pList1, pList2->m_pNext);
    }

    return pSortedList;

}

// ====================²âÊÔ´úÂë====================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("\nThe first list is:\n");
    PrintList(pHead1);

    printf("\nThe second list is:\n");
    PrintList(pHead2);

    printf("\nThe merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// Á½¸öÁ´±íÖÐÓÐÖØ¸´µÄÊý×Ö
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// Á½¸öÁ´±í¶¼Ö»ÓÐÒ»¸öÊý×Ö
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// Ò»¸öÁ´±íÎª¿ÕÁ´±í
// list1: 1->3->5
// list2: ¿ÕÁ´±í
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, NULL);

    DestroyList(pMergedHead);
}

// Á½¸öÁ´±í¶¼Îª¿ÕÁ´±í
// list1: ¿ÕÁ´±í
// list2: ¿ÕÁ´±í
void Test5()
{
    ListNode* pMergedHead = Test("Test5", NULL, NULL);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

