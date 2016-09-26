#include <QString>
#include "fraction.h"
#include "assert.h"
Fraction::Fraction(){}

Fraction::Fraction(int n, int d) :
  m_Numerator(n),
  m_Denominator(d)
  {
    assert(d != 0);
    simplify();
  }

void Fraction::set(int nn, int nd) {
    m_Numerator = nn;
    m_Denominator = nd;
}

double Fraction::toDouble() const {
    return 1.0 * m_Numerator / m_Denominator;
}

QString Fraction::toString() const {
  return QString("%1 / %2").arg(m_Numerator).arg(m_Denominator);
}

Fraction Fraction::add(const Fraction& other)
{
  int n = m_Numerator* other.m_Denominator + other.m_Numerator *m_Denominator;
  int d = m_Denominator * other.m_Denominator;
  // Fraction output(n, d);
  // output.simplify();
  return Fraction(n, d);
}
int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a%b);
}
void Fraction::simplify()
{
  int f = gcd(m_Numerator, m_Denominator);
  set(m_Numerator/ f, m_Denominator / f);

}

Fraction Fraction::subtract(const Fraction& other)
{
  return add(Fraction(-other.m_Numerator, other.m_Denominator));
}

Fraction Fraction::multiply(const Fraction& other)
{
  return Fraction(m_Numerator * other.m_Numerator, m_Denominator * other.m_Denominator);
}  

Fraction Fraction::divide(const Fraction& other)
{
  Fraction inv(other.m_Denominator, other.m_Numerator);
  return multiply(inv);
}
