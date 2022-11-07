/*
 * https://www.clzly.xyz/2020/CPP/7173084f/
 * */
#include<iostream>
// #include <fstream>

using namespace std;

int main() {
    int n = 7, k = 3;
    // cin >> n >> k;
    // 生成数组，记录每个孩子本身的编号
    int *child = new int[n];
    for (int i = 0; i < n; i++) {
        child[i] = i + 1;
    }
    int num = n; // 记录剩下的总人数
    int count = 1;// 报数
    int index = 0;// 遍历孩子数组的下标
    while (num != 1) { // 直到最后只剩下一个人才结束
        if (child[index] != 0) {
            // 满足淘汰条件就将人数减一，数值置为零并继续报数
            if (count % k == 0 || count % 10 == k) {
                num--;
                cout <<"淘汰第" << child[index] << "名孩子,报数是" << count << "，还剩" << num <<"个人"<< endl;
                count++;
                child[index] = 0;
            } else {
                count++;
                index = (index + 1) % n;
                continue;
            }
        } else {
            index = (index + 1) % n;
        }
    }
    // 最后输出存活孩子的编号
    for (int i = 0; i < n; i++) {
        if (child[i] != 0) {
            cout << "最后活下来的是" << child[i];
        }
    }
    return 0;
}

