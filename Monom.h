#include <iostream>
#include <cstdint>

class Monom{
private:
    double _coef;
    size_t _size;
    int16_t* _array;
public:
    Monom(double coef, size_t size, int16_t* array);
    double GetCoef() const;
    Monom(const Monom& mon);
    Monom& operator=(const Monom& mon);
    Monom operator+(const Monom& mon)const;
    bool CanOperate(const Monom& mon) const;
    Monom operator-(const Monom& mon)const;
    Monom operator*(const Monom& mon) const;
    Monom operator*(double x) const;
    Monom operator/(const Monom& mon) const;
    ~Monom();
    friend std::ostream& operator<<(std::ostream& os, const Monom& m){
        os<<m._coef;
        int astr_flag=0;
        for(size_t i=0; i<m._size-1;i++){
            if(m._array[i]!=0){
                if(m._array[i]==1){
                    if(astr_flag>0)
                        std::cout<<"*";
                    os<<"X"<<i+1;
                    astr_flag++;

                }
                
                else{
                    if(astr_flag>0)
                        std::cout<<"*";
                    os<<"X"<<i+1<<"^"<<m._array[i];
                    astr_flag++;
                }
            }
        }
        if(m._array[m._size-1]!=0){
            if(m._array[m._size-1]==1){
                if(astr_flag>0)
                        std::cout<<"*";
                os<<"X"<<m._size;
            }
            else{
                if(astr_flag>0)
                        std::cout<<"*";
                os<<"X"<<m._size<<"^"<<m._array[m._size-1];
            }
        }
            
        return os;
    }

};