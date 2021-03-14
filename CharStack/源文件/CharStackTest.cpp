
#include <iostream>

#include <string>

#include "charstack.h" 

using namespace std;

int main() {

    CharStack mystack;

    for (int i = 0; i < 5; i++) {

        char ch;

        cin >> ch;

        mystack.push(ch);

    }

    if (!mystack.isEmpty()) cout << "ջ�е�Ԫ�ظ���Ϊ" << mystack.size();

    cout << endl;

    char getElement = mystack.pop();

    cout << "���Ƴ���Ԫ��Ϊ��" << getElement << endl;

    mystack.clear();

    cout << "���ջ��Ԫ�ظ���Ϊ��" << mystack.size() << endl;

    cout << "��ʱ��ջ������Ϊ��" << mystack.getCapacity();

    return 0;

}
