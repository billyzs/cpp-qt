#include <cstdlib>
#include <iostream>
#include <QtGui>
int roll_dices(){
  return rand() % 11 + 2;
}
int set_game(){
  int n = roll_dices();
  while (n == 7 || n == 11 || n ==2){
    n = roll_dices();
  }
  char prompt[50];
  sprintf(prompt, "Welcome, your number is %d. Continue playing?", n);
  return QMessageBox::information(0, "2Dice game", prompt, QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes? n : 0;
}

using namespace std;
int main(int argc, char* argv[]){
  QApplication app(argc, argv);
  srand(time(NULL));
  static int player_number = set_game();
  if (player_number == 0) return EXIT_SUCCESS; 
  long play = QMessageBox::Yes;
  int rolled_number = player_number;
  bool reset = false;
  while (play == QMessageBox::Yes) {
    if(reset){
      player_number = set_game();
      if(player_number == 0) break;
      reset = false;
    }
    rolled_number = roll_dices();
    switch(rolled_number){
      default:
        char buffer[50];
        sprintf(buffer, "you rolled a %d, continue?", rolled_number);
        play = QMessageBox::information(0, "2Dice game", buffer, QMessageBox::Yes | QMessageBox::No);
        break;
      case 7: case 11: 
        play = QMessageBox::information(0, "2Dice game","Congratulations! You win. Another Game?", QMessageBox::Yes | QMessageBox::No);
        reset = true;
        break;

      case 2:
        play = QMessageBox::information(0, "2Dice game", "You lost. Another try?", QMessageBox::Yes | QMessageBox::No);
        reset = true;
    }
    if (rolled_number == player_number){
      play = QMessageBox::information(0, "2Dice game","Congratulations! You win. Another Game?", QMessageBox::Yes | QMessageBox::No);
      reset = true;
    }
   }
  // cout << ((answer == QMessageBox::Yes)? "continue" : "exit") << endl;
  return EXIT_SUCCESS;
}
