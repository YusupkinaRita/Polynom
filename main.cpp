#include <iostream>
#include "Polynom.h"
#include <cstdint>

int main(){
    Monom a1 = Monom(2, 3, new int16_t[3]{1, 0, 0});
    Monom a2 = Monom(3, 3, new int16_t[3]{0, 1, 0});
    Monom a3 = Monom(-1, 3, new int16_t[3]{0, 0, 1});
    Monom a4 = Monom(5, 3, new int16_t[3]{1, 1, 1});
    Monom a5 = Monom(2, 3, new int16_t[3]{1, 0, 0});
    Monom a6 = Monom(2, 3, new int16_t[3]{0, 1, 0});

    Polynom p;
    Polynom p1;
    p.AppendMonom(a1);
    p.AppendMonom(a1);
    p.AppendMonom(a2);
    p.AppendMonom(a3);
    p.AppendMonom(a4);
    p1.AppendMonom(a5);
    //p1.AppendMonom(a6);

    p.Print();
    p1.Print();
    Polynom x=p;
    x.Print();
    
    // Polynom p_plus=p+p1;
    // Polynom p_min=p-p1;
    // p_plus.Print();
    // p_min.Print();

    std::cout << std::endl;

    return 0;
}