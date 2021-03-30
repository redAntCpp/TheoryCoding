#ifdef _LQueue_h
#include "error.h"

/*构造函数,创建一个空队列*/
template<typename ValueType>
LQueue<ValueType>::LQueue(){
    head = tail = NULL; //队空的条件
    count = 0;
}

/*析构函数*/
template<typename ValueType>
LQueue<ValueType>::~LQueue(){
    clear();
}
/*返回队列的长度*/
template<typename ValueType>
int LQueue<ValueType>::size(){
    return count;
}

/*判断队列是否为空*/
template<typename ValueType>
bool LQueue<ValueType>::isEmpty(){
    return count == 0;
}
/*清空队列操作*/
template<typename ValueType>
void LQueue<ValueType>::clear(){
    while (count > 0)
    {
        deQueue();
    }
}

/*入队列操作
 *分为两步：1. 新建节点，并赋值
           2. 添加到队列中，考虑队列此时是否为空
 */
template<typename ValueType>
void LQueue<ValueType>::enQueue(ValueType elem){
    Cell *cell = new Cell;
    cell -> data = elem; //赋值
    cell -> link = NULL; //因为添加的是队尾，所以指向下一位的指针为空指针
    /*考虑，如果此刻的队列为空队列，那么我们新建的节点理所应当成为我们的队列的头指针*/
    if (head == NULL)
    {
        head = cell;
    }else{
        tail -> link = cell;
    }
    tail = cell; //将为指针的指向转向新建的尾节点
    count++;
}

/*出队列操作
 *分为三步：1.检测队列是否为空
           2.建立临时指针指向要出队的节点
           3.头指针指向后移，并删除临时指针
*/
template<typename ValueType>
ValueType LQueue<ValueType>::deQueue(){
    /*执行操作之前检测队列是否为空*/
    if (isEmpty())
    {
        error("deLQueue: Attempting to deLQueue an empty LQueue");
    }
    /*出队操作*/
    Cell *cell = head; //建立一个临时指针指向我们的头节点
    ValueType result = cell -> data;//记录当前的数据信息
    head = cell -> link;//头指针指向后移 
    if(head == NULL) tail = NULL;//当队列的头指针为空时，表明此刻的队列为空
    count--;
    delete cell;//删除临时节点
    return result;
}

/*返回队头的值*/
template<typename ValueType>
ValueType LQueue<ValueType>::peek(){
    if (isEmpty())
    {
        error("Attempting to peek at an empty LQueue");
    }
    return head -> data;
}