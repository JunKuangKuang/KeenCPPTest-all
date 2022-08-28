//
// Created by keen on 2022/8/28.
//
/**
 * 宏定义测试文件
 * */
#include<iostream>

#define endl '\n'
#define SR1(x, y) x+y

using namespace std;

void sum1() {
    int a = 5, b = 4;
    a += 2 * SR1(a, b);
    cout << "sum1=" << a << endl;//结果是19
}

#define SR2(x, y) ((x)+(y))

void sum2() {
    int a = 5, b = 4;
    a += 2 * SR2(a, b);
    cout << "sum2=" << a << endl;//结果是23
}

#define fun1(a) a

void f1() {
    cout << "f1=" << fun1(12 + 3)<< endl;//结果是数字15
}

#define fun2(a) "a"

void f2() {
    cout << "f2=" << fun2(12 + 3)<< endl;//结果是字符串a
}


int main() {
    sum1();
    sum2();
    f1();
    f2();
    return 0;
}