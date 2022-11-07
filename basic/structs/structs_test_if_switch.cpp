//结构语句测试If和Switch
//https://www.clzly.xyz/2020/CPP/434ca9bc/

#include <iostream>
#include<fstream>

using namespace std;

void coutIF() {
    int x = 100;
    if (x < 10) {
        cout << "1";
    } else if (x > 101) {
        cout << "2";
    } else {
        cout << "3";
    }
}

void coutSWITCH() {
    int x, a, b, c, d;
    a = b = c = d = 0;
    cin >> x;
    switch (x) {
        case 1:
            a++;
            break;
        default:
            d = 1;
        case 2:
            b++;
            break;
        case 3:
            c++;
            break;
    }
    cout << a << b << c << d << endl;
}

int main() {
    coutIF();
    coutSWITCH();
    return 0;
}
