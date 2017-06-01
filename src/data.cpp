#include "data.h"
#include <sstream>
#include <vector>


// 可能有异常,重复添加
void usePoly::addPolynomial(const std::string& name, const Polynomial & t)
{
    data.at(name) = t;
    return ;
}

// 可能有异常, 找不到
void usePoly::deletePolynomial(const std::string& t)
{
    data.erase(t);
}

// 可能有异常, 找不到
Polynomial usePoly::getPolynomial(const std::string& t)
{
    return data.at(t);
}

void usePoly::printAll()
{
    for (auto a : data){
        std::cout << a.first << "=" << a.second.toString() << std::endl;
    }
}