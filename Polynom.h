#pragma once
#include "Node.h"

class Polynom {
private:
    Node* _head;

public:
    Polynom();
    Polynom(const Polynom& tmp);
    Polynom& operator=(const Polynom& p);
    void AppendMonom(Monom monom);
    void Print();
    Polynom operator+(const Polynom& polynom) const;
    Polynom operator-(const Polynom& polynom) const;
    Polynom operator*(const Polynom& polynom) const;
    Polynom operator/(const Polynom& polynom) const;



};