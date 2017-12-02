#include <iostream>
#include <vector>
#include <string>

#include "list.h"


ListNode* mergeSort(ListNode* l1, ListNode* l2)
{
    ListNode* res = new ListNode();
    ListNode* node = res;
    while (l1 && l2)
    {
        if (l1->m_nValue < l2->m_nValue)
        {
            node->m_pNext = l1;
            l1 = l1->m_pNext;
        }
        else
        {
            node->m_pNext = l2;
            l2 = l2->m_pNext;
        }
        node = node->m_pNext;
    }
    if (l1)
        node->m_pNext = l1;
    if (l2)
        node->m_pNext = l2;
    // return
    return res->m_pNext;
}

ListNode * sortList(ListNode * head)
{
    // write your code here
    if (head == NULL || head->m_pNext == NULL)
        return head;
    // find mid
    ListNode *fast = head, *slow = head, *mid = head;
    while (fast != NULL && fast->m_pNext != NULL)
    {
        mid = slow;
        slow = slow->m_pNext;
        fast = fast->m_pNext->m_pNext;
    }
    // spilt listnode
    mid->m_pNext = NULL;
    // !!!
    return mergeSort(sortList(head), sortList(slow));
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
    ListNode* res = sortList(pNode1);
    // Print list
    PrintList(res);

}

int main(int argc, char** argv)
{
    Test();

    return 0;
}
