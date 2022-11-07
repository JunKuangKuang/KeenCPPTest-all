/*
 * Created by 君匡 on 2022/11/7.
 * https://www.clzly.xyz/2020/CPP/c07d3922/
 *
 * printf 进制转换
 * 十进制转十六进制
 * 十进制转八进制
 * */
#include <iostream>

#define endl "\n"
using namespace std;

int main() {
    int PrintVal = 9;
    /*按整型输出,默认右对齐*/
    printf("%d\n", PrintVal);
    /*按整型输出,补齐4位的宽度,补齐位为空格,默认右对齐*/
    printf("%4d\n", PrintVal);
    /*按整形输出,补齐4位的宽度,补齐位为0,默认右对齐*/
    printf("%04d\n", PrintVal);

    /*按16进制输出,默认右对齐*/
    printf("%x\n", PrintVal);
    /*按16进制输出,补齐4位的宽度,补齐位为空格,默认右对齐*/
    printf("%4x\n", PrintVal);
    /*按照16进制输出,补齐4位的宽度,补齐位为0,默认右对齐*/
    printf("%04x\n", PrintVal);

    /*按8进制输出,默认右对齐*/
    printf("%o\n", PrintVal);
    /*按8进制输出,补齐4位的宽度,补齐位为空格,默认右对齐*/
    printf("%4o\n", PrintVal);
    /*按照8进制输出,补齐4位的宽度,补齐位为0,默认右对齐*/
    printf("%04o\n", PrintVal);
    return 0;
}
