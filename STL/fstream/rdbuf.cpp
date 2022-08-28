/*
 * 展示重定向，更多的
 * */

#include<fstream>
#include <ostream>
#include <iostream>
#include<string>

#define filepath "/Volumes/KeenMacPlus/Projects/C++项目/KeenCPPTest-all/STL/fstream/txt/"
using namespace std;

void cinAndCout() {
    cout << "请输入信息：" << endl;
    string a;
    cin >> a;
    cout << "你输出的信息为： " << a;
}

int main() {
    // cinAndCout();

    ifstream fin(filepath"rdbuf.txt");
    ofstream fout(filepath"out.txt");
    if (!fin || !fout) {
        cout << "打开文件出错" << endl;
        return 0;
    }

    // 下面四行是用 rdbuf()  重新定向
    streambuf *cinbackup = NULL;
    streambuf *coutbackup = NULL;
    coutbackup = cout.rdbuf(fout.rdbuf());
    cinbackup = cin.rdbuf(fin.rdbuf()); // 用 rdbuf()  重新定向

    // 原先这个对象是输出到控制台，限制是输出到文件out.txt
    cout << "Hello world" << endl;

    string line;
    while (cin) {
        cin >> line;// 从 rdbuf.txt 文件读入
        if (cin)
            cout << line << endl;// 写入 out
    }
    fout.close();
    fin.close();


    //恢复标准输入输出
    // 如果不恢复，即使关闭了文件流，仍然无法输出到控制台！
    cin.rdbuf(cinbackup); // 恢复键盘输入
    cout.rdbuf(coutbackup); // 恢复控制台输出

    cout << "完成操作！";


    return 0;
}