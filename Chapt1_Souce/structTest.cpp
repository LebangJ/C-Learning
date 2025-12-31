#include <iostream>
#include <string>
using namespace std;

// 先定义结构体
struct Student {
    string name;
    int age;
    float score;
};

int main() {
    // 方式1：先定义结构体，再单独创建变量（最常用，代码清晰）
    Student s1;

    // 方式2：定义结构体的同时，直接创建变量
    struct Teacher {
        string t_name;
        int t_id;
    } t1;  // t1 是 Teacher 类型的变量

    // 方式3：创建变量时直接初始化（C++11及以上支持，简洁高效）
    Student s2 = {"张三", 18, 95.5f};
    // 访问并输出成员值
    cout << "姓名：" << s2.name << endl;
    cout << "年龄：" << s2.age << endl;
    cout << "成绩：" << s2.score << endl;

     // 定义结构体数组：存储3个学生信息
    Student stuArr[3] = {
        {"张三", 18, 95.5f},
        {"李四", 17, 89.0f},
        {"王五", 19, 92.0f}
    };

    // 遍历结构体数组，访问每个元素的成员
    for (int i = 0; i < 3; i++) {
        cout << "第" << i+1 << "个学生：" << endl;
        cout << "姓名：" << stuArr[i].name << "，年龄：" << stuArr[i].age << "，成绩：" << stuArr[i].score << endl;
    }
    // 定义结构体指针，指向结构体变量s的地址
    Student* p = &s2;

    // 指针访问成员：用 ->
    cout << "指针访问-姓名：" << p->name << endl;
    cout << "指针访问-年龄：" << p->age << endl;
    cout << "指针访问-成绩：" << p->score << endl;
    
    return 0;
}
