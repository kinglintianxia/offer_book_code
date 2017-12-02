#include <iostream>
#include <vector>
#include <string>

#include "list.h"


ListNode* insertionSortList(ListNode * head)
{
    // write your code here
    if (head == NULL)
        return NULL;
    ListNode* dummy = new ListNode(0);
    while (head != NULL)
    {
        ListNode* node = dummy;
        while (node->m_pNext != NULL && node->m_pNext->m_nValue < head->m_nValue)
        {
            node = node->m_pNext;
        }
        ListNode* next = head->m_pNext;
        head->m_pNext = node->m_pNext;
        node->m_pNext = head;
        head = next;

    }
    return dummy->m_pNext;


}

// 1->3->5->2->4->null
void Test()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    ConnectListNodes(pNode5, pNode2);
    ConnectListNodes(pNode2, pNode4);
    ListNode* res = insertionSortList(pNode1);
    // Print list
    PrintList(res);

}

int main(int argc, char** argv)
{
    Test();

    return 0;
}
