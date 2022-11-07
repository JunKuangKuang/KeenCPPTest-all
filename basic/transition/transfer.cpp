/*
 * Created by 君匡 on 2022/11/7.
 * https://www.clzly.xyz/2020/CPP/c07d3922/
 * 类型转换
 * int类型四舍五入
 * int转char
 * char转int
 * int转string
 * string转int
 * bool转int
 * */
#include <iostream>
#include <string>

using namespace std;

void int_sishewuru() {
    double dou = 39.65;
    dou = (double) ((int) (dou * 10 + (dou < 0 ? -0.5 : 0.5))) / 10;
    cout << dou;
}

void int_to_char() {
    int i = 5;

    char c1 = i;                  // 5 '\x05'无法打印
    char c2 = i - 0;              // 5 '\x05'无法打印
    char c3 = i - '0';            // -43 '\xd5'打印乱码
    char c4 = i + '0';            // 53 '5'可打印
    cout << c4;
}

void char_to_int() {
    char c = '0';

    int i1 = c;                    // 48
    int i2 = c - 0;                // 48
    int i3 = c - '0';              // 0
    int i4 = c + '0';              // 96
    cout << i3;
}

void int_to_string() {
    int a = 100;
    string b = "";
    b = to_string(a);//string库，但需要c++11的支持
    cout<<b;
}

void string_to_int() {
    int a = 1;
    string b = "100abbc";
    a = atoi(b.c_str());//标准库，但是会忽略字符串中的字母，只保留数字
    cout<<a<<endl;
    a = stoi(b);//string库，但需要c++11的支持
    cout<<a;
}
void bool_to_int() {
    bool a = true, b = false;
    cout << "a=" << a << " , b=" << b << endl;
    cout << "a=" << boolalpha << a << " , b=" << b << endl;
}
/*
 * 结果为：
 * a=1 , b=0
 * a=true , b=false
 * */


int main() {
    // int_sishewuru();
    // int_to_char();
    // char_to_int();
    // string_to_int();
    bool_to_int();

    return 0;
};