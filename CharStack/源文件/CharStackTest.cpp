
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

    if (!mystack.isEmpty()) cout << "栈中的元素个数为" << mystack.size();

    cout << endl;

    char getElement = mystack.pop();

    cout << "被移除的元素为：" << getElement << endl;

    mystack.clear();

    cout << "清空栈后，元素个数为：" << mystack.size() << endl;

    cout << "此时的栈的容量为：" << mystack.getCapacity();

    return 0;

}
