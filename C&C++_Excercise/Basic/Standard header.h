#ifndef __INCvxWorksh
#define __INCvxWorksh
#ifdef __cplusplus   // 告诉编译器，这部分代码按C语言方式编译和连接，而不是按C++方式 
extern "C" {
#endif
/*...*/
#ifdef __cpluscplus
}
#endif
#endif /* __INCvxWorksh */


/*
标准头文件的结构
1、2、10行的作用是防止该头文件被重复引用

3行表示若当前使用的是C++编译器

4~8行的作用机制：
1）extern告诉编译器，其声明的函数和变量可以在本模块或其他模块中使用。通常在模块的头文件中对本模块提供给其他模块引用的函数和全局变量以关键字extern声明；
2）"C"指其修饰的变量和函数是按照C语言方式编译和连接的。
3）extern "C"是编译器提供的与C连接交换指定的符号，用来解决名字匹配问题。
4）理解：被extern "C"修饰的变量和函数是按照C语言方式进行编译和链接的 
*/

/*
C++中，void foo(int x, int y) 和 void foo(int x, float y) 编译生成的符号是不同的，前者可能是_foo_int_int类，后者可能是_foo_int_float类。
可以发现，这样的名字包含了函数名、函数参数数量及类型信息，C++就是考这种机制来实现函数重载的。
（如果加extern"C" 声明后，模块编译生成foo的目标代码时，就不会对其名字进行特殊处理，采用了C语言的方式，也就是_foo之类。） 
*/ 
