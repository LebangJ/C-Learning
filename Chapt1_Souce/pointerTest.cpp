#include "iostream"
using namespace std;
int main() {

	//1、指针的定义
	int a = 10; //定义整型变量a
	
	//指针定义语法： 数据类型 * 变量名 ;
	int * p;

	//指针变量赋值
	p = &a; //指针指向变量a的地址
	cout << &a << endl; //打印数据a的地址
	cout << p << endl;  //打印指针变量p

	//2、指针的使用
	//通过*操作指针变量指向的内存
	cout << "*p = " << *p << endl;
    cout << "*p = " << *p+1 << endl;
    
    cout << sizeof(p) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;
    //64位地址存储是16位十六进制，16*4=8*8=64byte
    //无论类型，大小都是8个字节

    //空指针：没存东西，解引用会报错
    int * k = NULL;

	//访问空指针报错 
	//内存编号0 ~255为系统占用内存，不允许用户访问
	cout << *k << endl;

    //野指针：指向非法内存空间
//   int *m = (int*)0x1100;
//	cout << *m << endl;

    //指针常量和常量指针
    //1 常量指针:不能修改指针指向的值：可以看作常量const int的指针
//    int b = 110;
//   const int * p1 = &a;
//   p1  = &b;
    //*p1 = 100;
    //注意即便此时指针指向的是别的位置仍然不能对指针进行解引用操作
        //1.1 常量规则：
    const int c = 1;
    //int * p3 = &c;
        //无法将常量的地址赋值给一个普通指针，防止你修改常量的值
    const int * p3 = &c ; 
    cout << *p3 << endl;
    //2 指针常量:地址（指向内存）不变，但可以改值
    int * const p4 = &a;

     


	system("pause");
	return 0;
}