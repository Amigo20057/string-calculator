#include"include.h"
#include"stringCal.h"
#include"defaultCal.h"

//LITE CALCULATOR
/*
int main() {
    char choice;
    short op;
    do {
        system("CLS");
        std::cout << "---CALCUL---" << std::endl << std::endl;
        std::cout << "1 SUM" << std::endl;
        std::cout << "2 Minus" << std::endl;
        std::cout << "3 Divide" << std::endl;
        std::cout << "4 Multiply" << std::endl;
        std::cout << "5 Sqrt Equations" << std::endl;
        std::cout << "6 Pow" << std::endl;
        std::cout << "7 EXIT" << std::endl << std::endl;
        std::cin >> op;
        switch (op) {
        case 1: {
            Calculator cal;
            std::cout << cal.sum();
            break;
        }
        case 2: {
            Calculator cal;
            std::cout << cal.minus();
            break;
        }
        case 3: {
            Calculator cal;
            std::cout << cal.div();
            break;
        }
        case 4: {
            Calculator cal;
            std::cout << cal.mult();
            break;
        }
        case 5: {
            double a, b, c;
            std::cout << "Enter A: ";
            std::cin >> a;
            std::cout << "Enter B: ";
            std::cin >> b;
            std::cout << "Enter C: ";
            std::cin >> c;
            Calculator cal(a,b,c);
            cal.sqrEquations();
            break;
        }
        case 6: {
            Calculator cal;
            std::cout << cal.powD();
            break;
        }
        case 7: {
            exit(1);
        }
        default:{
            std::cerr << "\nError\n";
            break;
        }
        }

        std::cout << std::endl << "Next [y/n]: ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
*/

//STRING CALCLATOR
int main() {
    stringCalculator sC;
    sC.stringCal();
}

