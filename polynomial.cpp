
#ifndef _POLYNOMISL_CPP_
#define _POLYNOMISL_CPP_

#include "polynomial.h"
#include <algorithm>

Polynomial::Polynomial(){

}
Polynomial::Polynomial(const std::vector<item> t){
    this->_items = t;
    sort(this->_items.begin(), this->_items.end(), 
            [](Polynomial::item lhs, Polynomial::item rhs ){
                return lhs.power < rhs.power;
            } 
        );
}


// overload operator
Polynomial Polynomial::operator+(const Polynomial& rhs)
{
    std::vector<item> ans = this->_items;
    for (auto i : rhs._items){
        if (ans.find())
    }
}
Polynomial Polynomial::operator-(const Polynomial& rhs)
{

} 
Polynomial Polynomial::operator*(const Polynomial& rhs)
{

}

Polynomial Polynomial::operator*(int rhs)
{

}
Polynomial operator*(int lhs, const Polynomial& rhs)
{

}

int Polynomial::evaluate(int arg)
{

}
std::string Polynomial::toString()
{

}

Polynomial& operator*(int lhs, const Polynomial& rhs);

#endif