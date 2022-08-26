/*
 * 展示自定义类型如何类外重载运算符
 * */

#include <iostream>
#include <set>

using namespace std;

/*Student结构体*/
struct Student {
    string name;
    int age;
    string sex;

    Student() {}

    Student(const string &name, int age, const string &sex) : name(name), age(age), sex(sex) {}
};

/*
 * 为Student指定排序准则
 * 先比较名字；若名字相同,则比较年龄。小的返回true
 * 如果想要部分参数匹配，可以用正则表达式来规定
 * */
class StudentCompare {
public:
    bool operator()(const Student &a, const Student &b) const {
        if (a.name < b.name)
            return true;
        else if (a.name == b.name) {
            if (a.age < b.age)
                return true;
            else
                return false;
        } else
            return false;
    }
};

int main() {
    set<Student, StudentCompare> stuSet;

    stuSet.insert(Student("张三", 13, "male"));
    stuSet.insert(Student("李四", 23, "female"));

    /*构造一个用来查找的临时对象,可以看到,即使stuTemp与stu1实际上并不是同一个对象,
     *但当在set中查找时,仍能够查找到集合中的元素成功。
     *这是因为已定义的StudentCompare的缘故。
     */
    Student stuTemp;
    stuTemp.name = "张三";
    stuTemp.age = 13;

    set<Student, StudentCompare>::iterator iter;
    iter = stuSet.find(stuTemp);
    if (iter != stuSet.end()) {
        cout << (*iter).name << " " << (*iter).age << " " << (*iter).sex << endl;
    } else {
        cout << "Cannot fine the student!" << endl;
    }
    return 0;
}