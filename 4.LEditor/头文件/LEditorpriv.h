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
		char ch;  //����ַ��ĵط�
		Cell* link;//�����һ��Cell�ĵ�ַ��Ҳ����ָ��
	};
	/* Instance variables */
	Cell* start; //ͷָ�룬ָ���һ��Ԫ��
	Cell* cursor; //�αָ꣬��ǰѡ�е�cell

	/* Make it illegal to copy editor buffers */
	//LEditor(const LEditor& value) { }
	//const LEditor& operator=(const LEditor& rhs) { return *this; }