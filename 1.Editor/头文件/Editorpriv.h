private:
    /* ʵ�������� */
    char* array; /* ��̬�ַ����� */
    int capacity; /* ��������ռ� */
    int length; /* buffer�е��ַ��� */
    int cursor; /* �ַ�֮����α� */
    /* ʹ�ø���buffer�Ϸ� */
    //Editor(const Editor& value) { }
    //const Editor& operator=(const Editor& rhs) { return *this; }
    /* ˽�з������� */
    void expandCapacity();