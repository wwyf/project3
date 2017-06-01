#include <iostream>
#include <string>
#include "polynomial.h"
#include "data.h"
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;
// 1. 输入多项式
// 2. 多项式相加
// 3. 多项式相减
// 4. 多项式与常数的乘法运算
// 5. 求多项式代入某点的值
// 6. 显示所有储存多项式 降幂
// 7. 多项式与多项式相乘
// 8. 判断两个多项式是否相等
// 9. 对某个多项式求导
// h. 帮助（查看功能列表）
// q. 退出系统

// 将字符串类型的多项式转换为多项式类
Polynomial str2poly(const std::string & poly)
{
    std::stringstream strPoly;
    strPoly << poly; 
    char leftParenthese,rightParenthese,comma;
    int power;
    double coefficient;
    std::vector<Polynomial::item> myPoly;
    while (strPoly.good()){
        strPoly >> leftParenthese >> power >> comma >> coefficient >> rightParenthese;
        myPoly.push_back(Polynomial::item(power, coefficient));
    }
    return Polynomial(myPoly);
}

// 检查多项式输入是否合法
bool check(const std::string& t){
    if (std::regex_match(t, std::regex("(\\(\\d+,\\d+\\))+")))
        return true;
    else
        return false;
}

//TODO
// 该函数负责输入，
//如果输入标识符就返回对应多项式类对象
//如果输入多项式则返回对应多项式类对象
Polynomial Input(const std::string& information ){
    string myInput;
    cout << information;
    getline(cin, myInput);
    while (!check(myInput)){
        cout << "invalid input!" << endl;
        cout << "please input again" << endl;
        getline(cin, myInput);
    }
    return str2poly(myInput);
}

int main(){
    usePoly myPolynomial;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "1. 输入多项式" << std::endl;
    std::cout << "2. 多项式相加" << std::endl;
    std::cout << "3. 多项式相减" << std::endl;
    std::cout << "4. 多项式与常数的乘法运算" << std::endl;
    std::cout << "5. 求多项式代入某点的值" << std::endl;
    std::cout << "6. 显示所有储存多项式" << std::endl;
    std::cout << "9. 帮助（查看功能列表）" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::string choice;
    std::cin >> choice;
    while (choice[0] != 'q'){
        switch(choice[0]){
            case '1' :{
                Polynomial myPoly = Input("please write down your polynomial.\ne.g:(3,5)(2,4)\n");
                string myName;
                cout << "please write down the name of your polynomial" << endl;
                cin >> myName;
                myPolynomial.addPolynomial(myName, myPoly);
                break;
            }
            case '2' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                Polynomial myPoly2 = Input("please write down your second polynomial.\n");
                cout << (myPoly1 + myPoly2) << endl;
                break;
            }
            case '3' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                Polynomial myPoly2 = Input("please write down your second polynomial.\n");
                cout << (myPoly1 - myPoly2) << endl;
                break;
            }
            case '4' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                double times;
                cout << "please write down the number" << endl;
                cin >> times;
                cout << (myPoly1 * times) << endl;
                break;
            }
            case '5' :{
                Polynomial myPoly = Input("please write down your polynomial");
                double times;
                cout << "please write down the number you want to put in" << endl;
                cin >> times;
                cout << "the result is " << myPoly.evaluate(times) << endl;
                break;
            }
            case '6' :{
                cout << "Your polynomials are lists below." << endl;
                myPolynomial.printAll();
                break;
            }
            case '7' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                Polynomial myPoly2 = Input("please write down your second polynomial.\n");
                cout << (myPoly1 * myPoly2) << endl;                
                break;
            }
            case '8' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                Polynomial myPoly2 = Input("please write down your second polynomial.\n");
                if (myPoly1 == myPoly2) 
                    cout << "These two polynomials are same." << endl;
                else
                    cout << "These two polynomials are not same." << endl;
                break;
            }
            case '9' :{// 9. 对某个多项式求导
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                cout << myPoly1.derivative() << endl;                
                break;
            }
            case 'h' :{

            }
            default:{
                cout << "your input is invalid." << endl;
            }
        }
        cout << "please write down your choice again." << endl;
        cin >> choice;
    }
    cout << "You have quited this system successfully." << std::endl;
    return 0;
}
