#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

void init() {
    map<int, string> m1;//空对象
    //自带初值
    map<int, string> m2(
            {
                    {1, "A"},
                    {3, "C"},
                    {2, "B"}
            }
    );
    //默认按照索引less递增输出为
    // 1 A
    // 2 B
    // 3 C
    map<int, string, greater<int>> m3(
            {
                    {1, "A"},
                    {3, "C"},
                    {2, "B"}
            }
    );
    // 3 C
    // 2 B
    // 1 A
}

void add1() {
    map<int, string> m(
            {
                    {1, "A"},
                    {3, "C"},
                    {2, "B"}
            }
    );

    // 当索引是不存在的值，成功插入；当索引已经存在，则不进行操作
    //调用make_pair函数模板，好处是构造对象不需要参数，用起来更方便
    m.insert(pair<int, string>(24, "Z"));
    m.insert(map<int, string>::value_type(23, "Y"));
    m.insert(make_pair(1, "Z"));

    // 索引是原先没有的，直接插入；索引已经存在直接修改
    m[22] = "X";
    m[3] = "X";

    // 当索引是不存在的值，成功插入；当索引已经存在，则不进行操作
    m.emplace(pair<int, string>(21, "W"));
    m.emplace(pair<int, string>(1, "W"));

    map<int, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
}
//1 A
// 2 B
// 3 X
// 21 W
// 22 X
// 23 Y
// 24 Z

void update() {
    map<int, string> m(
            {
                    {1, "A"},
                    {3, "C"},
                    {2, "B"}
            }
    );
    // 索引是原先没有的，直接插入
    m[4] = "D";

    // 索引是已经存在的，就进行更新
    m[3] = "D";

    map<int, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
}

void search1() {
    map<int, string> m(
            {
                    {1, "A"},
                    {3, "C"},
                    {2, "B"}
            }
    );

    map<int, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
}

//1 A
// 2 B
// 3 C
void search2() {
    map<int, string> m(
            {
                    {1, "A"},
                    {3, "C"},
                    {5, "B"}
            }
    );
    cout << "遍历前元素的个数：" << m.size() << endl;
    for (int i = 0; i < m.size(); i++) {
        cout << i << ' ' << m[i] << endl;
    }
    cout << "遍历后元素的个数：" << m.size();

}
//遍历前元素的个数：3
// 0
// 1 A
// 2
// 3 C
// 4
// 5 B
// 遍历后元素的个数：6


/*
 * 删除有两种方式，
 * clear是直接清空
 * erase是删除指定迭代器范围内的数字
 * 也可以用来删除指定的单个元素
 * */
void del1() {
    map<int, string> m(
            {
                    {1, "A"},
                    {2, "B"},
                    {3, "C"}
            }
    );
    //清空
    m.clear();//{}
    if (m.empty()) {//判断Vector为空则返回true
        m.insert(pair<int, string>(4, "D"));
        m.insert(pair<int, string>(5, "E"));
        m.insert(pair<int, string>(6, "F"));

        //用迭代器删除单个元素，注意指针被删除后就失效了
        map<int, string>::iterator iter = m.begin();
        m.erase(iter);//所剩元素{5,E},{6,F}，此时的iter仍然是{4,D}
        cout << "错误的迭代器内容：" << iter->first << ' ' << iter->second << endl;

        //删除一个范围， 只保留最后一个
        m.erase(m.begin(), ++m.end()); //{6,F}

        //通过关键字索引的数据存在就删除，并返回1；如果关键字索引的数据不存在就不操作，并返回0
        m.erase(2);

    }
    map<int, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
}

/*
 * 遍历集合以删除指定条件的元素
 * */
void del2() {
    map<int, string> m(
            {
                    {1, "A"},
                    {2, "B"},
                    {3, "C"}
            }
    );
    map<int, string>::iterator iter;

    // 删除元素后，期望iter指针是继续指向{3,C}的，
    // 但是经过iter++后，竟然又到了上一个元素！
    // 很明显，删除元素后的迭代器变成了类似野指针的存在！
    // for (iter = m.begin(); iter != m.end(); iter++) {
    //     if (iter->first == 2 || iter->second == "B") {
    //         m.erase(iter);
    //     }
    //     cout << iter->first << ' ' << iter->second << endl;
    // }
    //结果是：
    // 1 A
    // 2 B
    // 1 A
    // 3 C

    // 正确做法应该是先复制出来一个临时迭代器
    // 接着将原来的迭代器后移一位指向正常的元素
    // 最后用临时迭代器删除指定元素！
    // 第二步和第三步不能反了，否则也会影响到原来正常的迭代器！
    for (iter = m.begin(); iter != m.end();) {
        if (iter->first == 2) {
            map<int, string>::iterator iterTemp = iter;
            ++iter;
            m.erase(iterTemp);
        } else {
            cout << iter->first << ' ' << iter->second << endl;
            ++iter;
        }
    }
    // 结果是
    // 1 A
    // 3 C
}


/*
 * 用count函数寻找元素，
 * */
void find1(map<int, string> map) {
    if (map.count(2) == 1) {
        cout << "元素2存在" << endl;
    }
    if (map.count(8) == 0) {
        cout << "元素8不存在";
    }
}

/*
 * 用find函数寻找元素，
 * */
void find2(map<int, string> map) {
    if (map.find(2) != map.end()) {
        cout << "元素2存在" << endl;
    }
    if (map.find(8) == map.end()) {
        cout << "元素8不存在";
    }
}

bool Special(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;//从小到大排序
}

void specialCompare() {
    // 初始map集合
    map<string, int> m;
    m["a"] = 2;
    m["b"] = 3;
    m["c"] = 1;

    // 转为vector集合
    vector<pair<string, int> > demo(m.begin(), m.end());

    for (auto it = demo.begin(); it != demo.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;

    // 排序后查看效果
    sort(demo.begin(), demo.end(), Special);

    for (auto it = demo.begin(); it != demo.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;

    // 转换为新的map集合，区别就是前后类型反了。
    map<int, string> m2;
    for (vector<pair<string, int> >::iterator it = demo.begin(); it != demo.end(); ++it) {
        m2[(*it).second] = (*it).first;
    }

    map<int, string>::iterator iter;
    for (iter = m2.begin(); iter != m2.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
}
//a 2
// b 3
// c 1
//
// c 1
// a 2
// b 3
//
// 1 c
// 2 a
// 3 b

int main() {

    // add1();
    // search1();
    // search2();
    // del2();

    // map<int, string> m(
    //         {
    //                 {1, "A"},
    //                 {2, "B"},
    //                 {3, "C"}
    //         }
    // );
    //
    // find1(m);
    // find2(m);
    specialCompare();
    return 0;
}

