private:
	/*ջ������ṹ*/
	struct Cell {
		ValueType data;
		Cell *link;
	};
	/*ʵ��������*/
	Cell *stack; /*����һ��cell���͵�ָ�룬ָ��ջ��*/
	int count;   /*�÷���ջ�е�Ԫ�ظ���*/

				 /* Make it illegal to copy stacks */
	Stack(const Stack & value) { }
	const Stack & operator=(const Stack & rhs) { return *this; }
