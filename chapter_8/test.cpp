#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
using namespace std::chrono;
void test_inline_regular();
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
    test_inline_regular();
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