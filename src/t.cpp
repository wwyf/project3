#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "polynomial.h"
using namespace std;
int main(){
    // Polynomial::item item1(0,2);
    // std::vector<Polynomial::item> t;
    // t.push_back(Polynomial::item(0,1));
    // t.push_back(Polynomial::item(1,1));
    // t.push_back(Polynomial::item(6,1));
    // t.push_back(Polynomial::item(3,0));
    // Polynomial a(t);
    // cout << a.toString() << endl;


    std::vector<Polynomial::item> t2;
    t2.push_back(Polynomial::item(0,1));
    t2.push_back(Polynomial::item(1,1));
    t2.push_back(Polynomial::item(2,1));

    // t2.push_back(Polynomial::item(3,2));
    Polynomial b(t2);
    cout << b.toString() << endl;
    cout << b.evaluate(2) << endl;


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