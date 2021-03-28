#include <string>
#include <iostream>
#include "LEditor.h"

using namespace std;

//在当前游标指向的后面插入元素
void LEditor::insertCharacter(char value) {
	Cell* cp = new Cell;//创建一个空的cell，并用指针cp指向它
	cp->ch = value; //为空的cell赋值
	cp->link = cursor->link;//将当前游标指向的地址赋值给空cell
	cursor->link = cp;//调整游标下cell的指向
	cursor = cp;
}
//删除游标前的元素
void LEditor::deleteCharacter() {
	if (cursor->link != NULL) { //确保游标后面确实存在此元素
		Cell* deleteCell = cursor->link;//标记当前需要删除的cell
		cursor->link = cursor->link->link;//将游标的指向改变
		delete deleteCell; //删除标记cell
	}
}
//创建一个空指针，指向第一个cell
LEditor::LEditor() {
	start = cursor = new Cell();
	start->link = NULL;
}

void LEditor::moveCursorForward() {
	if (cursor->link != NULL)
	{
		cursor = cursor->link;
	}
}

void LEditor::moveCursorToStart() {
	cursor = start;
}

void LEditor::moveCursorToEnd() {
	while (cursor->link != NULL)
	{
		cursor = cursor->link;
	}
}

void LEditor::moveCursorBackward() {
	Cell* cp = start;//定义一个临时指针，从头开始
	if (cursor != start) {
		while (cp ->link != cursor) //当前节点的下一个节点不是游标的时候，向前移动
		{
			cp = cp->link;
		}
		cursor = cp;//游标向后挪动一位
	}
}

void LEditor::showContents() {
	for (Cell* cp = start->link; cp != NULL; cp = cp->link) {
		cout << cp->ch << "->";
	}
	cout << endl;
	/*
	for (Cell* cp = start;cp != cursor;cp = cp->link)
	{
		cout << " ";
	}
	cout << '^' << endl;
	*/
}

LEditor::~LEditor() {
	Cell* cp = start;
	while (cp!= NULL)
	{
		Cell* next = cp->link;//暂存下一个要删除的内容
		delete cp;//删除当前节点
		cp = next;//重新赋值给cp
	}
}