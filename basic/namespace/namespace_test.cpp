//
// Created by 君匡 on 2022/8/28.
// 测试命名空间的函数
// https://www.clzly.xyz/2020/CPP/7126d1ab/
#include <iostream>

using namespace std;

// 第一个命名空间
namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}
// 第二个命名空间
namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}

int main() {

    // 调用第一个命名空间中的函数
    first_space::func();

    // 调用第二个命名空间中的函数
    second_space::func();

    return 0;
}