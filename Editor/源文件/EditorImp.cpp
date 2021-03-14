/*
   此文件用于实现编辑器的具体功能
*/
#include "Editor.h"
#include <iostream>
#include <string>
using namespace std;
/*常数*/
const int INITIAL_CAPACITY = 10; //初始化的容量为10
/*
 *函数说明：构造函数和析构函数
 *----------------------------
 *构造函数初始化私有成员的值，析构函数释放堆中的对象所占的空间
 */

//构造函数，一般初始化数值
Editor::Editor() {
    length = 0;
    cursor = 0;
    capacity = INITIAL_CAPACITY;
    array = new char[capacity]; //初始化字符数组容量 
}
//析构函数
Editor::~Editor() {
    delete[] array;
}
/*
 *实现移动游标的方法，考虑特殊情况
 */
void Editor::moveCursorForward() {
    if (cursor < length) cursor++;
}
void Editor::moveCursorBackward() {
    if (cursor > 0) cursor--;
}
void Editor::moveCursorToStart() {
    cursor = 0;
}
void Editor::moveCursorToEnd() {
    cursor = length;
}
/*
  *实现的方法：delecteCharacter(); insertCharacter(char ch);
  *-----------------------------------
  *插入或删除字符的每个功能都必须移动数组中的所有后续字符，
  *以便为新插入留出空间，或者关闭删除留下的空间
  */
void Editor::insertCharacter(char ch) {
    if (cursor == length) expandCapacity();
    /*
     *这里我们选择从光标到buffer末尾的这一段字符
     *然后我们将前一位的值赋给后一位，实现腾出空
     *间的操作，使得ch可以插入
     */
    for (int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }
    array[cursor] = ch; //将ch的值赋值给当前的光标处
    cursor++;
    length++;//插入后，字符数组的长度相应加1 
}
void Editor::deleteCharacter() {
    if (cursor < length) {
        /*
        *这里我们选择从光标 +1 到buffer末尾的这一段字符
        *然后我们将后一位的值赋给前一位，实现收缩空
        *间的操作
        */
        for (int i = cursor + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
        length--;//插入后,字符数组的长度相应减1 
    }
}
/*
  *方法：expandCapacity()
  *---------------------
  *这个方法的原理应该记住，我们将原array在堆中的首节点地址赋给我们定义的
  *相应类型的 oldArray，此时他们两个指向堆中的同一个数组
  *然后将capacity扩大一倍，在堆中建立一个新容量为capacity *2的数组
  *之后把原oldArray指向的内容复制给现在扩容后的array
  *最后删除oldArray中的内容，完成扩容操作
  */
void Editor::expandCapacity() {
    char* oldArray = array; 
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] = oldArray[i]; //复制 
    }
    delete[] oldArray;
}
/*
  *方法 ：showContent
  *------------------
  *该方法打印缓冲区的内容，每个字符之间有
  *一个空格，留下下一行插入符号的空间，以指示光标的位置
  */
void Editor::showContents() {
    for (int i = 0; i < length; i++) {
        cout << " " << array[i];
    }
    cout << endl;
    cout << string(2 * cursor, ' ') << "^" << endl;
}
