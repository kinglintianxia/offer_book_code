#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void thread01()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 01 is working ！" << endl;
        sleep(1);
    }
}
void thread02()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 02 is working ！" << endl;
        sleep(1);
    }
}

int main()
{
    thread task01(thread01);
    thread task02(thread02);
    // 两个子线程并行执行，join函数会阻塞主流程，所以子线程都执行完成之后才继续执行主线程。
//    task01.join();
//    task02.join();

    // 使用detach的主线程和两个子线程并行执行
    task01.detach();
    task02.detach();

    for (int i = 0; i < 5; i++)
    {
        cout << "Main thread is working ！" << endl;
        sleep(2);
    }
//    system("pause");
}
