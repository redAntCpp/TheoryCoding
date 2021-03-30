/*
 *这个文件保存的是Queue.h的私有部分
 *我们这个时候用顺序队列。也就是用数组来实现我们的队列
 *这样的队列我们称为顺序队列
 */
private:
    /*队列的链式结构*/
    struct Cell{
        ValueType data;
        Cell *link;
    };
    /*实例化变量*/
    Cell *head; //头指针
    Cell *tail; //尾指针
    int count; //记录队列元素的总数