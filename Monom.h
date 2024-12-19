#include <iostream>

class Monom{
private:
    double _coef;
    size_t _size;
    int16_t* _array;
public:
    Monom(double coef, size_t size, int16_t* array);
    double GetCoef() const;
    void print() const;
    Monom(const Monom& mon);
    Monom& operator=(const Monom& mon);
    Monom operator+(const Monom& mon)const;
    bool CanOperate(const Monom& mon) const;
    Monom operator-(const Monom& mon)const;
    Monom operator*(const Monom& mon) const;
    Monom operator/(const Monom& mon) const;
    ~Monom();
};