#include <iostream>
#include <stack>

using namespace std;

int main() {
    //空对象
    stack<int> s;

    s.push(2);// 头入头出{2}
    s.push(3);// 头入头出{3 2}
    s.push(1);// 头入头出{1 3 2}
    s.push(4);// 头入头出{4 1 3 2}
    cout << s.size() << endl;//元素个数

    while (!s.empty()) { //若true,则队列中无元素
        int temp = s.top(); //获取队头元素
        cout << temp << " ";
        s.pop();//弹出队头元素
    }
    return 0;
}
