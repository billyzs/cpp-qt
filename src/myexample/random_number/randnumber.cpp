#include <cstdlib>
#include <iostream>
#include <QString>

using namespace std;
int main(int argc, char* argv[]){
  unsigned int seed;
  cout << "choose an integer as seed: " << endl;
  cin >> seed;
  srand(seed);
  for (int i=0; i < 10; ++i){
    cout << "the " << i << "th " << "random number is: " << rand() << endl; 
  }
  return EXIT_SUCCESS;
}

