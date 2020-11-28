#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <iterator>
#include "lab4/base.hpp"
#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "lab4/div.hpp"
#include "lab4/mult.hpp"
#include "lab4/power.hpp"
#include <string>

using namespace std;

class Factory {
    private:
    public:
        Factory(){};
        Base* parse(char** input, int length){
		for(int i = 0; i < length; i++){

                    if(input[i] = "+"){
                        string s = input[i-1];
                        string j = input[i+1];
			cout << s << " " << j << endl;
               	    }
		}
                /*
                else if(input.next() = "-"){
                    string op2 = input.next();
                    Base* sub = new Sub(op1, op2);
                }
                else if(input.next() = "/"){
                    string op2 = input.next();
                    Base* div = new Div(op1, op2);
                }
                else if(input.next() = "*"){
                    string op2 = input.next();
                    Base* mult = new Mult(op1, op2);
                }
                else if(input.next() = "**"){
                    string op2 = input.next();
                    Base* pow = new Power(op1, op2);
                }*/
           
            
        };

};

#endif
