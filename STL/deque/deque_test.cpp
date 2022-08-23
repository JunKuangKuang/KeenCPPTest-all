/*
 * 这个文件是展示如何运行双向队列
 * */
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> deque1{1, 2, 3, 4, 5};
    //增加函数
    deque1.push_front(3);//头部增加一个元素X
    deque1.push_back(2);//尾部增加一个元素x
    if (!deque1.empty()) { //若true,则deque中无元素
        //顺序遍历
        for (int i = 0; i < deque1.size(); i++)
            cout << deque1[i] << " ";

        cout << endl;
    }
    //	deque1.pop_front();//去头
    //	deque1.pop_back();//去尾
    //	deque1.clear();//清空
    ////	cout << num << endl;
    sort(deque1.begin(), deque1.end());
    if (!deque1.empty()) { //若true,则deque中无元素
        //顺序遍历
        for (int i = 0; i < deque1.size(); i++)
            cout << deque1[i] << " ";
        cout << endl;
    }

    cout << endl;
    ////删除函数
    //	deque1.pop_front(): 删除双端队列中最前一个元素
    //		deque1.pop_back(): 删除双端队列中最后一个元素
    //		deque1.clear(): 清空双端队列中元素
    //
    ////判断函数
    //		deque1.empty() : 向量是否为空，若true, 则向量中无元素
    //
    ////大小函数
    //		deque1.size(): 返回向量中元素的个数
    //	cout << deque1[0] << deque1[1];
    return 0;
}