/**
   This example shows the
   mehanics of passing arrays to functions,
   and returning them by pointer
*/

#include <assert.h>
#include <iostream>
int paramSize;

void bar(int* integers) {
    integers[2]=3;                      /* Change the third element in the incoming array. */
}

int* foo(int arrayparameter[]) {
    using namespace std;
    paramSize = sizeof(arrayparameter);
    bar(arrayparameter);                /* Pass an array by pointer to a function. */
    return arrayparameter;              /* Return an array as a pointer from a function. */
}
    
int main(int argc, char** argv) {
    int intarray2[10] = {9,9,9,9,9,9,9,2,1};
    char chararray[20] = "Hello World"; /* Special syntax for initializing char array. */
    int intarray1[20];                  /* Uninitialized memory. */
    int* retval;                        /* Uninitialized pointer. */

//  intarray1 = foo(intarray2);         /* Error, intarray1 is like a char* const, it cannot be assigned to. */

    retval = foo(intarray2);
    assert (retval[2] == 3);
    assert (retval[2] = intarray2[2]);
    assert (retval == intarray2);
    int refSize = sizeof(intarray2);
    using namespace std;
    // try {assert(refSize == paramSize);}
    //catch(int e){
    cout << "ref: " << refSize << "param: " << paramSize << endl;
    //}
    return 0;
}

