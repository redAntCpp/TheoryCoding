/*
*这个文件用于实现Stack头文件中定义的一系列的方法
*/
#ifdef _LStack_h
#include "error.h"

/*构造函数*/
template <typename ValueType>
Stack<ValueType>::Stack() {
	stack = NULL; //初始状态，栈顶的节点为空 
	count = 0;  //栈顶元素为0
}
/*析构函数*/
template <typename ValueType>
Stack<ValueType>::~Stack() {
	clear();//调用我们的clear函数
}
/*返回栈的大小*/
template <typename ValueType>
int Stack<ValueType>::size() {
	return count;  //直接返回count的大小
}
/*判断栈是否为空*/
template <typename ValueType>
bool Stack<ValueType>::isEmpty() {
	return count == 0;
}
/*清空栈*/
template <typename ValueType>
void Stack<ValueType>::clear() {
	if (count > 0)
	{
		pop();
	}
}
/*入栈，边画图边写代码理解*/
template <typename ValueType>
void Stack<ValueType>::push(ValueType element) {
	Cell *cell = new Cell;
	cell->data = element;//填入节点的值
	cell->link = stack;//指向栈顶的第二号元素，也就是头结点的指针（为空）
	stack = cell; //然后头结点指向这个节点
	count++;
}
/*出栈操作*/
template <typename ValueType>
ValueType Stack<ValueType>::pop() {
	if (isEmpty()) error("pop: Attempting to pop an empty stack");
	Cell *cell = stack; //定义一个指针 指向头结点所指的节点,注意，stack不是一个节点，它是指针
	ValueType nReturn = cell->data; //保存这个数据 以便返回
	stack = stack->link; //改变头结点的指向
	count--; //栈长减一
	delete cell; //执行删除操作
	return nReturn;//返回栈顶值
}
/*查看栈顶元素*/
template <typename ValueType>
ValueType Stack<ValueType>::peek() {
	if (isEmpty()) error("peek: Attempting to peek at an empty stack");
	return stack->data;
}

#endif