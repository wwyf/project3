#include <iostream>
#include <string>
#include "polynomial.h"
int main(){
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
    while (choice[0] != '0'){
        switch(choice[0]){
            case '1' :{

                break;
            }
            case '2' :{
            
                break;
            }
            case '3' :{

                break;
            }
            case '4' :{

                break;
            }
            case '5' :{

                break;
            }
            case '6' :{

                break;
            }
            case '7' :{

                break;
            }
            case '8' :{

                break;
            }
            // case 'a' :{

            // }
            // case 'b' :{

            // }
            default:{

            }
        }
        std::cin >> choice;
    }
    std::cout << "You have quited this system successfully." << std::endl;
    return 0;
}