#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <string>
#include <vector>

class Polynomial{

public:
    typedef double coefficient_t;
    struct item{
        int power;//每一项的次数
        coefficient_t coefficient;//系数
    };//每一项
    Polynomial();
    Polynomial(const std::vector<item> t);


// overload operator
    Polynomial operator+(const Polynomial& rhs);
    Polynomial operator-(const Polynomial& rhs);
    Polynomial operator*(const Polynomial& rhs);

    Polynomial operator*(int rhs);
    friend Polynomial operator*(int lhs, const Polynomial& rhs);

    int evaluate(int arg);
    std::string toString();


private:
    std::string _identity;// 多项式的标识符，便于使用存储的多项式
    std::vector <item> _items;// 存放每一项的数组
};


#endif