#include <iostream>  // 修复：标准头文件用<>，而非""
using namespace std;
using LebronFunPtr = int(*)();
//父函数
int Father(){
    cout << "Cleveland this is for you"<<endl;
    return 1;
}
//子函数
int Son(){
    cout << "You are my sunshine"<<endl;
    return 2;
}
//主调函数
int Role(LebronFunPtr a){
    int result = 0;
    if(a != nullptr){
        //只需要有一个变量来承担函数的返回值即可调用函数
        //重点在调用函数不在于“副值”
        result = a();//更日常
        result =(*a)();//更逻辑
        a();//不返回
        cout << "OK"<<endl;

    }
    return result;
}




int main(){
    int a  = Role(Father);//函数名本身也是一个指针，类似数组名
    int b = Role(Son);
    cout <<a<<endl;
    cout << b<<endl;
    return 0;
}
/*
    总结：
        1.typeof改名函数指针
        2.创建函数指针：挖坑
        3.函数指针赋值：埋坑
        4.调用：“赋值”：实际上只是接收返回值，可以不接受
        #难点：函数名本身就是一个函数指针，并且已经包含了该函数的地址
        6.直接调用赋值（2+3+4）
        7.主调函数调用
*/