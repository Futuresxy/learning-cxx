#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
template<class T>
T plus(T a, T b) {
    return a + b;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    // TODO: 修改判断条件使测试通过
    std::cout<< (plus(0.1, 0.2) == 0.3) <<std::endl;  
    //0.1 + 0.2 ≠ 精确的 0.3  因为浮点数无法精确表示十进制的小数,
    //在double fp64下存在多位尾数，相加后精度能够体现差异
    //加上f后是fp32通过舍人等操作发现刚好相等
    ASSERT(std::abs(plus(0.1f, 0.2f) - 0.3f )<1e-9 , "How to make this pass?");

    return 0;
}
