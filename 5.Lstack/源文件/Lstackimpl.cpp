/*
*����ļ�����ʵ��Stackͷ�ļ��ж����һϵ�еķ���
*/
#ifdef _LStack_h
#include "error.h"

/*���캯��*/
template <typename ValueType>
Stack<ValueType>::Stack() {
	stack = NULL; //��ʼ״̬��ջ���Ľڵ�Ϊ�� 
	count = 0;  //ջ��Ԫ��Ϊ0
}
/*��������*/
template <typename ValueType>
Stack<ValueType>::~Stack() {
	clear();//�������ǵ�clear����
}
/*����ջ�Ĵ�С*/
template <typename ValueType>
int Stack<ValueType>::size() {
	return count;  //ֱ�ӷ���count�Ĵ�С
}
/*�ж�ջ�Ƿ�Ϊ��*/
template <typename ValueType>
bool Stack<ValueType>::isEmpty() {
	return count == 0;
}
/*���ջ*/
template <typename ValueType>
void Stack<ValueType>::clear() {
	if (count > 0)
	{
		pop();
	}
}
/*��ջ���߻�ͼ��д�������*/
template <typename ValueType>
void Stack<ValueType>::push(ValueType element) {
	Cell *cell = new Cell;
	cell->data = element;//����ڵ��ֵ
	cell->link = stack;//ָ��ջ���ĵڶ���Ԫ�أ�Ҳ����ͷ����ָ�루Ϊ�գ�
	stack = cell; //Ȼ��ͷ���ָ������ڵ�
	count++;
}
/*��ջ����*/
template <typename ValueType>
ValueType Stack<ValueType>::pop() {
	if (isEmpty()) error("pop: Attempting to pop an empty stack");
	Cell *cell = stack; //����һ��ָ�� ָ��ͷ�����ָ�Ľڵ�,ע�⣬stack����һ���ڵ㣬����ָ��
	ValueType nReturn = cell->data; //����������� �Ա㷵��
	stack = stack->link; //�ı�ͷ����ָ��
	count--; //ջ����һ
	delete cell; //ִ��ɾ������
	return nReturn;//����ջ��ֵ
}
/*�鿴ջ��Ԫ��*/
template <typename ValueType>
ValueType Stack<ValueType>::peek() {
	if (isEmpty()) error("peek: Attempting to peek at an empty stack");
	return stack->data;
}

#endif