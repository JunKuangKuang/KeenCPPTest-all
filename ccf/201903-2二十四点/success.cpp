#include <iostream>
#include <string>
#include <stack>

using namespace std;

//计算字符串str对应的结果
int jisuan(string str) {
    stack<int> sint;
    for (int i = 0; i < 7; i++) {
        if (str[i] == '+') {
        } else if (str[i] == '-') {
            sint.push('0' - str[i + 1]);
            i = i + 1;
            continue;
        } else if (str[i] == 'x') {
            int t = sint.top() * (str[i + 1] - '0');
            sint.pop();
            sint.push(t);
            i = i + 1;
            continue;
        } else if (str[i] == '/') {
            int t = sint.top() / (str[i + 1] - '0');
            sint.pop();
            sint.push(t);
            i = i + 1;
            continue;
        } else {
            sint.push(str[i] - '0');
        }
    }

    int sum = 0;
    while (sint.size() > 0) {
        sum += sint.top();
        sint.pop();
    }
    return sum;
}

//输入数据的主函数
int main() {
    int n;
    cin >> n;
    string str[100];
    for (int i = 0; i < n; i++) {
        char s[6];
        cin >> s;
        str[i] = s;
    }
    for (int i = 0; i < n; i++) {
        int ans = jisuan(str[i]);
        if (ans == 24) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}