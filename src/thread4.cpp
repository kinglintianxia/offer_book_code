#include <iostream>
#include <unistd.h> // sleep
#include <thread>
#include <mutex>

using namespace std;

mutex mu;  //线程互斥对象

int totalNum = 100;

void thread01()
{
    while (totalNum > 0)
    {
        mu.lock(); //同步数据锁
        cout << "thread1: " << totalNum << endl;
        totalNum--;
        mu.unlock();  //解除锁定
        sleep(1); // 1 sec
    }
}
void thread02()
{
    while (totalNum > 0)
    {
        mu.lock();
        cout << "thread2: " << totalNum << endl;
        totalNum--;
        mu.unlock();
        sleep(2); // 1 sec
    }
}

int main(int argc, char** argv)
{
    thread task01(thread01);
    thread task02(thread02);
    task01.detach();
    task02.detach();
    while (1)
    {
        sleep(1);
    }

//    task01.join();
//    task02.join();

    return 0;
}
