
#ifndef _POLYNOMISL_CPP_
#define _POLYNOMISL_CPP_

#include "polynomial.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>


// void print(std::vector<Polynomial::item> t){
//     for (auto i : t){
//         std::cout << i.power << " " << i.coefficient << " | ";
//     }
//     std::cout << std::endl;
// }


////构造函数，创建一个有一定容量的vector
Polynomial::Polynomial(int maxPower):_maxPower(maxPower){
    for (int i = 0; i <= _maxPower; i++)
        _items.push_back(item(i, 0));
    _maxPower = 0;// 漏了这一句话,造成很大影响
}

// 构造函数，使用vector来初始化多项式
Polynomial::Polynomial(const std::vector<item> t):Polynomial(){
    std::vector<item> t2 = t;
    std::sort(t2.begin(), t2.end());
    // _maxPower = t2[t2.size() - 1].power;
    int i = 0;
    for (i = t2.size() - 1; i > 0; i--){
        if (t2[i].coefficient != 0)
            break;
    }
    _maxPower = t2[i].power;
    // std::cout << _maxPower << std::endl;
    for (auto i : t){
        _items[i.power].coefficient = i.coefficient;
    }
}




// overload operator
// 次数大的加次数小的
Polynomial Polynomial::operator+(const Polynomial& rhs) const
{
    if (this->_maxPower < rhs._maxPower){
        return (rhs + (*this));
    }
    power_t maxPower = this->_maxPower;
    std::vector<item> ans = this->_items;
    for (int i = 0; i <= maxPower; i++){
        ans[i].coefficient += rhs._items[i].coefficient;
    }
    return Polynomial(ans);
}

// 次数大的减次数小的
Polynomial Polynomial::operator-(const Polynomial& rhs) const
{
    if (this->_maxPower < rhs._maxPower){
        return (rhs - (*this));
    }
    std::vector<item> ans = this->_items;
    power_t maxPower = std::max(this->_maxPower, rhs._maxPower);
    for (int i = 0; i <= maxPower; i++){
        ans[i].coefficient -= rhs._items[i].coefficient;
    } 
    return Polynomial(ans);
} 


// 多项式乘单项式
Polynomial Polynomial::operator*(const item& rhs) const
{
    // std::vector<item> ans = this->_items;
    // for (int i = 0; i <= this->_maxPower; i++){
    //     ans[i].power += rhs.power;
    //     ans[i].coefficient *= rhs.coefficient;
    // }
    // return Polynomial(ans);    
    // 有问题,power 和 vector 的索引 不对应 

    if (rhs.coefficient == 0){
        return Polynomial();
    }
    std::vector<item> ans(this->_maxPower + rhs.power + 1, item(0,0));
    for (int i = ans.size() - 1; i >= 0 ; i--){
        ans[i].power = i;
    }//初始化每一项的次数
    for (int i = ans.size() - 1; i >= rhs.power ; i--){
        ans[i].coefficient = this->_items[i-rhs.power].coefficient * rhs.coefficient;
    }//计算每一项的系数
    return Polynomial(ans);
}

// 多项式 乘 多项式
Polynomial Polynomial::operator*(const Polynomial& rhs) const
{
    Polynomial ans(this->_maxPower + rhs._maxPower + 1);
    Polynomial temp(rhs._items);
    for (int i = 0; i <= rhs._maxPower; i++){
        ans = ans + (*this) * rhs._items[i];
    }
    return ans;  
} 

// 多项式 数乘
Polynomial Polynomial::operator*(coefficient_t rhs) const
{
    std::vector<item> ans = this->_items;
    for (int i = 0; i <= this->_maxPower; i++){
        ans[i].coefficient *= rhs;
    }
    return Polynomial(ans);   
}

// 数字 乘 多项式 
Polynomial operator*(Polynomial::coefficient_t lhs, const Polynomial& rhs)
{
    return rhs * lhs;
}

// 判断多项式是否相等
bool Polynomial::operator==(const Polynomial& rhs) const
{
    int flag = 1;
    if (_maxPower != rhs._maxPower){
        flag = 0;
        return false;
    }
    for (int i = 0; i <= _maxPower; i++){
        if (this->_items[i] != rhs._items[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}




// 计算 多项式的值
double Polynomial::evaluate(coefficient_t arg) const
{
    double ans = 0;
    double xPower = 1;
    for (int i = 0; i <= this->_maxPower; i++){
        ans += this->_items[i].coefficient * xPower;
        xPower *= arg;
    }
    return ans;
}

Polynomial Polynomial::derivative() const
{
    std::vector<item> ans;
    for (auto i : this->_items){
        if (i.power == 0){
            ans.push_back(item(0,0));
        }
        else if (i.coefficient != 0){
            ans.push_back(item(i.power-1, i.coefficient * i.power));
        }
    }
    return Polynomial(ans);
}


// 格式化输出
// FIXME: 系数或者次数为1的时候都需要进一步调整
std::string Polynomial::toString() const
{
    std::stringstream formatOut;
    for (int i = _maxPower; i >= 0; i--){
        if (i == _maxPower){
            if (i == 0){
                formatOut  << _items[i].coefficient;
            }
            else{
                formatOut   << _items[i].coefficient << "x^" << _items[i].power;
            }
        }
        else if (i == 0 && _items[i].coefficient != 0){
            formatOut << std::showpos << _items[i].coefficient;
        }
        else if (_items[i].coefficient != 0){
            formatOut   << std::showpos << _items[i].coefficient << "x^" 
                        << std::noshowpos << _items[i].power;
        }
    }
    std::string ans;
    formatOut >> ans;
    return ans;
}

std::ostream &  operator<<(std::ostream& out, const Polynomial & rhs)
{
    out << rhs.toString(); 
    return out;
}
#endif