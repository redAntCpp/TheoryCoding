/*
*这部分文件实现我们之前所使用的stack类
*它主要的原理为 后进先出（LIFO）
*/

#ifndef _LStack_h
#define _LStack_h

/*
*类型: Stack<ValueType>
*此类建立一个称为堆栈的线性结构，其中仅从一端添加和删除值。
*这个规定产生了一个（LIFO）的行为，它是堆栈的定义特征。
*基本堆栈操作是push（添加元素到顶部）和pop（把元素从顶部删除）。
*/
template <typename ValueType>
class Stack {
public:
	/*
	*构造函数：Stack
	*用法：Stack <ValueType> stack
	*-----------------------------
	*初始化一个空栈
	*/
	Stack();
	//析构函数
	~Stack();
	/*
	*方法：size（）
	*用法：int n = stack.size();
	*--------------------------
	*返回栈中元素的个数
	*/
	int size();
	/*
	*方法：isEmpty（）
	*用法：stack.isEmpty();
	*--------------------------
	*判断栈中元素是否为空
	*/
	bool isEmpty();
	/*
	*方法：clear（）
	*用法：stack.clear();
	*--------------------------
	*清空栈中的所有元素
	*/
	void clear();
	/*
	*方法：push（）
	*用法：stack.push();
	*--------------------------
	*向栈顶推入一个元素
	*/
	void push(ValueType);
	/*
	*方法：pop（）
	*用法：stack.pop();
	*--------------------------
	*移除栈顶的一个元素,并返回其值，如果栈空 则返回一个错误
	*/
	ValueType pop();
	/*
	*方法：peek（）
	*用法：stack.peek();
	*--------------------------
	*返回栈顶的值，但是不移除，peek 偷看的意思,如果栈空 则返回一个错误
	*/
	ValueType peek();

#include "Lstackpriv.h" //私有成员部分


};

#include "Lstackimpl.cpp" //将实现文件包含进来 

#endif
