/*
 *这个文件定义了charstack类，它用来实现char类型的栈抽象
 */
#ifndef _charstack_h
#define _charstack_h

 /*
  *这个类模拟char型的栈，它的基本类型类似于
  * stack <char>,我们现在用指定的基本类型去实现
  *这些抽象的操作，然后我们可以利用前面的模板知识
  *将这些转换为一般的模板
  */
class CharStack {
public:
        /*
        * 构造函数: CharStack
        * 用法: CharStack cstk;
        * ----------------------
        * 初始化一个新的空栈，使其能够装下一系列的字符
        */
        CharStack();
    /*
    * 析构函数: ~CharStack
    * 用法: 常常隐式调用
    * -------------------------
    * 释放这个结构在堆中占用的空间
    */
    ~CharStack();
    /*
    * 方法: size
    * 用法: int nElems = cstk.size();
    * --------------------------------
    * 返回栈中的字符数量
    */
    int size();
    /*
    * 方法: getCapacity()
    * 用法: int n = cstk.getCapacity();
    * --------------------------------
    * 返回栈中的容量
    */
    int getCapacity();
    /*
    * 方法: isEmpty
    * 用法: if (cstk.isEmpty()) . . .
    * --------------------------------
    * 当栈中没有字符元素的时候，返回true
    */

    bool isEmpty();
    /*
    * 方法: clear
    * 用法: cstk.clear();
    * --------------------
    * 移除栈中所有的元素
    */
    void clear();
    /*
    * 方法: push
    * 用法: cstk.push(ch);
    * ---------------------
    * 将一个元素压入栈中.
    */
    void push(char ch);
    /*
    * 方法: pop
    * 用法: char ch = cstk.pop();
    * ----------------------------
    * 移除栈顶元素并返回其值.
    */
    char pop();
    /*
    * 方法: peek
    * 用法: char ch = cstk.peek();
    * -----------------------------
    * 返回堆栈上的最上面的值，而不删除它。
    * 在空栈上调用查看会产生错误
    */
    char peek();

#include "charstackpriv.h"
};

#endif 