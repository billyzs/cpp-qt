#include <iostream>
#include <cstdint>
#include <cstring>
using namespace std;

class Snafu {
public:
    Snafu(int x) : mData(x) {}
    void showSum(Snafu & other) const {
        cout << mData + other.mData << endl; 
    }
private:
    int mData;
};

void foo(const Snafu & myObject1,
         const Snafu & myObject2) {
    Snafu* tmp = new Snafu(0); 
    memcpy(tmp, &myObject2, sizeof(myObject2));
    // [ . . . ]  
    myObject1.showSum(const_cast<Snafu&>(myObject2));
    myObject1.showSum(*tmp);
    delete tmp;
}

int main() {

    Snafu myObject1(12345);
    Snafu myObject2 = Snafu(54321);
    Snafu& r_2 = myObject2;
    foo(myObject1, myObject2);

}

