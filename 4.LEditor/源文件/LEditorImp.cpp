#include <string>
#include <iostream>
#include "LEditor.h"

using namespace std;

//�ڵ�ǰ�α�ָ��ĺ������Ԫ��
void LEditor::insertCharacter(char value) {
	Cell* cp = new Cell;//����һ���յ�cell������ָ��cpָ����
	cp->ch = value; //Ϊ�յ�cell��ֵ
	cp->link = cursor->link;//����ǰ�α�ָ��ĵ�ַ��ֵ����cell
	cursor->link = cp;//�����α���cell��ָ��
	cursor = cp;
}
//ɾ���α�ǰ��Ԫ��
void LEditor::deleteCharacter() {
	if (cursor->link != NULL) { //ȷ���α����ȷʵ���ڴ�Ԫ��
		Cell* deleteCell = cursor->link;//��ǵ�ǰ��Ҫɾ����cell
		cursor->link = cursor->link->link;//���α��ָ��ı�
		delete deleteCell; //ɾ�����cell
	}
}
//����һ����ָ�룬ָ���һ��cell
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
	Cell* cp = start;//����һ����ʱָ�룬��ͷ��ʼ
	if (cursor != start) {
		while (cp ->link != cursor) //��ǰ�ڵ����һ���ڵ㲻���α��ʱ����ǰ�ƶ�
		{
			cp = cp->link;
		}
		cursor = cp;//�α����Ų��һλ
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
		Cell* next = cp->link;//�ݴ���һ��Ҫɾ��������
		delete cp;//ɾ����ǰ�ڵ�
		cp = next;//���¸�ֵ��cp
	}
}