private:
	/*栈的链表结构*/
	struct Cell {
		ValueType data;
		Cell *link;
	};
	/*实例化变量*/
	Cell *stack; /*定义一个cell类型的指针，指向栈顶*/
	int count;   /*用返回栈中的元素个数*/

				 /* Make it illegal to copy stacks */
	Stack(const Stack & value) { }
	const Stack & operator=(const Stack & rhs) { return *this; }
