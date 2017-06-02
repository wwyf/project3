#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "polynomial.h"
using namespace std;

// Polynomial str2poly(const std::string & poly)
// {
//     std::stringstream strPoly;
//     strPoly << poly; 
//     char leftParenthese,rightParenthese,comma;
//     int power;
//     double coefficient;
//     std::vector<Polynomial::item> myPoly;
//     while (strPoly.good()){
//         strPoly >> leftParenthese >> power >> comma >> coefficient >> rightParenthese;
//         myPoly.push_back(Polynomial::item(power, coefficient));
//     }
//     return Polynomial(myPoly);
// }


int main(){
    // cout << str2poly("(1,2)(2,5)(0,5)") << endl;;
    // Polynomial::item item1(0,0);
    std::vector<Polynomial::item> t;
    t.push_back(Polynomial::item(0,0));
    t.push_back(Polynomial::item(1,0));
    t.push_back(Polynomial::item(6,0));
    // t.push_back(Polynomial::item(3,0));
    Polynomial a(t);
    cout << a.toString() << endl;


    // std::vector<Polynomial::item> t2;
    // t2.push_back(Polynomial::item(0,1));
    // t2.push_back(Polynomial::item(1,1));
    // t2.push_back(Polynomial::item(2,1));

    // // t2.push_back(Polynomial::item(3,2));
    // Polynomial b(t2);
    // cout << b.toString() << endl;
    // cout << b.evaluate(2) << endl;


    // std::vector<Polynomial::item> t3;
    // t3.push_back(Polynomial::item(0,0));
    // Polynomial::item zero(0, 0);
    // Polynomial c(t3);

    // // cout << (a + b).toString() << endl;
    // cout << (a * 0).toString() << endl;
    // cout << (a * zero).toString() << endl;
    // cout << (a * c).toString() << endl;
    // cout << (a * b).toString() << endl;
}