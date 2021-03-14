/*
   ���ļ�����ʵ�ֱ༭���ľ��幦��
*/
#include "Editor.h"
#include <iostream>
#include <string>
using namespace std;
/*����*/
const int INITIAL_CAPACITY = 10; //��ʼ��������Ϊ10
/*
 *����˵�������캯������������
 *----------------------------
 *���캯����ʼ��˽�г�Ա��ֵ�����������ͷŶ��еĶ�����ռ�Ŀռ�
 */

//���캯����һ���ʼ����ֵ
Editor::Editor() {
    length = 0;
    cursor = 0;
    capacity = INITIAL_CAPACITY;
    array = new char[capacity]; //��ʼ���ַ��������� 
}
//��������
Editor::~Editor() {
    delete[] array;
}
/*
 *ʵ���ƶ��α�ķ����������������
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
  *ʵ�ֵķ�����delecteCharacter(); insertCharacter(char ch);
  *-----------------------------------
  *�����ɾ���ַ���ÿ�����ܶ������ƶ������е����к����ַ���
  *�Ա�Ϊ�²��������ռ䣬���߹ر�ɾ�����µĿռ�
  */
void Editor::insertCharacter(char ch) {
    if (cursor == length) expandCapacity();
    /*
     *��������ѡ��ӹ�굽bufferĩβ����һ���ַ�
     *Ȼ�����ǽ�ǰһλ��ֵ������һλ��ʵ���ڳ���
     *��Ĳ�����ʹ��ch���Բ���
     */
    for (int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }
    array[cursor] = ch; //��ch��ֵ��ֵ����ǰ�Ĺ�괦
    cursor++;
    length++;//������ַ�����ĳ�����Ӧ��1 
}
void Editor::deleteCharacter() {
    if (cursor < length) {
        /*
        *��������ѡ��ӹ�� +1 ��bufferĩβ����һ���ַ�
        *Ȼ�����ǽ���һλ��ֵ����ǰһλ��ʵ��������
        *��Ĳ���
        */
        for (int i = cursor + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
        length--;//�����,�ַ�����ĳ�����Ӧ��1 
    }
}
/*
  *������expandCapacity()
  *---------------------
  *���������ԭ��Ӧ�ü�ס�����ǽ�ԭarray�ڶ��е��׽ڵ��ַ�������Ƕ����
  *��Ӧ���͵� oldArray����ʱ��������ָ����е�ͬһ������
  *Ȼ��capacity����һ�����ڶ��н���һ��������Ϊcapacity *2������
  *֮���ԭoldArrayָ������ݸ��Ƹ��������ݺ��array
  *���ɾ��oldArray�е����ݣ�������ݲ���
  */
void Editor::expandCapacity() {
    char* oldArray = array; 
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] = oldArray[i]; //���� 
    }
    delete[] oldArray;
}
/*
  *���� ��showContent
  *------------------
  *�÷�����ӡ�����������ݣ�ÿ���ַ�֮����
  *һ���ո�������һ�в�����ŵĿռ䣬��ָʾ����λ��
  */
void Editor::showContents() {
    for (int i = 0; i < length; i++) {
        cout << " " << array[i];
    }
    cout << endl;
    cout << string(2 * cursor, ' ') << "^" << endl;
}
