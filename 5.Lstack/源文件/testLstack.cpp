#include <iostream>
#include "Lstack.h" 
using namespace std;
int main() {
	Stack<int> mystack;
	for (int i = 0; i < 10; i++)
	{
		mystack.push(i);
	}
	cout << "ջ��Ԫ��Ϊ��" << mystack.peek() << endl;
	cout << "ջ�й���" << mystack.size() << "��Ԫ��" << endl;
	int n = mystack.pop();
	cout << "��ջ��Ԫ��Ϊ��" << n << endl;
	cout << "��ʱջ����Ԫ��Ϊ��" << mystack.peek() << endl;
	mystack.push(100);
	cout << "ѹ��100�󣬴�ʱ��ջ��Ϊ��" << mystack.peek() << endl;
	mystack.clear();
	cout << "���ջ��ջ�е�Ԫ�ظ���Ϊ��" << mystack.size() << endl;
	mystack.pop();
	return 0;
}