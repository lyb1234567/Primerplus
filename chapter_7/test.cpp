#include <iostream>
#include <string>
struct time_struct
{
    int hours;
    int minutes;
    int seconds;
};
const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);
void test_input_error();
void test_const_usage();
void test_2D_array();
void test_const_char_usage();
void test_struct();
void test_function_pointer();
void test_auto_usage();
void set_2D_array(int arr[][4]);
void set_time(time_struct *a);
double function_model(int a);
void use_function_pointer(double (*pt)(int));
int main()
{
#if 0
    test_const_usage();
    test_input_error();
    test_2D_array();
    test_const_char_usage();
    test_struct();
#endif
    test_function_pointer();
}
void test_input_error()
{

    using namespace std;
    double factor;
    cout << "Enter factor:";
    while (!(cin >> factor))
    {
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }
        cout << "Bad inout;Please enter a valid number:";
    }
    cout << "Factor:" << factor;
}
void test_const_usage()
{
    using namespace std;
    int a = 39;
    // ptr可以指向不同的地址，但是指向的值不能改变
    const int *ptr = &a;
    cout << *ptr << " " << &ptr << endl;
    a++;
    //可以通过修改a的值来改变ptr的值，因为这里的const仅代表ptr的值不能改变，并不代表其指向的值不能改变
    cout << *ptr << " " << &ptr << endl;
    int sloth = 80;
    const int *ps = &sloth;
    //使得finger只能指向sloth，但是可以用与修改sloth的值
    int *const finger = &sloth;
    *finger += 1;
    cout << sloth;
}
void set_2D_array(int arr[][4])
{
    using namespace std;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = i * j;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void test_2D_array()
{
    using namespace std;
    int array[3][4];
    set_2D_array(array);
    return;
}
void test_struct()
{
    using namespace std;
    time_struct a{10, 20, 30};
    cout << "Before change：" << endl;
    cout << "Hours:" << a.hours << " "
         << "Minutes:" << a.minutes << " "
         << "Seconds:" << a.minutes << endl;
    set_time(&a);
    cout << "Hours:" << a.hours << " "
         << "Minutes:" << a.minutes << " "
         << "Seconds:" << a.minutes << endl;
}
void test_const_char_usage()
{
    using namespace std;
    const char *str = "Hello World";
    int count = 0;
    while (*str)
    {
        if (*str == 'l')
        {
            count++;
        }
        *str++;
    }
    cout << count << " l in the string" << endl;
}
void test_function_pointer()
{
    //声明一个指向参数为int,并返回double的函数的指针。
    double (*pt)(int);
    pt = function_model;
    use_function_pointer(function_model);
    std::cout << std::endl;
    double array[10] = {1, 2, 3, 4, 5, 6, 8};
    const double *(*pt1)(const double *, int) = f1;
    auto pt2 = f2;
    auto pt3 = f3;
    *pt1(array, 3);
    *pt2(array, 3);
    *pt3(array, 3);
}
void set_time(time_struct *a)
{
    a->hours = a->hours + 1;
}
double function_model(int a)
{
    using namespace std;
    return a + 3;
}
void use_function_pointer(double (*pt)(int))
{

    std::cout << (*pt)(10) << std::endl;
    std::cout << "Using the pointer";
}
const double *f1(const double ar[], int n)
{
    std::cout << "Using f1" << std::endl;
}
const double *f2(const double[], int)
{
    std::cout << "Using f2" << std::endl;
}
const double *f3(const double *, int)
{
    std::cout << "Using f3" << std::endl;
}