#include <iostream>
using namespace std;

// 定义共同体：包含3个不同大小的成员
union MyUnion {
    char c;    // 占1字节
    int i;     // 占4字节
    float f;   // 占4字节
}; // 总大小 = 最大成员大小 = 4字节

int main() {

    // 方式1：先定义共同体，再单独创建变量（最常用）
    MyUnion u1;

    // 方式2：定义共同体的同时，直接创建变量
    union Data {
        short s; // 2字节
        double d; // 8字节
    } d1; // d1是Data类型的共同体变量，总大小8字节

    // 方式3：创建变量时直接初始化（仅能初始化第一个成员）
    MyUnion u2 = {'a'}; 
    //#只能一个成员，而且当多个元素类型相同的时候强制赋值第一个元素
    MyUnion u;
    // ========== 1. 给char类型成员赋值 ==========
    u.c = 'A';
    cout << "赋值char成员后：" << endl;
    cout << "u.c = " << u.c << "  （值有效）" << endl;
    cout << "u.i = " << u.i << "  （值随机，无效）" << endl; // 其他成员失效

    // ========== 2. 给int类型成员赋值 ==========
    u.i = 100; // 覆盖内存，原char成员被销毁
    cout << "\n赋值int成员后：" << endl;
    cout << "u.i = " << u.i << "  （值有效）" << endl;
    cout << "u.c = " << u.c << "  （值被覆盖，无效）" << endl;

    // ========== 3. 共同体指针访问成员 ==========
    MyUnion* p = &u;
    p->f = 3.14f; // 指针访问用 ->，覆盖内存，原int成员失效
    cout << "\n指针访问float成员：p->f = " << p->f << endl;

    return 0;
}
