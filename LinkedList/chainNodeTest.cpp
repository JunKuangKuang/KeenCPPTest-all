//
// Created by keen on 2022/8/28.
//

#include "../utils/chain/chainNode.h"
#include <iostream>

/*
 * 统计链表中元素值为X的结点个数
 * */
int countX(const chainNode<int> *root, int X) {
    int num = 0;// 统计次数
    const chainNode<int> *temp=root;
    while (temp) {
        if (temp->data == X)
            num++;
        temp = temp->next;
    }
    return num;
}

int main() {
    chainNode<int> root;
    root.data = 1;
    root.next = new chainNode<int>(1);
    root.next->next = new chainNode<int>;
    // {1,1,0}共三个结点
    std::cout << countX(&root, 1);
    std::cout << root.data;
    return 0;
}
