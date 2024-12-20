#include "Polynom.h"

Polynom::Polynom() {
    _head = nullptr;
}

Polynom::Polynom(const Polynom& tmp) {
    _head=tmp._head;
    Node* tmp_next = _head->Next;
    Node* copy_next=tmp._head->Next;
    while (copy_next != nullptr) {
        tmp_next=copy_next;
        copy_next=copy_next->Next;
        tmp_next = tmp_next->Next;
    }
}
Polynom& Polynom::operator=(const Polynom& p){
    if (this == &p){
        return *this;
    }
    Polynom res=Polynom();
    Node* res_tmp=res._head;
    Node* tmp=p._head;
    while (tmp!=nullptr){
        res_tmp=tmp;
        res_tmp=res_tmp->Next;
        tmp=tmp->Next;
    }
    return res;
    
    
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
            std::cout<<tmp->GetMonom();
        else {
            if (tmp->GetMonom().GetCoef() > 0)
                std::cout << " + ";
            std::cout<<tmp->GetMonom();
        }
        tmp = tmp->Next;
    }
    std::cout<<std::endl;
}

Polynom Polynom::operator+(const Polynom& polynom) const {
    Polynom res(*this);
    Node* rightPolynom = polynom._head;

    while (rightPolynom != nullptr)
    {
        res.AppendMonom(rightPolynom->GetMonom());
        rightPolynom = rightPolynom->Next;
    }
    res.Print();
    return res;
}

Polynom Polynom::operator-(const Polynom& polynom) const {
    Polynom res(*this);
    Node* rightPolynom = polynom._head;

    while (rightPolynom != nullptr)
    {
        Monom m_min=rightPolynom->GetMonom()*(-1);
        res.AppendMonom(m_min);
        rightPolynom = rightPolynom->Next;
    }
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