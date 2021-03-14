
#include "charstack.h"

#include "error.h"

using namespace std;



/*常量*/

const int INITIAL_CAPACITY = 10;

/*构造函数和析构函数*/

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
    count = 0; /*注意 这个时候我们只是把count的值赋值为0，但是实际的元素

                *还在内存中，只是不在这个对象里面了，所以不是真正意义上的

                *销毁

                */
}

void CharStack::push(char ch) {
    if (count == capacity) expandCapacity();
    array[count] = ch; //因为count是从0开始计算的，所以不是count+1 
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
