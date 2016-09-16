#include <iostream>
#include <cstdlib>
#include <stdio.h>
int main(int argc, char* argv[]){
  using namespace std;
  cout << "enter the cost and payment amounts" << endl;
  double cost, payment;
  cin >> cost;
  cin >> payment;
  cout << (payment - cost) * 1000 << endl;
  int change = ((payment - cost) * 1000) /  10; // in cents; truncate values < 1cent
  cout << "change: " << change << endl;
  int tens = change / 1000;
  change %= 1000;
  int fives = change / 500;
  change %= 500;
  int ones = change / 100;
  change %= 100;
  int quarters = change / 25;
  change %= 25;
  int dimes = change / 10;
  change %= 10;
  int nickels = change / 5;
  change %= 5;
  int pennies = change;
  char buffer[200];
  sprintf(buffer, "%d tens, %d fives, %d ones, %d quarters, %d dimes, %d nickels and %d pennies \n", tens, fives, ones, quarters, dimes, nickels, pennies);
  cout << buffer << endl;
  return 0;
}
