#include <iostream>
#include "Lstack.h" 
using namespace std;
int main() {
	Stack<int> mystack;
	for (int i = 0; i < 10; i++)
	{
		mystack.push(i);
	}
	cout << "栈顶元素为：" << mystack.peek() << endl;
	cout << "栈中共有" << mystack.size() << "个元素" << endl;
	int n = mystack.pop();
	cout << "出栈的元素为：" << n << endl;
	cout << "此时栈顶的元素为：" << mystack.peek() << endl;
	mystack.push(100);
	cout << "压入100后，此时的栈顶为：" << mystack.peek() << endl;
	mystack.clear();
	cout << "清空栈后，栈中的元素个数为：" << mystack.size() << endl;
	mystack.pop();
	return 0;
}