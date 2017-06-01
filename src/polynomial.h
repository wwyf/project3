#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#define MAX_ITEM_NUM 50

#include <string>
#include <vector>
#include <iostream>

class Polynomial{

public:
    typedef double coefficient_t;
    typedef int power_t;
    struct item{
        power_t power;//每一项的次数
        coefficient_t coefficient;//系数
        item(power_t arg, coefficient_t arg2):power(arg),coefficient(arg2) {}
        bool operator<(const item& rhs){return this->power < rhs.power;}
    };//每一项

    Polynomial(int maxPower = MAX_ITEM_NUM);
    Polynomial(const std::vector<item> t);
    // explicit Polynomial(const std::string & poly);// 必须用合法的字符串才能初始化

// overload operator
    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator*(const item& rhs) const;
    Polynomial operator*(const Polynomial& rhs) const;

    Polynomial operator*(coefficient_t rhs) const;
    friend Polynomial operator*(coefficient_t lhs, const Polynomial& rhs);

    double evaluate(coefficient_t arg);
    std::string toString() const;

    friend std::ostream & operator<<(std::ostream& out, const Polynomial & rhs);

private:
    // std::string _identity;// 多项式的标识符，便于使用存储的多项式
    power_t _maxPower; // 最大次数, +1 即为数组存放的项数
    std::vector <item> _items;// 存放每一项的数组
};


#endif