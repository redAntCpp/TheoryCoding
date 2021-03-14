#include <iostream>
#include "Editor.h"
#include <string>
#include <cctype>

using namespace std;
/*函数声明*/
void executeCommand(Editor& buffer, string line);
int main() {
	Editor buffer;
	while (true)
	{
		cout << "*";
		string cmd;
		getline(cin, cmd);//输入命令
		if (cmd != "") executeCommand(buffer, cmd);
		buffer.showContents();//显示文本
	}
	return 0;
}
void executeCommand(Editor& buffer, string line) {
	switch (toupper(line[0])) {
	case 'I': for (int i = 1; i < line.length(); i++) {
		buffer.insertCharacter(line[i]);
	}
	break; //命令执行完毕退出
	case 'D': buffer.deleteCharacter(); break;
	case 'F': buffer.moveCursorForward(); break;
	case 'B': buffer.moveCursorBackward(); break;
	case 'J': buffer.moveCursorToStart(); break;
	case 'Z': buffer.moveCursorToEnd(); break;
	case 'Q': exit(0);
	default: cout << "Illegal command" << endl; break;
	}
}