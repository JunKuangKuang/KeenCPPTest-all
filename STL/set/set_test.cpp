/*
 * 记录简单的增删改查
 * */

#include<iostream>
#include<set>
#include <vector>

using namespace std;

void init() {

    set<int> s1;//空对象
    set<int> s2{3, 4, 2, 1};//列表清单,默认less递增 ,输出为{1,2,3,4}
    set<int, greater<int> > s3{6, 5, 7, 8};//列表清单 ,输出为{8.7.6.5}
}


/*
 * insert能插入多个，慢但是实用
 * */
void add1() {
    set<int> demo{1, 2};
    //在第一个元素后面插入3
    demo.insert(demo.begin()++, 3);//{1,2,3},结果遵循递增规则

    //直接插入元素,也是按照规则排列
    demo.insert(-1);//{-1,1,2,3}
    //C++11之后,可以用emplace_hint或者emplace替代

    //插入其他容器的部分序列
    vector<int> test{7, 8, 9};
    demo.insert(++test.begin(), --test.end()); //{-1,1,2,3,8}

    //插入初始化列表
    demo.insert({10, 11}); //{-1,1,2,3,8,10,11}

    set<int> s = demo;
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
}


/*
 * emplace，只能插入一个
 * 而且如果元素已经存在，是不会再次插入的
 * */
void add2() {
    set<int> demo{1, 2};

    demo.emplace(4);//{1,2,4}

    demo.emplace(4);//还是{1,2,4}

    set<int> s = demo;
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
}


/*
 * 直接用迭代器，注意const_iterator还是iterator
 * */
void search() {
    set<int> demo{1, 2};

    // 如果参数为const vector<int> 需要用const_iterator
    // vector<int>::const_iterator iter=v.begin();

    set<int> s = demo;
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
}


/*
 * 删除有两种方式，
 * clear是直接清空
 * erase是删除指定迭代器范围内的数字
 * 也可以用来删除指定的单个元素
 * */
void del() {
    set<int> demo{1, 2, 3, 4, 5};
    //清空
    demo.clear();//{}
    if (demo.empty()) {//判断Vector为空则返回true
        demo.insert({6, 7, 8, 9, 10, 11});//{ 6, 7, 8, 9, 10, 11 }

        //删除第一个元素
        demo.erase(demo.begin());//{7, 8, 9, 10, 11 }
        // 删除指定元素
        demo.erase(11);
        //删除前三个
        demo.erase(demo.begin(), next(demo.begin(), 3)); //{ 10, 11 }
        // 只保留最后一个
        demo.erase(demo.begin(), ++demo.end()); //{11}
    }

    set<int> s = demo;
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
}

int main() {
    // add1();
    // add2();
    // add3();
    // add4();

    // search();

    del();
    return 0;
}

