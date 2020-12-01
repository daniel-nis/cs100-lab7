#include "factory.hpp"

int main(int argv, char** argc) {
    Factory* factory = new Factory();
    //cout << factory->parse(argc, argv) << "\n";
    Base* conversion = factory->parse(argc, argv);
    cout << conversion->stringify() << endl;
    cout << conversion->evaluate() << endl;

    return 0;
} 