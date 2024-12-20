#include "Monom.h"
#include <cstdint>

Monom::Monom(double coef, size_t size, int16_t* array){
    _coef = coef;
    _size = size;
    _array = array;
}

double Monom::GetCoef() const {
    return _coef;
}


Monom::Monom(const Monom& mon){
    _size = mon._size;
    _coef = mon._coef;
    _array = new int16_t[_size];
    for (size_t i = 0; i < _size; i++){
        _array[i] = mon._array[i];
    }
}

Monom& Monom::operator=(const Monom& mon){
    if (this == &mon){
        return *this;
    }
    delete [] _array;
    _array = new int16_t[mon._size];
    _size = mon._size;
    _coef = mon._coef;
    for (size_t i = 0; i < _size; i++){
        _array[i] = mon._array[i];
    }
    return *this;
}

Monom Monom::operator+(const Monom& mon)const{
    Monom a(*this);
    if (a._size != mon._size){
        throw "cant add these monoms";
    }
    for (size_t i = 0; i < _size; i ++){
        if (a._array[i] != mon._array[i]){
            throw "cant add these monoms";
        }
    }
    a._coef += mon._coef;
    return a;
};

bool Monom::CanOperate(const Monom& mon) const {
    if (this->_size != mon._size){
        return false;
    }
    for (size_t i = 0; i < _size; i ++){
        if (this->_array[i] != mon._array[i]){
            return false;
        }
    }
    return true;
}

Monom Monom::operator-(const Monom& mon)const{
    Monom a(*this);
    if (a._size != mon._size){
        throw "cant substract these monoms";
    }
    for (size_t i = 0; i < _size; i ++){
        if (a._array[i] != mon._array[i]){
            throw "cant substract these monoms";
        }
    }
    a._coef -= mon._coef;
    return a;
};

Monom Monom::operator*(const Monom& mon) const{
    size_t mSize = std::max(this->_size, mon._size);
    int16_t* array = new int16_t[mSize];
    int16_t* maxArr = _array;
    if (mSize == mon._size)
        maxArr = mon._array;
    size_t minSize = std::min(this->_size, mon._size);
    for(size_t i = 0; i < mSize; i++){
        array[i] = i < minSize ? _array[i] + mon._array[i] : maxArr[i];
    }
    return Monom(_coef * mon._coef, mSize, array);
}
Monom Monom:: operator*(double x) const{
    double new_coef=_coef*x;

    Monom res=Monom(new_coef,_size, _array);
    return res;
}

Monom Monom::operator/(const Monom& mon) const{
    size_t mSize = std::max(this->_size, mon._size);
    int16_t* array = new int16_t[mSize];
    size_t minSize = std::min(this->_size, mon._size);
    for(size_t i = 0; i < minSize; i++){
        array[i] = _array[i] - mon._array[i];
    }
    if(this->_size > mon._size){
        for(size_t i = minSize; i < this->_size; i++){
            array[i] -= _array[i];
        } 
    }
    else{
        for(size_t i = minSize; i < mon._size; i++){
            array[i] -= mon._array[i];
        } 
    }
    return Monom(_coef / mon._coef, mSize, array);
}

Monom::~Monom(){
    delete [] _array;
}