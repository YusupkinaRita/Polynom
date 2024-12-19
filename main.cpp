#include <iostream>
#include "Polynom.h"

int main(){
    Monom a1 = Monom(2, 3, new int16_t[3]{1, 0, 0});
    Monom a2 = Monom(3, 3, new int16_t[3]{0, 1, 0});
    Monom a3 = Monom(-1, 3, new int16_t[3]{0, 0, 1});
    Monom a4 = Monom(5, 3, new int16_t[3]{1, 1, 1});

    Polynom p;
    p.AppendMonom(a1);
    p.AppendMonom(a2);
    p.AppendMonom(a3);
    p.AppendMonom(a4);

    p.Print();

    std::cout << std::endl;

    return 0;
}