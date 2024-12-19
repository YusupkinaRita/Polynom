#include "Polynom.h"

Polynom::Polynom() {
    _head = nullptr;
}

Polynom::Polynom(const Polynom& tmp) {
    Node* tmpHead = tmp._head;
    while (tmpHead != nullptr) {
        AppendMonom(tmpHead->GetMonom());
        tmpHead = tmpHead->Next;
    }
}

void Polynom::AppendMonom(Monom monom) {
    if (_head == nullptr) {
        _head = new Node(monom);
    } 
    else 
    {
        Node* tmp = _head;
        while (tmp->Next != nullptr) {
            if (tmp->GetMonom().CanOperate(monom)) {
                Monom result = tmp->GetMonom() + monom;
                tmp->SetMonom(result);
                return;
            }
            tmp = tmp->Next;
        }
        tmp->Next = new Node(monom);
    }
}

void Polynom::Print() {
    Node* tmp = _head;
    while (tmp != nullptr) {
        if (tmp == _head)
            tmp->GetMonom().print();
        else {
            if (tmp->GetMonom().GetCoef() > 0)
                std::cout << " + ";
            tmp->GetMonom().print();
        }
        tmp = tmp->Next;
    }
}

Polynom Polynom::operator+(const Polynom& polynom) const {
    Polynom res(*this);
    Node* rightPolynom = polynom._head;

    while (rightPolynom != nullptr)
    {
        res.AppendMonom(rightPolynom->GetMonom());
        rightPolynom = rightPolynom->Next;
    }
    return res;
}

Polynom Polynom::operator-(const Polynom& polynom) const {
    Polynom res(*this);

    return res;
}
Polynom Polynom::operator*(const Polynom& polynom) const {
        Polynom res(*this);

    return res;
}
Polynom Polynom::operator/(const Polynom& polynom) const {
        Polynom res(*this);

    return res;
}