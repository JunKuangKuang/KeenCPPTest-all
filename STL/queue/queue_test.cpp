#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;//空对象
    q.push(2);//尾部插入
    q.push(3);
    q.push(1);
    q.push(4);
    cout << q.size() << endl;//元素个数
    if (!q.empty()) { //若true,则队列中无元素
        int temp = q.front(); //获取队头元素
        cout << temp << endl;
        temp = q.back(); //获取队尾元素
        cout << temp << endl;
        q.pop();//弹出队头元素
    }
    return 0;
}
