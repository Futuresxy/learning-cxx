#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
//函数前的static ：限制该函数的链接属性，使其仅在当前编译单元（即当前 .cpp 文件）内可见。
//函数内部的static ：使 static_ 成为静态存储期的局部变量。
//               只初始化一次：在程序第一次执行到该声明时初始化，之后不再重新初始化。
//               生命周期贯穿整个程序运行期：即使函数返回，变量值也不会销毁。
//               作用域仍限于函数内部：只能在 func 内访问。
static int func(int param) {
    static int static_ = param;
    std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
