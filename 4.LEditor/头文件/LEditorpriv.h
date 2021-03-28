#pragma once
private:
	/*
	* Type: Cell
	* ----------
	* This structure type is used locally within the implementation to
	* store each cell in the linked-list representation. Each cell
	* contains one character and a pointer to the next cell in the chain.
	*/
	struct Cell {
		char ch;  //存放字符的地方
		Cell* link;//存放下一个Cell的地址，也就是指针
	};
	/* Instance variables */
	Cell* start; //头指针，指向第一个元素
	Cell* cursor; //游标，指向当前选中的cell

	/* Make it illegal to copy editor buffers */
	//LEditor(const LEditor& value) { }
	//const LEditor& operator=(const LEditor& rhs) { return *this; }