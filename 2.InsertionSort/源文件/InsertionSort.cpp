#include <iostream>
#include <vector>
#include <string>
using namespace std;
void insertSort(vector<int>& vec);
//�������������ʾ��
string outNum(vector<int> vec);
int main() {
    vector<int> vec;
    vec.push_back(56);
    vec.push_back(25);
    vec.push_back(37);
    vec.push_back(58);
    vec.push_back(95);
    vec.push_back(19);
    vec.push_back(73);
    vec.push_back(30);
    insertSort(vec);
    return 0;
}
//��������
void insertSort(vector<int>& vec) {
    cout << "��ʼ����" << endl;
    cout << "��ʼΪ��" << outNum(vec) << endl;
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];//��¼��λ�õ�ֵ�����λ��֮ǰ�����ֶ��Ѿ��������     
        //��������֮������Ų��Ϊ�����ڳ��ռ� 
        cout << "��" + to_string(i) + "��: ";
        int k = i; //������ʱ�����������±���㣬��֤����Ӱ��i������ִ�
        while (k > 0 && key < vec[k - 1]) {
            //�������д���Ϊ���ݵĲ����ڳ��ռ�
            vec[k] = vec[k - 1];
            vec[k - 1] = key;
            //�±�ع鵽key�ϣ�������һ�ֵıȶ�
            k--;
        }
        cout << outNum(vec)  + " key��ֵΪ��" + to_string(key)<< endl;
    }
    cout << "������ϣ�" << endl;
}
//���ַ�����ʽ���
string outNum(vector<int> vec) {
    string output;
    for (int k = 0; k < vec.size(); k++) {
        //cout << vec[k] << " ";
        output = output + to_string(vec[k]) + " ";
    }
    return output;
}