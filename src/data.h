#ifndef _DATA_H_
#define _DATA_H_
#include "polynomial.h"
#include <string>
#include <iostream>
#include <map>
class usePoly{
public:
    void addPolynomial(const std::string&, const Polynomial &);
    void deletePolynomial(const std::string&);
    Polynomial getPolynomial(const std::string&);
    void printAll();
private:
    std::map<std::string, Polynomial> data; 
};

#endif