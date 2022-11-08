/*
 * Created by 君匡 on 2022/11/8.
 * https://www.clzly.xyz/2020/CPP/ccba786f/
 * 字符串相关的方法测试样例
 * 构造、尾缀添加、内部插入、比较、删除、取代、截取、交换、转换数组
 * */
#include<string>
#include <iostream>
#include <cstring>

using namespace std;

void stringTestConstruct() {
    string str = string("12345 \0 54321", 13);//不等价于str="12345 \0 54321";
    cout << str << endl;

    string str1 = "12345 \0 54321";
    cout << str1;
}

void stringTestAppend() {
    string str = "Hello";
    str.append(3, '!');//等价于str+="!!!" ;
    cout << str;
}


void stringTestAppend2() {
    string str = "abc";
    str.append("\0 def", 5);//等价于 str =string("abc\0 def", 8);
    cout << str;
}

void stringTestCompare() {
    string s1 = "abandon";
    string s2 = "about";
    int b = s1.compare(s2);//直接比较，s1小于s2，故返回-1

    int c = s1.compare(2, 4, s2);//s1下标为2的字符a开始的4个字符ando和s2进行比较。ando大于s2故返回1
    cout << c << endl;

    int d = s1.compare(2, 4, s2, 1, 3);
    cout << d << endl;//s1下标为2的字符a开始的4个字符ando和s2下标为1的字符b开始的3个字符bou比较。前者小，故返回-1。

    string s3 = "abc";
    string s4 = "abc";
    int e = s3.compare(s4);//相等返回0
    cout << e << endl;
}

void stringTestErase() {
    string s("1234567890123456789012345");//总共25个字符
    cout << s << endl;
    cout << s.erase(10, 6) << endl;//从下标第10的字符开始删除，一共删除6个。
    cout << s.erase(10) << endl;//删除下标为10的字符及之后的 ==保留下标小于10的字符
    cout << s.erase();//清空字符串
}

void stringTestInsert() {
    string str = "abc";
    str.insert(1, "123");
    /*在下标为1的位置，插入字符串123全部*/
    cout << str << endl;

    str = "abc";
    str.insert(1, "123", 1, 1);
    /*在下标为1的位置，插入字符串123的一部分，并且从下标1开始，长度为1的一段*/
    cout << str << endl;

    str = "abc";
    str.insert(1, "123", 2);
    /*在下标为1的位置，插入字符串123的一部分，并且从下标0开始，长度为2的一段*/
    cout << str << endl;

    str = "abc";
    str.insert(1, 2, 'z');
    /*在下标为1的位置，插入2个字符z*/
    cout << str;
}

void stringTestLength() {
    //其实后面都是返回的同一个字段_M_string_length。
    string s("1234567890123456789012345");//总共25个字符
    cout << s.size() << endl;//输出25
    cout << s.length() << endl;//输出25
}

void stringTestReplace() {
    string str = "1234567890";
    str.replace(0, 9, "ABC");
    /*把下标从0开始、长度为2的一段字符串，替换为ABC*/
    cout << str << endl;

    str = "1234567890";
    str.replace(str.find('8'), 3, "ABC");
    /*把从字符8开始、长度为2的一段字符串，替换为ABC*/
    cout << str;
}

void stringTestSubstr() {
    string s("123456789012345678901234567890");
    cout << s << endl;
    printf("%30s\n", s.substr(21).c_str());
    cout << s.erase(21) << endl;
}

void stringTestSwap() {
    string first("This comes first");
    string second("And this is second");
    first.swap(second);
    cout << first << endl;
    cout << second << endl;
}

void stringTestC_str() {
    //数组
    char c[20];
    string s = "1234";
    strcpy(c, s.c_str());//注意strcpy函数是在cstring头文件中的
    cout << c;

    //指针
    string str = "hello";
    const char *p1 = str.c_str();//加const
    char *p2 = (char *) str.c_str();//或者是强制转换
}

void stringTestData() {
    //数组
    char c[20];
    string s = "1234";
    strcpy(c, s.c_str());//注意strcpy函数是在cstring头文件中的


    //指针
    string str = "hello";
    const char *p1 = str.c_str();//加const
    char *p2 = (char *) str.data();//或者是强制转换
    cout << c;
}

void stringTestCopy() {
    string str = "hmmm";
    char p[10];
    str.copy(p, 3, 0);
    /*把从0开始、长度为3的字符串，复制到字符数组p之中*/
    p[3] = '\0';//注意手动加结束符！！！
    cout << p;
}

int main() {
    // stringTestAppend();
    // stringTestAppend2();
    // stringTestConstruct();
    // stringTestCompare();
    // stringTestErase();
    // stringTestInsert();
    // stringTestReplace();
    // stringTestSubstr();
    // stringTestSwap();
    // stringTestC_str();
    // stringTestData();
    stringTestCopy();
    return 0;
}