#ifndef _editor_h
#define _editor_h
class Editor {
public:
	Editor();
	~Editor();
	void moveCursorForward();
	void moveCursorBackward();
	void moveCursorToStart();
	void moveCursorToEnd();
	void insertCharacter(char ch);
	void deleteCharacter();
	void showContents();

    #include "Editorpriv.h" 
};

#endif
