//
// Created by keen on 2022/8/28.
//
#include <fstream>
#include<iostream>
#include<string>

#define filepath "/Volumes/KeenMacPlus/Projects/C++项目/KeenCPPTest-all/STL/fstream/txt/"
using namespace std;



/*
 * 读取文件，并统计有多少行
 * */
void read() {
    // ifstream fin("input.txt");//等价于
    // fstream fin("input.txt", ios::in);//等价于
    fstream fin;    fin.open(filepath"input.txt", ios::in);

    // 一定要判断是否打开成功！
    if (!fin) {
        cout << "打开文件出错" << endl;
        return;
    }

    char c;
    int lineNum = 0;// 统计行数
    while (fin.get(c))// 逐字符读入
    {
        if (c == '\n')
            lineNum++;
    }
    cout << lineNum + 1 << endl;
    fin.close();
}

/*
 * 向文件中写入字符串，注意模式的不同
 * */
void write() {
    fstream fin;
    // fin.open(filepath"input.txt"); // 覆盖模式
    fin.open(filepath"input.txt", ios::app); // 末尾追加模式
    if (!fin) {
        cout << "打开文件出错" << endl;
        return ;
    }
    fin << "这是新加的一行" << endl;
    fin.close();
}

int main() {
    // write()
    read();
    return 0;
}