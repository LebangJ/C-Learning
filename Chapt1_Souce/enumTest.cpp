#include <iostream>
using namespace std;

//  C风格枚举：定义语法：enum 枚举名 { 枚举常量1, 枚举常量2, ... };
enum Week {
    MON,  // 默认赋值 0
    TUE,  // 自动+1 → 1
    WED,  // 自动+1 → 2
    FRI = 4, // 手动指定值 4
    SAT,     // 延续规则 →5
    SUN      // 延续规则 →6
};


// 未指定底层类型 → 默认底层int，常量赋值1
enum class Status {
    SUCCESS = 1,
    FAILED  = 0
};

// 指定底层类型 → char，常量赋值1，
// 设定底层是char只是限定内存大小，还是只能用整数
enum class StatusChar : char {
    SUCCESS = 1,
    FAILED  = 0
};

int main() {
    // 1. 定义枚举变量，赋值枚举常量
    Week today = Week::FRI;
    //Week:: 作用域限定
    // 2. 可直接输出（底层是int，隐式转换）
    cout << "今天对应的数值：" << today << endl; // 输出：4
        //隐式转换，cout打印整数4
    cout << "今天对应的数值：" <<(char)((int)today+'0') << endl; // 输出：4
        //显式转换，cout打印字符4
    // 3. 可直接与整数比较/赋值（弱类型特性）
    if (today == 4) cout << "今天是周五！\n";
    //today = 2; // 直接赋值整数，语法合法（不推荐）

    // 强类型枚举使用
    Status a = Status::SUCCESS;
    StatusChar b = StatusChar::SUCCESS;
    //完全禁止隐式转换，必须手动双层强转 
    cout << "胜利对应的数值：" << static_cast<char>( static_cast<int>(a) + '0' ) << endl; // 输出：4
    cout << "胜利对应的数值：" << (char)((int)b+'0')<< endl; 
        //cout打印字符1
    return 0;
}

/*
赋值规则：第一个常量默认0，后续依次 + 1；可给任意常量手动指定整数值，未指定的延续「前值 + 1」；
底层类型：固定为 int，不可自定义；
❌ 致命缺陷 1：全局作用域污染 → 枚举常量属于全局，多个枚举中出现同名常量会直接编译冲突；
❌ 致命缺陷 2：弱类型不安全 → 枚举变量可与整数随意隐式转换、赋值、比较，极易写出逻辑错误代码。
*/
