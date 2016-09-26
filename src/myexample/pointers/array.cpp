#include <stdio.h>
#include <iostream>
int main(int argc, char* argv[]){
  using namespace std;
  int e[10];
  int i[] = {1,2,3};
  int a = 10;
  int* head = a;
  // cout << *head << endl;
  for(int t = 0; t < 10; ++t){
    e[t] = t * 2;
  }
  cout << "elements in e: " << endl;
  for(int t = 0; t < 10; ++t){
    cout << *head++ << endl;
  }
  return 0;
}
