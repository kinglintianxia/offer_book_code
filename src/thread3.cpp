#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int totalNum = 10;

void thread01()
{
    while (totalNum > 0)
    {
        cout << totalNum << endl;
        totalNum--;
        sleep(1); // 1 sec
    }
}
void thread02()
{
    while (totalNum > 0)
    {
        cout << totalNum << endl;
        totalNum--;
        sleep(1); // 1 sec
    }
}

int main()
{
    thread task01(thread01);
    thread task02(thread02);
    // main thread need sleep
//    task01.detach();
//    task02.detach();

    task01.join();
    task02.join();


}
