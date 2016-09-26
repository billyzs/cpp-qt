#ifndef _FRACTION_H_ 
#define _FRACTION_H_  

#include <QString>


class Fraction {
public:
    Fraction(int numerator, int denominator);
    Fraction();
    void set(int numerator, int denominator);
    int getNumerator(){return m_Numerator;}
    int getDenominator(){return m_Denominator;};
    double toDouble() const;
    QString toString() const;
    Fraction add(const Fraction& other);
    Fraction subtract(const Fraction& other);
    Fraction multiply(const Fraction& other);
    Fraction divide(const Fraction& other);
    void simplify();
private:
    int m_Numerator;
    int m_Denominator;
};

#endif

