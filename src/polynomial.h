#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#define MAX_ITEM_NUM 50 
//即该程序能够处理(多项式的最大次数+1),可通过修改该数字来实现更大次数的多项式的计算

#include <string>
#include <vector>
#include <iostream>

class Polynomial{

public:
    typedef double coefficient_t;//系数类型为double
    typedef int power_t;//指数类型为int
    struct item{
        power_t power;//每一项的次数
        coefficient_t coefficient;//系数
        item(power_t arg, coefficient_t arg2):power(arg),coefficient(arg2) {}
        bool operator<(const item& rhs) const{return this->power < rhs.power;}
        bool operator!=(const item& rhs) const{return ((power != rhs.power)||(coefficient != rhs.coefficient));};
    };// 每一项

//构造函数
    Polynomial(int maxPower = MAX_ITEM_NUM);
    // 生成（maxPower+1）项的多项式，并且初始化指数为对应数字，系数为0
    Polynomial(const std::vector<item> t);
    // 使用vector来初始化多项式的系数
    // 注意此vector的内容需合法


//重载运算符
    Polynomial operator+(const Polynomial& rhs) const;//多项式相加
    Polynomial operator-(const Polynomial& rhs) const;//多项式相减
    Polynomial operator*(const item& rhs) const;//多项式乘某一项
    Polynomial operator*(const Polynomial& rhs) const;//多项式乘多项式
    Polynomial operator*(coefficient_t rhs) const;//多项式的数乘
    friend Polynomial operator*(coefficient_t lhs, const Polynomial& rhs);
        //多项式的数乘
    bool operator==(const Polynomial& rhs) const;

// 运算接口
    double evaluate(coefficient_t arg) const;// 多项式求值
    Polynomial derivative() const; //多项式求导

// I/O
    std::string toString() const;//多项式转变成字符串类型输出
    friend std::ostream & operator<<(std::ostream& out, const Polynomial & rhs);
    //使用cout输出

private:
    power_t _maxPower; // 最大次数, +1 即为数组存放的项数
    std::vector <item> _items;// 存放每一项的数组，该数组默认最大项数为MAX_ITEM_NUM 为50
};


#endif
