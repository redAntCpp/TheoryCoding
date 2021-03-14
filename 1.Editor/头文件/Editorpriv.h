private:
    /* 实例化变量 */
    char* array; /* 动态字符数组 */
    int capacity; /* 分配数组空间 */
    int length; /* buffer中的字符数 */
    int cursor; /* 字符之后的游标 */
    /* 使得复制buffer合法 */
    //Editor(const Editor& value) { }
    //const Editor& operator=(const Editor& rhs) { return *this; }
    /* 私有方法声明 */
    void expandCapacity();