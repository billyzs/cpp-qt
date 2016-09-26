#include <iostream>
using namespace std;

class Quux {
public:
    Quux(int initializer) :
        mData(initializer), printcounter(0) {}
    void print() const;
    void showprintcounter() const {
      std::cout << printcounter << std::endl; 
    }
    void incrementPrintCounter() const {
      printcounter += 1;
    }

private:
    int mData;
    mutable int printcounter;
};

void Quux::print() const {
    cout << mData << endl; 
    incrementPrintCounter();
}

int main() {
    Quux a(45);
    a.print();
    a.print();
    a.print();
    a.showprintcounter();
    const Quux b(246);
    b.print();
    b.print();
    b.showprintcounter();
    return 0;
}

