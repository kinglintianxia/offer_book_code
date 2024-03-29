#include <stdio.h>

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;

    ListNode () {}
    ListNode (int val)
    {
        this->m_nValue = val;
        this->m_pNext = NULL;
    }

};

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);
// __declspec( dllexport )
