/*
 * Created by 君匡 on 2022/11/8.
 * https://www.clzly.xyz/2020/CPP/c07d3922/
 * 字符串和字符数组相互转化
 * */
#include <iostream>

using namespace ::std;

void stringt_to_char_data() {
    string str = "hello";
    const char *p1 = str.data();//不可修改
    cout << p1 << endl;

    char *p2 = (char *) str.data();//可修改
    p2[1]++;
    cout << p2;
}

void stringt_to_char_c_str() {
    string str = "world";
    const char *p1 = str.c_str();//不可修改
    cout << p1 << endl;

    char *p2 = (char *) str.c_str();//可修改
    p2[1]++;
    cout << p2;
}

void stringt_to_char_copy() {
    string str = "hmmm";
    char p[10];
    str.copy(p, 3, 0);//这里3代表复制几个字符，0代表复制的位置，
    p[3] = '\0';//注意手动加结束符！！！
    cout << p;
}

void char_to_string() {
    string s;
    char *p = "hello world";
    s = p;
    cout << s;
}

int main() {
    // stringt_to_char_data();
    // stringt_to_char_c_str();
    // stringt_to_char_copy();
    char_to_string();
    // bool_to_int();

    return 0;

};
