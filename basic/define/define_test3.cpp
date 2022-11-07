/**
 * Created by 君匡 on 2022/8/28.
 * 宏定义测试文件3
 * */
#include<iostream>

using namespace std;

#define endl '\n'
#define STR(s)     #s
#define CONS(a, b)  int(a##e##b)

int main() {
    cout << STR(vck)<< endl;       // 输出字符串"vck"
    cout << CONS(2, 3);  // 2e3 输出:2000
    return 0;
}
#undef CONS
#undef STR