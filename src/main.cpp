#include <iostream>
#include <string>
#include <sstream>
#include "polynomial.h"
#include "data.h"
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;

usePoly myPolynomial;//用于多项式的存储

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

// 使用正则表达式检查多项式输入是否合法
bool check(const std::string& t){
    if (std::regex_match(t, std::regex("(\\(\\d+,\\d+\\))+")))
        return true;
    else
        return false;
}



// 该函数负责输入，
//如果输入标识符就返回对应多项式类对象
//如果输入多项式则返回对应多项式类对象
// FIXME: maybe throw  std::out_of_range  exception
Polynomial Input(const std::string& information ){
    string myInput;
    cout << information;
    cin >> myInput;
    if (myInput[0] == '('){
        while (!check(myInput)){
            cout << "invalid input!" << endl;
            cout << "please input again" << endl;
            cin >> myInput;
        }
        return str2poly(myInput);
    }
    else {
        while(!myPolynomial.findPolynomial(myInput))
        {
            cout << "this polynomial do not exist!!" << endl;
            cout << "please input the name again" << endl;
            cin >> myInput;
        }
        return myPolynomial.getPolynomial(myInput);
    }
}

// 输出目标多项式,以便确认
// 并确定是否需要保存
void Output(const Polynomial& rhs){
    cout << "Your polynomial is this." << endl;
    cout << rhs << endl;
    cout << "Do you want to save this Polynomial?" << endl;
    cout << "enter 'y' to save" << endl;
    cout << "enter 'n' not to save" << endl;
    string choice;
    cin >> choice;
    if (choice[0] == 'n'){
        return ;
    }
    else {
        cout << "please write down the name of this polynomial." << endl;
        string polyName;
        cin >> polyName;
        while(myPolynomial.findPolynomial(polyName))
        {
            cout << "this name exists!!" << endl;
            cout << "please input the name again" << endl;
            cin >> polyName;
        }
        myPolynomial.addPolynomial(polyName, rhs);
        cout << "save this polynomial successfully" << endl;
    }
    return ;
}

int main(){

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "1. 输入多项式" << std::endl;
    std::cout << "2. 多项式相加" << std::endl;
    std::cout << "3. 多项式相减" << std::endl;
    std::cout << "4. 多项式与常数的乘法运算" << std::endl;
    std::cout << "5. 求多项式代入某点的值" << std::endl;
    std::cout << "6. 显示所有储存多项式" << std::endl;
    std::cout << "7. 多项式与多项式相乘" << std::endl;
    std::cout << "8. 判断两个多项式是否相等" << std::endl;
    std::cout << "9. 对某个多项式求导" << std::endl;
    std::cout << "h. 帮助(查看功能列表)" << std::endl;
    std::cout << "q. 退出系统" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::string choice;
    std::cin >> choice;
    while (choice[0] != 'q'){
        switch(choice[0]){
            case '1' :{
                Polynomial myPoly = Input("please write down your polynomial.\ne.g:(3,5)(2,4)(power, coefficient)\n");
                Output(myPoly);
                break;
            }
            case '2' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                Polynomial myPoly2 = Input("please write down your second polynomial.\n");
                Output(myPoly1 + myPoly2);
                break;
            }
            case '3' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                Polynomial myPoly2 = Input("please write down your second polynomial.\n");
                Output(myPoly1 - myPoly2);
                break;
            }
            case '4' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                double times;
                cout << "please write down the number" << endl;
                cin >> times;
                Output(myPoly1 * times);
                break;
            }
            case '5' :{
                Polynomial myPoly = Input("please write down your polynomial.\n");
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
                Output(myPoly1 * myPoly2);
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
            case '9' :{
                Polynomial myPoly1 = Input("please write down your first polynomial.\n");
                cout << "Original polynomial:" << endl;
                cout << myPoly1 << endl;
                cout << "the derivative" << endl;
                Output(myPoly1.derivative());
                break;
            }
            case 'h' :{
                std::cout << "-----------------------------------" << std::endl;
                std::cout << "1. 输入多项式" << std::endl;
                std::cout << "2. 多项式相加" << std::endl;
                std::cout << "3. 多项式相减" << std::endl;
                std::cout << "4. 多项式与常数的乘法运算" << std::endl;
                std::cout << "5. 求多项式代入某点的值" << std::endl;
                std::cout << "6. 显示所有储存多项式" << std::endl;
                std::cout << "7. 多项式与多项式相乘" << std::endl;
                std::cout << "8. 判断两个多项式是否相等" << std::endl;
                std::cout << "9. 对某个多项式求导" << std::endl;
                std::cout << "h. 帮助(查看功能列表)" << std::endl;
                std::cout << "q. 退出系统" << std::endl;
                std::cout << "-----------------------------------" << std::endl;
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
