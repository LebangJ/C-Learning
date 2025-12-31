#include <iostream>  // 修复：标准头文件用<>，而非""
using namespace std;

// 目标函数1：无参、返回int
int func1() { return 10; }
// 目标函数2：2个int参数、返回int
int func2(int a, int b) { return a + b; }
// 目标函数3：无参、无返回值
void func3() { cout << "Hello FuncPtr" << endl; }

int main() {
    // 定义匹配各函数的函数指针
    int (*fp1)();
    int (*fp2)(int, int);
    void (*fp3)();

    // 函数指针赋值：函数名 == 函数入口地址（两种写法等价）
    fp1 = func1;   // 推荐写法：简洁直观
    fp2 = &func2;  // 兼容写法：加&取地址，效果完全一致
    fp3 = func3;

    // 判空防护（避免野指针调用）
    if (fp1 != nullptr && fp2 != nullptr && fp3 != nullptr) {
        // ========== 方式1：解引用调用 ✅ 最符合指针语义，推荐 ==========
        int res1 = (*fp1)();          // 等价于 func1() → res1=10
        int res2 = (*fp2)(10, 20);    // 等价于 func2(10,20) → res2=30
        cout << "解引用调用结果：res1=" << res1 << ", res2=" << res2 << endl;
        (*fp3)();                     // 等价于 func3() → 打印Hello FuncPtr

        // ========== 方式2：直接调用 ✅ 编译器语法糖，最简洁，推荐 ==========
        res1 = fp1();//指针赋值在函数指针中直接变成调用函数
        res2 = fp2(10, 20);
        cout << "直接调用结果：res1=" << res1 << ", res2=" << res2 << endl;
        fp3();
    } else {
        cout << "Cleveland this is for you" << endl;
    }

    return 0;
}
