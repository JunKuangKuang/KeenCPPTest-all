//
// Created by 君匡 on 2022/8/28.
// 输出bool类型的字符
//
#include <iostream>
using namespace std;
int main(){
    bool a=true,b=false;
    cout<<"a="<<a<<" , b="<<b<<endl;
    cout<<"a="<<boolalpha<<a<<" , b="<<b<<endl;
    return 0;
}
/*
 * 结果为：
 * a=1 , b=0
 * a=true , b=false
 * */