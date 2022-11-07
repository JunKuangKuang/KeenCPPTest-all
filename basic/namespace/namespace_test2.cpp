//
// Created by 君匡 on 2022/8/28.
// 测试命名空间的变量
//
#include <iostream>

#define endl "\n"
using namespace std;

double a;//1号

int main() {
    int a = 10;//2号
    {
        int a = 20;//3号
        double b;
        ::a = 20.5;//1号
        b = ::a + a;//1号 +3号
        cout << "a=" << a << " " << "b=" << b << endl;//输出3号
        cout << "::a=" << ::a << endl;//输出1号
    }
    cout << "a=" << a << endl;//输出2号
    cout << "::a=" << ::a << endl;//输出1号
    return 0;
}