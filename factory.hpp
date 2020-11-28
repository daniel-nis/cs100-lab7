#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <iterator>
#include "lab4/base.hpp"
#include "lab4/op.hpp"
#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "lab4/div.hpp"
#include "lab4/mult.hpp"
#include "lab4/power.hpp"
#include <string>
#include <stdlib.h>

using namespace std;

class Factory {
    private:
    public:
        Factory(){};
        Base* parse(char** input, int length){

            double inVal[length];
            cout << input[2] << endl;
            if(input[2] = "+"){
                inVal[1] = stod(input[1]);
                inVal[3] = stod(input[3]);
                Base* a = new Op(inVal[1]);
                Base* b = new Op(inVal[3]);
                Base* add = new Add(a, b);
                cout << add->evaluate() << endl;
                cout << add->stringify() << endl;
            }
            else if(input[2] = "-"){
                inVal[1] = stod(input[1]);
                inVal[3] = stod(input[3]);
                Base* a = new Op(inVal[1]);
                Base* b = new Op(inVal[3]);
                Base* sub = new Sub(a, b);
                cout << sub->evaluate() << endl;
                cout << sub->stringify() << endl;
            }
            else{
                cout << "No operator found" << endl;
            }
            
        };

};

#endif