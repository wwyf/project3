#include "data.h"
#include <sstream>
#include <vector>

bool usePoly::findPolynomial(const std::string& name) const
{
    auto find_result = this->data.find(name);
    if (find_result == data.end())
        return false;
    else
        return true;
}


// 可能有异常,重复添加
void usePoly::addPolynomial(const std::string& name, const Polynomial & t)
{
    data[name] = t;
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
    // try{
        Polynomial ans = data.at(t);
        return ans;
    // }
    // catch (std::out_of_range e){
    //     throw e;
    // }
}

void usePoly::printAll()
{
    for (auto a : data){
        std::cout << a.first << "=" << a.second.toString() << std::endl;
    }
}