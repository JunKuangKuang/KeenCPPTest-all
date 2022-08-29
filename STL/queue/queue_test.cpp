#include <iostream>
#include <queue>

using namespace std;

int main() {
    //空对象
    queue<int> q;

    q.push(2);// 头出{2}尾入
    q.push(3);// 头出{2 3}尾入
    q.push(1);// 头出{2 3 1}尾入
    q.push(4);// 头出{2 3 1 4}尾入
    cout << q.size() << endl;//元素个数

    cout << q.back() << endl;//特殊清空下获取队尾元素

    while (!q.empty()) { //若true,则队列中无元素
        int temp = q.front(); //获取队头元素
        cout << temp << " ";
        q.pop();//弹出队头元素
    }
    return 0;
}
