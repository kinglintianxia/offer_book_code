#include <iostream>
#include <vector>
#include <string>

#include "list.h"

ListNode * swapNodes(ListNode * head, int v1, int v2)
{
    // write your code here
    if (head == NULL)
        return NULL;
    ListNode* pre = new ListNode();
    pre->m_pNext = head;
    ListNode* p1r = pre;
    ListNode* p1 = head;
    ListNode* p2r = pre;
    ListNode* p2 = head;
    while (p1 != NULL && p2 !=NULL)
    {
        // find v1
        if (p1->m_nValue != v1)
        {
            p1 = p1->m_pNext;
            p1r = p1r->m_pNext;
        }
        // find v2
        if (p2->m_nValue != v2)
        {
            p2 = p2->m_pNext;
            p2r = p2r->m_pNext;
        }
        if (p1 != NULL && p2!= NULL && p1->m_nValue == v1 && p2->m_nValue == v2)
        {
            ListNode* p2n = p2->m_pNext;
            if (p1->m_pNext != p2)
            {
                p1r->m_pNext = p2;
                p2->m_pNext = p1->m_pNext;
                p2r->m_pNext = p1;
                p1->m_pNext = p2n;
            }
            else
            {
                p1r->m_pNext = p2;
                p2->m_pNext = p1;
                p1->m_pNext = p2n;
            }
            break;

        }

    }
    return pre->m_pNext;

}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    ConnectListNodes(pNode5, pNode7);

    ListNode* pMergedHead = swapNodes( pNode1, 1, 5);
    PrintList(pMergedHead);
    std::printf("\n");
    DestroyList(pMergedHead);
}

int main(int argc, char** argv)
{

    Test1();
    return 0;
}
