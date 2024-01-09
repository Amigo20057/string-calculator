#pragma once

#include"include.h"

const double pi = acos(-1);

struct leksema {
    char type;
    double val;
};


class stringCalculator {
private:
    char ch;
public:
    double ctg(double x);

    bool math(std::stack<leksema>& StackN, std::stack<leksema>& StackO, leksema& it) {
        double a, b, res;
        a = StackN.top().val;
        StackN.pop();
        switch (StackO.top().type) {
        case '+': {
            b = StackN.top().val;
            StackN.pop();
            res = a + b;
            it.type = '0';
            it.val = res;
            StackN.push(it);
            StackO.pop();
            break;
        }
        case '-': {
            b = StackN.top().val;
            StackN.pop();
            res = b - a;
            it.type = '0';
            it.val = res;
            StackN.push(it);
            StackO.pop();
            break;
        }
        case '*': {
            b = StackN.top().val;
            StackN.pop();
            res = a * b;
            it.type = '0';
            it.val = res;
            StackN.push(it);
            StackO.pop();
            break;
        }
        case '/': {
            b = StackN.top().val;
            if (a == 0) {
                std::cerr << "\nError Divide Zero\n";
                return false;
            }
            else {
                StackN.pop();
                res = b / a;
                it.type = '0';
                it.val = res;
                StackN.push(it);
                StackO.pop();
                break;
            }
        case '^': {
            b = StackN.top().val;
            StackN.pop();
            res = pow(b, a);
            it.type = '0';
            it.val = res;
            StackN.push(it);
            StackO.pop();
            break;
        }
        case 's': {
            res = sin(a);
            it.type = '0';
            it.val = res;
            StackN.push(it);
            StackO.pop();
            break;
        }
        case 'c': {
            res = cos(a);
            it.type = '0';
            it.val = res;
            StackN.push(it);
            StackO.pop();
            break;
        }
        case 't': {
            if (cos(a) == 0) {
                std::cerr << "Invalid argument for tang";
                return false;
            }
            else {
                res = tan(a);
                it.type = '0';
                it.val = res;
                StackN.push(it);
                StackO.pop();
                break;
            }
        }
        case 'g': {
            if (sin(a) == 0) {
                std::cerr << "Invalid argument for ctg";
                return false;
            }
            else {
                res = ctg(a);
                it.type = '0';
                it.val = res;
                StackN.push(it);
                StackO.pop();
                break;
            }
        }
        default: {
            std::cerr << "\nError\n";
            return false;
            break;
        }
        }
        }
        return true;
    }

    int getRang(char c) {
        if (c == 's' || c == 'c' || c == 't' || c == 'g') {
            return 4;
        }
        if (c == '^') {
            return 3;
        }
        if (c == '+' || c == '-') {
            return 1;
        }
        if (c == '*' || c == '/') {
            return 2;
        }
        return 0;
    }

    int stringCal() {
        char c;
        double value;
        bool flag = 1;
        std::stack <leksema> stackN;
        std::stack <leksema> stackO;
        leksema it;

        while (1) {
            c = std::cin.peek();
            if (c == '\n')break;
            if (c == ' ') {
                std::cin.ignore();
                continue;
            }
            if (c == 's' || c == 'c' || c == 't') {
                char func[3];
                for (int i = 0; i < 3; i++) {
                    c = std::cin.peek();
                    func[i] = c;
                    std::cin.ignore();
                }
                if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') {
                    it.type = 's';
                    it.val = 0;
                    stackO.push(it);
                    continue;
                }
                if (func[0] == 'c' && func[1] == 'o' && func[2] == 's') {
                    it.type = 'c';
                    it.val = 0;
                    stackO.push(it);
                    continue;
                }
                if (func[0] == 't' && func[1] == 'a' && func[2] == 'n') {
                    it.type = 't';
                    it.val = 0;
                    stackO.push(it);
                    continue;
                }
                if (func[0] == 'c' && func[1] == 't' && func[2] == 'g') {
                    it.type = 'g';
                    it.val = 0;
                    stackO.push(it);
                    continue;
                }
            }
            if (c == 'p') {
                it.type = '0';
                it.val = pi;
                stackN.push(it);
                flag = 0;
                std::cin.ignore();
                continue;
            }
            if (c >= '0' && c <= '9' || c == '-' && flag == 1) {
                std::cin >> value;
                it.type = '0';
                it.val = value;
                stackN.push(it);
                flag = 0;
                continue;
            }
            if (c == '+' || c == '-' && flag == 0 || c == '*' || c == '/' || c == '^') {
                if (stackO.size() == 0) {
                    it.type = c;
                    it.val = 0;
                    stackO.push(it);
                    std::cin.ignore();
                    continue;
                }
                if (stackO.size() != 0 && getRang(c) > getRang(stackO.top().type)) {
                    it.type = c;
                    it.val = 0;
                    stackO.push(it);
                    std::cin.ignore();
                    continue;
                }
                if (stackO.size() != 0 && getRang(c) <= getRang(stackO.top().type)) {
                    if (math(stackN, stackO, it) == false) {
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (c == '(') {
                it.type = c;
                it.val = 0;
                stackO.push(it);
                std::cin.ignore();
                continue;
            }
            if (c == ')') {
                while (stackO.top().type != '(') {
                    if (math(stackN, stackO, it) == false) {
                        system("pause");
                        return 0;
                    }
                    else {
                        continue;
                    }
                }
                stackO.pop();
                std::cin.ignore();
                continue;
            }
            else {
                std::cout << "Error" << std::endl;
                system("pause");
                return 0;
            }
        }
        while (stackO.size() != 0) {
            if (math(stackN, stackO, it) == false) {
                system("pause");
                return 0;
            }
            else {
                continue;
            }
        }
        std::cout << "Result: " << stackN.top().val << std::endl;
        ch = c;
        return 0;
    }

    double ctg(double x) {
        double a = cos(x);
        double b = sin(x);
        return (a / b);
    }
};

