#include <malloc.h>
void createArray() {
    int* arr = (int*)malloc(10 * sizeof(int));  // 从堆分配内存
    //函数参数是内存的字节数
    //malloc的返回值是通用指针类型 void*（无类型指针），C/C++ 语法规定「void*不能直接赋值给具体类型指针（如int*）」；

    if (arr != NULL) {
        //作用：校验内存是否申请成功，只有arr≠NULL时，才能安全使用这块堆内存；
        //特殊情况下，指针变量指向了不合法的内存空间
        //不校验的后果：如果arr=NULL，后续执行arr[0]=100会触发「空指针解引用」，直接导致程序崩溃。
        arr[0] = 100;  // 使用堆内存
        // ...
    }
    free(arr);  // 手动释放内存
}