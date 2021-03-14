
#include "charstack.h"

#include "error.h"

using namespace std;



/*����*/

const int INITIAL_CAPACITY = 10;

/*���캯������������*/

CharStack::CharStack() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}

CharStack::~CharStack() {
    delete[] array;
}

int CharStack::size() {
    return count;
}

int CharStack::getCapacity() {
    return capacity;
}

bool CharStack::isEmpty() {
    return count == 0;
}

void CharStack::clear() {
    count = 0; /*ע�� ���ʱ������ֻ�ǰ�count��ֵ��ֵΪ0������ʵ�ʵ�Ԫ��

                *�����ڴ��У�ֻ�ǲ���������������ˣ����Բ������������ϵ�

                *����

                */
}

void CharStack::push(char ch) {
    if (count == capacity) expandCapacity();
    array[count] = ch; //��Ϊcount�Ǵ�0��ʼ����ģ����Բ���count+1 
    count++;

}

char CharStack::pop() {
    if (isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[count - 1];
    count--;
}

char CharStack::peek() {
    if (isEmpty()) error("peek: Attempting to peek at an empty stack");
    return array[count - 1];

}

void CharStack::expandCapacity() {
    char* oldArray = array;
    array = new char[capacity * 2];
    for (int i = 0; i < count; i++) {
        array[i] = oldArray[i];
    }
    delete[] oldArray;

}
