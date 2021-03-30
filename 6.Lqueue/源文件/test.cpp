#include <iostream>
#include "Queue.h"
using namespace std;
int main(){
    Queue<int> myqueue;
    for (int i = 0; i < 10; i++)
    {
        myqueue.enqueue(i);
    }
    cout << "队伍的长度为： " << myqueue.size();
    cout << endl;
    cout << "队头为： " << myqueue.peek() << endl;
    myqueue.enqueue(10);
    cout << "将10加入队列后，长度为：" <<myqueue.size() << endl;
    myqueue.dequeue();
    cout << "执行出队操作后的队头为：" << myqueue.peek() << endl;
    return 0;
}