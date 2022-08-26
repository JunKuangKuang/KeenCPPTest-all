/*
 * 记录查找函数的使用
 * */

#include<iostream>
#include<set>
#include <vector>

using namespace std;

/*
 * 用count函数寻找元素，
 * */
void find1(set<int> s ){
    if (s.count(4) == 1) {
        cout << "元素4存在"<<endl;
    }
    if (s.count(8) == 0) {
        cout << "元素8不存在";
    }
}
/*
 * 用find函数寻找元素，
 * */
void find2(set<int> s ){

    if (s.find(4)!= s.end() ) {
        cout << "元素4存在"<<endl;
    }else{
        cout << "元素4不存在";
    }
    if (s.find(8)!= s.end() ) {
        cout << "元素8存在"<<endl;
    }else{
        cout << "元素8不存在";
    }
}

int main() {
    // add1();
    set<int> demo{1,2,3,4};
    find1(demo);
    find2(demo);
    return 0;
}

