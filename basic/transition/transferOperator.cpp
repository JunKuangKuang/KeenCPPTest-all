/*
 * Created by 君匡 on 2022/11/8.
 * https://www.clzly.xyz/2020/CPP/c07d3922/
 * 运算符优先级
 * */
#include <iostream>

#define endl '\n'
using namespace std;

int main() {
    int a, b, c, x, y;
    a = 1;
    b = 2;
    c = 0;
    cout << a++ - 1 << endl;//后缀自增运算符优先级大于加减运算符 
    cout << (a && b || !c) << endl;//a和b相与结果为真 
    cout << b / ++a << endl;//2除以3商0 
    x = ++a || ++b && ++c;//或运算被a=4短路 
    cout << a << b << c << x << endl;
    a = b = c = -1;
    y = ++a && ++b && ++c;//与运算被a=0短路 
    cout << a << b << c << y << endl;
    return 0;
}

