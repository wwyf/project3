#ifndef _DATA_H_
#define _DATA_H_
#include "polynomial.h"
#include <string>
#include <iostream>
#include <map>
class usePoly{
public:
    bool findPolynomial(const std::string& name) const;
    //在多项式库中寻找有无该标识符对应的多项式
    void addPolynomial(const std::string& name, const Polynomial & poly);
    //在多项式库中添加该标识符对应的多项式
    void deletePolynomial(const std::string&);
    //在多项式库中删除该标识符对应的多项式
    Polynomial getPolynomial(const std::string&);
    //在该多项式库中取得该标识符对应的多项式
    void printAll();
    //格式化打印该多项式库中存有的所有多项式
private:
    std::map<std::string, Polynomial> data; 
    //索引是多项式对应的标识符，内容是该多项式
};

#endif
