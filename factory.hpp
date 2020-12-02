#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
//#include <iterator>
#include "lab4/base.hpp"
#include "lab4/op.hpp"
#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "lab4/div.hpp"
#include "lab4/mult.hpp"
#include "lab4/power.hpp"
#include <string>
#include <queue>

using namespace std;

class Factory{
    private:
        queue<Base*> operands;
        queue<string> operators;
        queue<Base*> solved;

    public:
        Factory(){};
        Base* parse(char** input, int length){
            double val = 0;
            char* c;
            string s;
            Base* h;

            for(int i = 1; i < length; i++){
                c = input[i];

                if(isOperand(c)){
                    val = stod(c);
                    Base* b = new Op(val);
                    operands.push(b);
                }

                if(isOperator(c)){
                    s = c;
                    operators.push(s);
                }
            }

            Base* val1 = operands.front();
            operands.pop();

            Base* val2 = operands.front();
            operands.pop();

            operate(val1, val2);

            Base* val3 = solved.front();
            //cout << val3->evaluate() << endl;
            //cout << val3->stringify() << endl;

            return val3;
        };

        bool isOperand(string c){
            if(c == "0" || c == "1" || c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == "7" || c == "8" || c == "9" || c == "10" || c == "11" || c == "12" || c == "13" || c == "14" || c == "15" || c == "16" || c == "17" || c == "18" || c == "19" || c == "20" || c == "21" || c == "22" || c == "23" || c == "24" || c == "25" || c == "26" || c == "27" || c == "28" || c == "29" || c == "30" ){
                return true;
            }
            return false;
        };

        bool isOperator(string c){
            if (!c.compare("+") || !c.compare("-") || !c.compare("*") || !c.compare("/") || !c.compare("**")){
                return true;
            }
            return false;
        };

        void operate(Base* val1, Base* val2){
            if(!operators.empty()){
                string op = operators.front();
                if(op == "-"){
                    operators.pop();
                    Base* sub = new Sub(val1, val2);
                    //cout << sub->stringify() << "\n";
                    //cout << sub->evaluate() << "\n";
                    if(!operands.empty()){
                        val2 = operands.front();
                        operands.pop();
                    }
                    operate(sub, val2);
                    solved.push(sub);
                }
                if(op == "+"){
                    operators.pop();
                    Base* add = new Add(val1, val2);
                    //cout << add->stringify() << "\n";
                    //cout << add->evaluate() << "\n";
                    if(!operands.empty()){
                        val2 = operands.front();
                        operands.pop();
                    }
                    operate(add, val2);
                    solved.push(add);
                }
                if(op == "/"){
                    operators.pop();
                    Base* div = new Div(val1, val2);
                    //cout << div->stringify() << "\n";
                    //cout << div->evaluate() << "\n";
                    if(!operands.empty()){
                        val2 = operands.front();
                        operands.pop();
                    }
                    operate(div, val2);
                    solved.push(div);
                }
                if(op == "*"){
                    operators.pop();
                    Base* mult = new Mult(val1, val2);
                    //cout << mult->stringify() << "\n";
                    //cout << mult->evaluate() << "\n";
                    if(!operands.empty()){
                        val2 = operands.front();
                        operands.pop();
                    }
                    operate(mult, val2);
                    solved.push(mult);
                }
                if(op == "**"){
                    operators.pop();
                    Base* pow = new Power(val1, val2);
                    //cout << pow->stringify() << "\n";
                    //cout << pow->evaluate() << "\n";
                    if(!operands.empty()){
                        val2 = operands.front();
                        operands.pop();
                    }
                    operate(pow, val2);
                    solved.push(pow);
                }
            }
        };
};

#endif
