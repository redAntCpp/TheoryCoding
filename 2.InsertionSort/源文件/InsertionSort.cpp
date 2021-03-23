#include <iostream>
#include <vector>
#include <string>
using namespace std;
void insertSort(vector<int>& vec);
//新增函数，输出示例
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
//插入排序
void insertSort(vector<int>& vec) {
    cout << "开始排序：" << endl;
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];//记录该位置的值，这个位置之前的数字都已经被排序好
        cout << "第" + to_string(i) + "轮：" + outNum(vec) + " 记录值为："+ to_string(key) << endl;
        //满足条件之后，往后挪动为插入腾出空间 
        while (i > 0 && key < vec[i - 1]) {
            //下面两行代码为数据的插入腾出空间
            vec[i] = vec[i - 1];
            vec[i - 1] = key;
            //下标回归到key上，进行下一轮的比对
            i--;
        }
    }
    cout << "排序完毕：" << endl;
}
//以字符串形式输出
string outNum(vector<int> vec) {
    string output;
    for (int k = 0; k < vec.size(); k++) {
        //cout << vec[k] << " ";
        output = output + to_string(vec[k]) + " ";
    }
    return output;
}