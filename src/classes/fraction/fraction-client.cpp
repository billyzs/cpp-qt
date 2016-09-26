#include <QTextStream>
#include "fraction.h"

int main() {
    QTextStream cout(stdout);
    Fraction f1, f2;
    f1.set(3, 4);
    f2.set(11,12);                      /* Set through a member function. */
    // f2.m_Numerator = 12;                /* Error, m_Numerator is visible but not accessible. */
    cout << "The first fraction is: " << f1.toString() << endl;
    cout << "\nThe second fraction, expressed as a double is: "
         << f2.toDouble() << endl;
    Fraction f3(12, 30); 
    cout << f1.toString() << " / "
         << f2.toString() << " = " 
         << f1.divide(f2).toString() << endl;
    return 0;
}

