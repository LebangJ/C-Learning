#include <iostream>
using namespace std;
typedef int MyInt;//把标识符int用myint代替
using constInt = const int;//同理比起typedef更加明白
typedef int (*CalcFunc)(int, int); //把函数指针用CalcFunc代替
sing CalcFunc = int (*)(int, int);
int main(){
    MyInt a = 1;
    int b = 2;
    constInt c = 3;
    cout << a << endl; 
    cout << b << endl;
    cout << c << endl;
    system("pause");
    return 0;
}