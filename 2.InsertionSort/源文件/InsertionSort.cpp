#include <iostream>
#include <vector>
using namespace std;
void insertSort(vector<int>& vec);
int main() {
    vector<int> vec;
    /*
    for (int i = 0; i < 8; i++) {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    */
    vec.push_back(56);
    vec.push_back(25);
    vec.push_back(37);
    vec.push_back(58);
    vec.push_back(95);
    vec.push_back(19);
    vec.push_back(73);
    vec.push_back(30);
    insertSort(vec);
    for (int k = 0; k < vec.size(); k++) {
        cout << vec[k] << " ";
    }
    return 0;
}
void insertSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];//��¼��λ�õ�ֵ�����λ��֮ǰ�����ֶ��Ѿ��������
        //��������֮������Ų��Ϊ�����ڳ��ռ� 
        while (i > 0 && key < vec[i - 1]) {
            //�������д���Ϊ���ݵĲ����ڳ��ռ�
            vec[i] = vec[i - 1];
            vec[i - 1] = key;
            //�±�ع鵽key�ϣ�������һ�ֵıȶ�
            i--;
        }
    }
}