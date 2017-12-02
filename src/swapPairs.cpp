#include <iostream>
#include <vector>
#include <string>

#include "list.h"

ListNode * swapPairs(ListNode * head)
{
    // write your code here
    if (head == NULL)
        return NULL;
    ListNode* pr = new ListNode();
    pr->m_pNext = head;
    ListNode* res = pr;
    ListNode* pc = head;
    while (pc != NULL)
    {
        ListNode* pn = pc->m_pNext;
        if (pn != NULL)
        {
            pr->m_pNext = pn;
            pc->m_pNext = pn->m_pNext;
            pn->m_pNext = pc;
            // for iterator
            pr = pc;
            pc = pc->m_pNext;
        }
        else
            pc = pc->m_pNext;

    }
    return res->m_pNext;

}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    //ListNode* pNode7 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    //ConnectListNodes(pNode5, pNode7);

    ListNode* pMergedHead = swapPairs( pNode1);
    PrintList(pMergedHead);
    std::printf("\n");
    DestroyList(pMergedHead);
}

int main(int argc, char** argv)
{

    Test1();
    return 0;
}
