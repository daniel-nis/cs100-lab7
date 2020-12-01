#include "factory.hpp"

int main(int argv, char** argc) {
    Factory* factory = new Factory();
    cout << factory->parse(argc, argv) << "\n";

    return 0;
} 