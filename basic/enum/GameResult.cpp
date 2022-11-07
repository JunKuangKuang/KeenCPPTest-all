/*
 * Created by 君匡 on 2022/11/7.
 * https://www.clzly.xyz/2020/CPP/c07d3922/
 * 枚举类型样例
 * */
#include <iostream>

using namespace std;
enum GameResult {
    WIN,LOSE,TIE,CANCEL
}; //下标依次为0,1,2,3
int main() {
    GameResult result;//声明变量时,可以不写关键字enum
    enum GameResult omit = CANCEL;//也可以在类型名前写enum

    for (int count = WIN; count <= CANCEL; count++) {//枚举类型隐含类型转换为整型
        result = GameResult(count);//整型显式类型转换为枚举类型
        if (result == omit)
            cout << "The game was cancelled" << endl;
        else {
            cout << "The game was played ";
            if (result == WIN)
                cout << "and we won ! ";
            if (result == LOSE)
                cout << "and we lost . ";
            cout << endl;
        }
    }
    return 0;
}