/*
 * Created by 君匡 on 2022/11/8.
 * ccba786f
 * 字符串迭代器的查询
 * */
#include<string>
#include <iostream>
#include <cstring>

using namespace std;

void stringIteratorTestFind() {
    string s("qwe123qwee123qweqwe1");
    string flag = "123";
    string::size_type position = 0;
    int i = 1;
    while ((position = s.find(flag, position)) != string::npos) {
        cout << "position  " << i << " : " << position << endl;
        position++;
        i++;
    }
}
void stringIteratorTestFind_first_of () {
    string s("qwe123qwee123qweqwe1");
    string flag="123";
    string::size_type position=0;
    int i=1;
    while((position=s.find_first_of(flag,position))!=string::npos) {
        cout<<"第"<<i<<"次匹配 : "<<position<<endl;
        position++;
        i++;
    }
}
int main() {
    // stringIteratorTestFind();
    stringIteratorTestFind_first_of();

    return 0;
}