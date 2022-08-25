#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * 声明了一个对象，初始是两个元素，容量为2
 * 当直接修改下标没有超过容量，会直接修改元素
 * 当直接修改下标查过了容量，会没有变化，因为容器内不存在超过容量的元素，被认为是无效操作。
 * */
void add1() {
    vector<int> demo{1, 2};
    demo[1] = 3;//{1,3}
    demo[10] = 3;//{1,3}
}

/*
 * insert能插入多个，慢但是实用
 * */
void add2() {
    vector<int> demo{1, 2};
    //在第一个元素后面插入3
    demo.insert(demo.begin() + 1, 3);//{1,3,2}

    //在末尾插入2个5
    demo.insert(demo.end(), 2, 5);//{1,3,2,5,5}

    //插入其他容器的部分序列
    set<int> setTemp{7, 8, 9};
    demo.insert(demo.end(), ++setTemp.begin(), --setTemp.end()); //{1,3,2,5,5,8}

    //插入初始化列表
    demo.insert(demo.end(), {10, 11}); //{1,3,2,5,5,7,8,9,10,11}

    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
}

/*
 * emplace，只能插入一个，但是快
 * */
void add3() {
    vector<int> demo{1, 2};

    demo.emplace(demo.begin(), 3);//{3,1,2}

    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
}

/*
 *在底层实现时，是会判断当前元素的个数是否等于容量大小，如果没有就直接插入，否则就要扩容了。
 * */
void add4() {
    vector<int> demo{1, 2};

    demo.push_back(3);//{3,1,2}

    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
}

/*
 * 直接for循环，用下标取元素即可
 * */
void search1() {
    vector<int> demo{1, 2};

    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
}

/*
 * 直接用迭代器，注意const_iterator还是iterator
 * */
void search2() {
    vector<int> demo{1, 2};

    // 如果参数为const vector<int> 需要用const_iterator
    // vector<int>::const_iterator iter=v.begin();
    for (vector<int>::iterator it = demo.begin(); it != demo.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << endl;
}

/*
 * 删除有两种方式，一个是直接清空，另一个是删除指定个数的元素
 * */
void del() {
    vector<int> demo{1, 2, 3, 4, 5};
    //清空
    demo.clear();//{}
    if (demo.empty()) {//判断Vector为空则返回true
        demo.insert(demo.end(), {6, 7, 8, 9, 10, 11});//{ 6, 7, 8, 9, 10, 11 }

        //删除第一个元素
        demo.erase(demo.begin());//{7, 8, 9, 10, 11 }

        //删除前三个
        demo.erase(demo.begin(), demo.begin() + 3); //{ 10, 11 }

        //删除最后一个
        demo.pop_back();//{10}
    }

    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
}

int main() {
    // add1();
    // add2();
    // add3();
    // add4();

    search2();
    del();
    return 0;
}