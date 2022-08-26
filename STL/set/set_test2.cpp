/*
 * 展示自定义类型如何类内重载运算符
 * */

#include <iostream>
#include <set>

using namespace std;

// 自定义结构体需要类内重载
struct Info {
    string name;
    float score;

    Info() {
        name = "a";
        score = 60;
    }

    Info(string sname, float fscore) {
        name = sname;
        score = fscore;
    }

    // 类内重载
    bool operator<(const Info &a) const {
        /*名字递减；若名字相同，则分数递减*/
        if (a.name < name)
            return true;
        else if (a.name == name) {
            return a.score < score;
        } else
            return false;
    }
};

void InfoCompare() {
    pair<set<Info>::iterator, bool> result;//获取插入的结果
    set<Info> s;
    // 插入默认对象和指定对象
    s.insert(Info());
    s.insert(Info("a", 53));
    s.insert(Info("keen", 68));
    result = s.insert(Info("keen", 60));

    // 遍历查看内容
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        cout << iter->name << " " << iter->score << endl;
    }
    cout << "插入元素的信息：" << result.first->name << " " << result.first->score << endl;
    cout << "插入是否成功" << boolalpha << result.second << endl;

    // 再次插入相同元素
    result = s.insert(Info("keen", 60));
    cout << "插入元素的信息：" << result.first->name << " " << result.first->score << endl;
    cout << "插入是否成功" << boolalpha << result.second << endl;
}
/*
keen 68
keen 60
a 60
a 53
插入元素的信息：keen 60
插入是否成功true
插入元素的信息：keen 60
插入是否成功false
 */

// 基础类型，变动规则为递增或者递减
void BasicCompare() {
    set<int, less<int> > s2{6, 5, 7, 8};//小数靠前。递增,输出为{5,6,7,8}
    set<int, greater<int> > s3{6, 5, 7, 8};//大数靠前。递减,输出为{8,7,6,5}

    // 遍历查看内容
    set<int> s = s2;
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
}

// 基础类型，但是有特殊的比较规则
// 此处以递增递减为例
// 当然也可以指定为其他自定义类型
struct Special {
    bool operator()(const int &a, const int &b) {
        // return a > b;//等价greater<int>
        return a < b;//等价less<int>
    }
};

// 基础类型需要类外重载
void SpecialCompare() {
    set<int, Special> s2;

    s2.emplace(3);
    s2.emplace(2);
    s2.emplace(1);
    s2.emplace(4);

    // 遍历查看内容
    set<int, Special> s = s2;
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
}

/*1 2 3 4 */

int main() {
    // InfoCompare();
    // BasicCompare();
    SpecialCompare();
    return 0;
}
