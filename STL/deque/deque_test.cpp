/*
 * 这个文件是展示如何运行双向队列
 * */
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    // 定义
    deque<int> deque1{1, 2, 3, 4, 5};

    //增加函数
    deque1.push_front(3);//头部增加一个元素X
    deque1.push_back(2);//尾部增加一个元素x

    //查询
    if (!deque1.empty()) { //若true,则deque中无元素
        //顺序遍历，跟数组一样可以直接取值！
        for (int i = 0; i < deque1.size(); i++)
            cout << deque1[i] << " ";
        cout << endl;

        //正向迭代器遍历
        for (deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); iter++)
            cout << *iter << " ";
        cout << endl;

        //反向迭代器遍历
        for (deque<int>::reverse_iterator iter = deque1.rbegin(); iter != deque1.rend(); iter++)
            cout << *iter << " ";
        cout << endl;
    }

    // 删除
    /*deque1.pop_front();//去头
    deque1.pop_back();//去尾
    deque1.clear();//清空*/
    // 迭代器排序
    sort(deque1.begin(), deque1.end());

    if (!deque1.empty()) { //若true,则deque中无元素
        //顺序遍历
        for (int i = 0; i < deque1.size(); i++)
            cout << deque1[i] << " ";
        cout << endl;
    }

    cout << endl;

    return 0;
}