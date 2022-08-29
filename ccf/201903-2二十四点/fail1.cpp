#include<iostream>
#include <fstream>
#include<string>
#include <stack>
#include <sstream>

using namespace std;

string judge_4(string s) {
    stringstream ss;//方便类型转换
    double a, b, c, d;//四个数值
    char ch;//临时记录
    string temp = "";//临时记录
    string str = "";//进行一次计算后,还保留了三个数值和两个运算符
    ch = s[0] - '0';
    a = ch;
    ch = s[2] - '0';
    b = ch;
    ch = s[4] - '0';
    c = ch;
    ch = s[6] - '0';
    d = ch;
    if (s[1] == 'x' || s[1] == '/') {
        if (s[1] == 'x') {//进行运算
            a = a * b;
        } else {
            a = a / b;
        }
        ss << a;//类型转换
        temp = ss.str(); //完成类型转换
        str += temp;
        str += s.substr(3);
    } else if (s[3] == 'x' || s[3] == '/') {
        if (s[3] == 'x') {
            b = b * c;
        } else {
            b = b / c;
        }
        ss << b;//类型转换
        temp = ss.str(); //完成类型转换

        str += s.substr(0, 2);
        str += temp;
        str += s.substr(5);
    } else if (s[5] == 'x' || s[5] == '/') {
        if (s[5] == 'x') {
            c = c * d;
        } else {
            c = c / d;
        }
        ss << c;//类型转换
        temp = ss.str(); //完成类型转换

        str += s.substr(0, 4);
        str += temp;
    }
    if (str == "") {    //没有进行乘除运算
        if (s[1] == '+') {
            a = a + b;
        } else {
            a = a - b;
        }
        ss << a;//类型转换
        temp = ss.str(); //完成类型转换
        str += temp;
        str += s.substr(3);
    }
    return str;
}


int main() {
    ifstream fin("1.txt");
    if (!fin) {
        return -1;
    }
    int n;//一共多少组算式
    fin >> n;
    string *str = new string[n];

    for (int i = 0; i < n; i++) {
        fin >> str[i];
    }

    for (int i = 0; i < n; i++) {
        cout << judge_4(str[i]) << endl;
    }

    fin.close();
    return 0;
}