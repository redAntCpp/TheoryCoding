#pragma once
/*
 *EDITÍ·ÎÄ¼þ
 */
#ifndef _LEditor_h
#define _LEditor_h
class LEditor {
public:
	LEditor();
	~LEditor();
	void moveCursorForward();
	void moveCursorBackward();
	void moveCursorToStart();
	void moveCursorToEnd();
	void insertCharacter(char ch);
	void deleteCharacter();
	void showContents();

#include "LEditorpriv.h" 
};

#endif
