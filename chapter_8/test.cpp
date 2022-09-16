#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
using namespace std;
using namespace std::chrono;
void test_inline_regular();
void test_reference_variable();
void test_overload_template();
void test_explicit_inexplicit_instantiate();
//定义模板类型
template <typename T>
void swap_test(T &a, T &b);
//显示实例化
template void swap_test<double>(double &a, double &b);
struct test
{
    const char *name;
    int data;
};

//显式具体化
template <>
void swap_test<test>(test &a, test &b);
inline int comp_1(int a, int b) { return (a > b) ? a : b; }
int comp_2(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    // test_inline_regular();
    // test_reference_variable();
    // test_overload_template();
    test_explicit_inexplicit_instantiate();
    return 0;
}
/*测试调用普通函数以及内联函数的时间差异*/
/*
对于普通函数来说，多次调用，会使得程序在某个指令之间来回跳转，从而造成程序之间的时间开销。
而内联函数调用，程序无需跳到另一个位置执行代码，再跳回来。因此内联函数的运行速度比常规函数稍快，但代价是需要占用更多内存。
*/
void test_inline_regular()
{
    auto start_1 = (double)clock();
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            comp_1(i, j);
        }
    }
    auto stop_1 = (double)clock();
    auto duration_1 = (stop_1 - start_1);
    cout << "Time taken by Inline call: "
         << duration_1 << " µs" << endl;
    auto start_2 = (double)clock();
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            comp_2(i, j);
        }
    }
    auto stop_2 = (double)clock();
    auto duration_2 = (stop_2 - start_2);
    cout << "Time taken by Regular Call: "
         << duration_2 << " µs" << endl;
}
/*
引用变量的变化会同时影响原变量的大小。
同时他们的地址保持相同.
使用引用的时候，必须将其初始化: int &c 这是不可以的。
所以说，一旦使用某个引用变量就必须使它一直效忠这个变量：
int &rodents=rats 其实就是 int* const ptr=&rats。
*/
void test_reference_variable()
{
    using namespace std;
    int a = 3;
    int &b = a;
    cout << "A:" << a << endl;
    cout << "B:" << b << endl;
    b++;
    cout << "A:" << a << endl;
    cout << "B:" << b << endl;

    cout << "Adress_a:" << &a << endl;
    cout << "Adress_b:" << &b << endl;
}

/*
函数模板以及函数重载。
我们可以对与使用同种算法的，但输入不用数据类型的参数使用重载。同时对于某些特定类型的使用显式具体化。
*/
template <typename T>
void swap_test(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <>
void swap_test<test>(test &a, test &b)
{
    test temp;
    temp = a;
    a = b;
    b = temp;
}
void test_overload_template()
{
    using namespace std;
    test a = {"Mike", 12};
    test b = {"Jack", 13};
    cout << "Before Swap:" << endl;
    cout << "a.name:" << a.name << endl;
    cout << "a.data:" << a.data << endl;
    cout << endl;
    cout << "b.name:" << b.name << endl;
    cout << "b.data:" << b.data << endl;
    cout << endl;
    int c = 3;
    int d = 4;
    double e = 12.1;
    double g = 12.6;
    swap_test(a, b);
    cout << "After Swap:" << endl;
    cout << "a.name:" << a.name << endl;
    cout << "a.data:" << a.data << endl;
    cout << endl;
    cout << "b.name:" << b.name << endl;
    cout << "b.data:" << b.data << endl;
    cout << "Before Swap:" << endl;
    cout << "c:" << c << " "
         << "d:" << d << endl;
    swap_test(c, d);
    cout << "After Swap:" << endl;
    cout << "c:" << c << " "
         << "d:" << d << endl;
    /*
    隐式子实例化：swap_test(a,b)，程序生成了一个T为test的例子
    显示实例化：template void swap_test<doubl>(double a,double b)
    */
}
/*
比较一下使用显示实例化和隐式实例化的速度差异
*/
void test_explicit_inexplicit_instantiate()
{
    int a = 3;
    int b = 4;

    double c = 3;
    double d = 4;

    auto start_1 = (double)clock();
    swap_test(a, b);
    auto stop_1 = (double)clock();
    auto duration_1 = (stop_1 - start_1);
    cout << "Time for inexplicit instantiation: "
         << duration_1 << " µs" << endl;
    auto start_2 = (double)clock();
    swap_test(c, d);
    auto stop_2 = (double)clock();
    auto duration_2 = (stop_2 - start_2);
    cout << "Time for explicit instantiation: "
         << duration_2 << " µs" << endl;
}
