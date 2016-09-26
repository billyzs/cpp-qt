#include <iostream>
using namespace std;

int main() {
 int* ip = 0;               /* null pointer */
 delete ip;                 /* has no effect at all - ip is still null. */
 if(ip) cout << "non-null" << endl;
 else cout << "null" << endl;
 ip = new int;              /* allocate space for an int */
 int* jp = new int(13);     /* allocate and initialize */
 //[...]      
 *jp *= 100;
 *ip = *jp;
 cout << "jp: " << *jp << endl;
 cout << "ip: " << *ip << endl;
 delete ip;                 /* Without this, we have a memory leak. */
 delete jp;
 int a = 10, b = 20;
 int& ra = a;
 cout << "ra: "<< ra << endl;
 ra = 20;
 cout << "ra: " << ra << endl;
 cout << "&ra: " << &ra << endl;
 cout << "*&ra: " << *&ra << endl;
}
