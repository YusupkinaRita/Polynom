#include "Monom.h"


class  Polynom
{
private:
    Monom* _head;
public:
    Polynom(){
        _head=nullptr;
     }
    ~ Polynom();

    void AppendMonom(Monom* monom){
        if(_head==nullptr){
            _head=monom;
        }
        else{
            Monom* tmp=_head;
            while(tmp!= nullptr){
                tmp =tmp->GetNext();
            }
        }
    }




};


