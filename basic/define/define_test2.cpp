/**
 * Created by 君匡 on 2022/8/28.
 * 宏定义，可以分行
 * */
#include <iostream>

using namespace std;

// #define doit(m, n) for(int i=0;i<(n);++i){m+=i;}
#define doit(m, n) for(int i=0;i<(n);++i)\
{\
m+=i;\
}

int main() {
    int a = 5, b = 4;
    doit(a, b);
    cout << a;// 结果为11
    return 0;
}