/*
 * 不论是修改还是删除，其实底层逻辑其实是一样的。
 * 第一步是读取原来的文件，一般是for循环逐行读取
 * 第二步是在循环的过程中匹配行号或者关键字，
 * 当匹配成功就对内容进行修改或者舍弃
 * 第三步，则是将读到内存的信息流写入文件，目标可以是新的文件，也可以是原来的文件
 * */
#include <fstream>
#include<string>
#include<iostream>

#define filepath "/Volumes/KeenMacPlus/Projects/C++项目/KeenCPPTest-all/STL/fstream/txt/"
using namespace std;

/*
 * 修改指定行号的数据为新的内容
 * 三个参数分别是文件名，行号，要修改的内容
 * 底层逻辑是把文件信息全存储到中间文件里，然后再把中间文件的内容覆盖源文件的内容
 *
 * 好处是即使出错了或者断电了，那么之前的数据仍然是保留在中间文件中的
 * 坏处是要读写量增大了，很耗费时间，适合大文件
 * */
void modiFile(string filename, int lineNum, string str) {
    ifstream file(filename);
    string line; // 临时变量，读取文件的一行内容
    int num = 0;// 统计行号
    ofstream outfile("test.txt", ios::out | ios::trunc);//用中间文件，记录整个文件的信息

    //将信息从源文件写到中间文件
    while (!file.eof()) {
        getline(file, line);
        if (num != lineNum - 1)
            outfile << line << endl;
        else
            outfile << str << endl;
        num++;
    }
    outfile.close();
    file.close();

    // 将信息从中间文件写入到源文件
    ofstream outfile1(filename, ios::out | ios::trunc);
    fstream file1("test.txt");
    while (!file1.eof()) {
        getline(file1, line);
        if (line != "") {
            outfile1 << line << endl;
        }
    }
    outfile1.close();
    file1.close();

    //最后删除中间文件
    // system("del test.txt");//Windows
    system("rm -f  test.txt");// mac和linux
}


/*
 * 修改指定行号的数据为新的内容
 * 三个参数分别是文件名，行号，要修改的内容
 * 底层逻辑是把文件信息全存储到字符串变量outStr里，然后再覆盖原先的内容
 *
 * 好处是不需要生成另一个临时文件来存储内容，适合小文件。
 * 缺点就是一旦在过程中出错了或者断电了，那么之前的数据就全没有了！
 * */
void modiFile2(string filename, int lineNum, char *content) {
    ifstream in(filename);
    string line; // 临时变量，读取文件的一行内容
    int num = 0;// 统计行号
    string outStr;// 记录整个文件的数据流

    while (getline(in, line)) {// 逐行读取，是没有换行符的！
        num++;
        if (lineNum != num) {
            outStr += line;
        } else {
            outStr += content;
        }
        outStr += '\n';
    }
    in.close();

    //新建这个文件的写入流对象，调用flush函数来清空文件流内的内容。
    ofstream out;
    out.open(filename);
    out.flush();
    out << outStr;
    out.close();
}

int main() {
    // modiFile(filepath"modifile.txt", 2, "这是新的第二行");
    modiFile2(filepath"modifile.txt", 2, "这也是新的第二行");
    cout << "over" << endl;
    return 0;
}