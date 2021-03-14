
private:

    /* 实例化参数 */

    char* array; /* 字符型的动态数组 */

    int capacity; /* 为数组分配空间 */

    int count; /* 当前被压入的栈中的元素个数 */

    /* 私有函数声明 */

    void expandCapacity();
