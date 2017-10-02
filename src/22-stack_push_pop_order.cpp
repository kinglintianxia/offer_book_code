// StackPushPopOrder.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <stack>

// king coding
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    if (pPush == NULL || pPop == NULL)
    {
        std::cout << "Invalid input, please check it!" << std::endl;
        return false;
    }
    // Prepare data
    std::stack<int> data_stack;
    int push_count = 0;
    int pop_count = 0;
    // First push in stack
    data_stack.push(pPush[pop_count]);
    push_count +=1;
    // Iteration
    while (pop_count < nLength)
    {
        while (data_stack.top() != pPop[pop_count] && push_count < nLength)
        {
            data_stack.push(pPush[push_count]);
            push_count++;
        }
        if (data_stack.top() == pPop[pop_count] && pop_count < nLength)
        {
            data_stack.pop();
            pop_count++;
        }

        // End
        if (data_stack.size() == 0)
            break;
        // Not find
        if (push_count == nLength && data_stack.top() != pPop[pop_count])
            return false;

    }
    return true;
}

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};

    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};

    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};

    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};

    Test("Test4", push, pop, nLength, false);
}

// pushºÍpopÐòÁÐÖ»ÓÐÒ»¸öÊý×Ö
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", NULL, NULL, 0, false);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

