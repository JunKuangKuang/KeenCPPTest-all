//
// Created by keen on 2022/8/23.
//
#include <iostream>
#include <time.h>

using namespace std;

int main(void) {
    time_t nowtime;
    nowtime = time(NULL); //获取日历时间
    cout << nowtime << endl;  //输出nowtime
    struct tm *local;
    local = localtime(&nowtime);  //获取当前系统时间
    cout << asctime(local);
    cout << ctime(&nowtime);

    return 0;
}


/*输出结果:
1268575163
Sun Mar
14 13:59:23 2010
Sun Mar
14 21:59:23 2010*/


/*
char buf[80];
strftime(buf,
80, "格式化输出：%Y-%m-%d %H:%M:%S", local);
cout << buf <<
endl;*/
