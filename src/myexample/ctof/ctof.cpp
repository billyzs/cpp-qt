#include <QtGui>
float f2c(float f){
  return (f - 32) * 5 / 9;
}

int main(int argc, char* argv[]){
  QApplication app(argc, argv);
  double inputTemp;
  bool ok;
  inputTemp = QInputDialog::getDouble(0, "Fahrenheit to Celsius",
  "Input temperature in F", 1.0, -65535.0, 65535.0, 1.0, &ok);
  float tempC = f2c(inputTemp);
  QString outString = QString("%1 degrees F is %2 degrees C.").arg(inputTemp).arg(tempC);
  QMessageBox::information(0, "Conversion result", outString);
  QTextStream cout(stdout);
  cout <<"F\t|C" << endl << "----------" << endl;  
  for (int i =0; i <= 100; i += 5){
    cout << i << "\t|" << f2c(float(i)) << endl;
  }
  return EXIT_SUCCESS;
}
