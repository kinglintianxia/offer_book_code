// MergeSortedLists.cpp : Defines the entry point for the console application.
//

// ¡¶½£Ö¸Offer¡ª¡ªÃûÆóÃæÊÔ¹Ù¾«½²µäÐÍ±à³ÌÌâ¡·´úÂë
// Öø×÷È¨ËùÓÐÕß£ººÎº£ÌÎ

#include <iostream>
#include <stdio.h>
#include "list.h"


ListNode* Test(ListNode * l1, ListNode * l2)
{
    // write your code here
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    if (l1 == NULL && l2 == NULL)
        return NULL;

    ListNode* pL1 = l1;
    ListNode* pL2 = l2;
    ListNode* sum = new ListNode();
    ListNode* pSum = sum;
    int carry = 0;
    while (pL1 != NULL && pL2 != NULL)
    {
        pSum->m_nValue = pL1->m_nValue + pL2->m_nValue + carry;
        carry = 0;
        if (pSum->m_nValue >= 10)
        {
            pSum->m_nValue %= 10;
            carry = 1;
        }
        pL1 = pL1->m_pNext;
        pL2 = pL2->m_pNext;
        if (pL1 != NULL && pL2 != NULL)
        {
            pSum->m_pNext = new ListNode();
            pSum = pSum->m_pNext;

        }

    }
    if (pL1 != NULL)
    {
        while (pL1 != NULL)
        {
            pSum->m_pNext = new ListNode();
            pSum = pSum->m_pNext;

            pSum->m_nValue = pL1->m_nValue + carry;
            carry = 0;
            if (pSum->m_nValue >= 10)
            {
                pSum->m_nValue %= 10;
                carry = 1;
            }
            pL1 = pL1->m_pNext;

        }

    }
    else if (pL2 != NULL)
    {
        while (pL2 != NULL)
        {
            pSum->m_pNext = new ListNode();
            pSum = pSum->m_pNext;

            pSum->m_nValue = pL2->m_nValue + carry;
            carry = 0;
            if (pSum->m_nValue >= 10)
            {
                pSum->m_nValue %= 10;
                carry = 1;
            }
            pL2 = pL2->m_pNext;

        }

    }
    //最后一个数看是不是大于10，
    if(carry==1)
    {
        pSum->m_pNext = new ListNode();
        pSum = pSum->m_pNext;
        pSum->m_nValue = 1;
        pSum->m_pNext = NULL;
    }
    else
    {
        pSum->m_pNext=NULL;
    }

    return sum;

}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(3);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(5);
    ListNode* pNode4 = CreateListNode(9);
//    ListNode* pNode6 = CreateListNode(2);

    ConnectListNodes(pNode2, pNode4);
//    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test( pNode1, pNode2);
    PrintList(pMergedHead);
    std::printf("\n");
    DestroyList(pMergedHead);
}



int main(int argc, char** argv)
{
    Test1();


    return 0;
}

