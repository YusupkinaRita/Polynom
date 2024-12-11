#pragma once
#include <iostream>
#include <cstring>

class Monom{
private:
    double _koef;
    size_t _size;
    int16_t* _degrees;
    Monom* _next;
public:
    Monom(size_t size, int16_t* degrees, double koef =1){
        _koef=koef;
        _size=size;
        _degrees=degrees;
        _next=nullptr;
    }
    ~Monom(){
        delete[] _degrees;
    }

    friend std::ostream& operator<<(std::ostream& os, const Monom& m){
        os<<m._koef;
        for(size_t i=0; i<m._size-1;i++)
            os<<"X"<<i+1<<"^"<<m._degrees[i]<<" * ";
        os<<"X"<<m._size<<"^"<<m._degrees[m._size-1];
            
        return os;
    }
    Monom(const Monom& m){
        _size=m._size;
        _koef=m._koef;
        _next=m._next;
        _degrees= new int16_t[_size];
        for(size_t i=0; i<_size;i++){
            _degrees[i]=m._degrees[i];
        }
    }
    Monom& operator=(const Monom& m){
        if(this==&m){
            return *this;
        }
        delete [] _degrees;
        _degrees = new int16_t[m._size];
        std::memcpy(_degrees, m._degrees, sizeof(int16_t)*m._size);

        return *this;
    }

    Monom operator+(const Monom& m)const{
        Monom a(*this);
        if(a._size!=m._size)
            throw("cant add these monoms");
        for(size_t i=0; i<_size;i++){
            if(a._degrees[i]!=m._degrees[i])
                throw("cant add these monoms");
        }
        a._koef+=m._koef;
        return a;

    }
    Monom operator-(const Monom& m)const{
        Monom a(*this);
        if(a._size!=m._size)
            throw("cant substract these monoms");
        for(size_t i=0; i<_size;i++){
            if(a._degrees[i]!=m._degrees[i])
                throw("cant substract these monoms");
        }
        a._koef-=m._koef;
        return a;
        
    }
    Monom operator*(const Monom& m)const{
        size_t new_size=std::max(_size, m._size);
        size_t min_size=std::min(_size, m._size);
        int16_t* new_deg=new int16_t[new_size];
        for(size_t i=0; i<min_size; i++){
            new_deg[i]=_degrees[i]+m._degrees[i];
        }
        if(_size>m._size){
            for(size_t i= min_size; i< new_size;i++)
                new_deg[i]=_degrees[i];
        }
        else{
            for(size_t i= min_size; i< new_size;i++)
                new_deg[i]=m._degrees[i];

        }

        Monom a(new_size, new_deg);
        a._koef=_koef * m._koef;
        return a;
        
    }
    Monom operator/(const Monom& m)const{
        size_t new_size=std::max(_size, m._size);
        size_t min_size=std::min(_size, m._size);
        int16_t* new_deg=new int16_t[new_size];
        for(size_t i=0; i<min_size; i++){
            new_deg[i]=_degrees[i]- m._degrees[i];
        }
        if(_size>m._size){
            for(size_t i= min_size; i< new_size;i++)
                new_deg[i]=_degrees[i];
        }
        else{
            for(size_t i= min_size; i< new_size;i++)
                new_deg[i]=(-1)*m._degrees[i];

        }

        Monom a(new_size, new_deg);
        a._koef=_koef / m._koef;
        return a;
        
    }

    Monom* GetNext(){
        return _next;
    }




};