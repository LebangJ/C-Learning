#include <iostream>
using namespace std;
//局部变量：一次初始化，全程保值；
//全局变量 / 函数：文件内可见，跨文件隔离；
//类成员：属于类，所有对象共享。

// 测试局部static变量
void countCall() {
    // static局部变量：仅初始化1次，值永久保留
    static int callNum = 0; 
    callNum++;
    cout << "函数被调用了 " << callNum << " 次" << endl;
}
// static全局变量：仅test1.cpp可见
static int global_val = 100;

// static全局函数：仅test1.cpp可见
static int add(int a, int b) {
    return a + b;
}
int main() {
    countCall(); // 第1次调用：callNum=1（首次初始化+自增）
    countCall(); // 第2次调用：callNum=2（直接自增，不初始化）
    countCall(); // 第3次调用：callNum=3
    return 0;
}
