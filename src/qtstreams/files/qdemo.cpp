#include <QTextStream>
#include <QString>
#include <QFile>
#include <sys/stat.h>

QTextStream cout(stdout);
QTextStream cerr(stderr);

bool fileExists(const QString& filename){
  struct stat buf;
  if (stat(filename.toStdString().c_str(), &buf) != -1){
    return true;
  }
  return false;
}


int main() {
  QString str, newstr;
  QTextStream strbuf(&str);             /* strbuf is initialized with the address of str.*/

  int lucky = 7;
  float pi = 3.14;
  double e = 2.71;

  cout << "An in-memory stream" << endl;
  strbuf << "luckynumber: " << lucky << endl
	 << "pi: " << pi << endl
	 << "e: " << e << endl;

  cout << str;
  // get filename from user
  QTextStream cin(stdin);
  QString fileName;
  cout << "Type the name of the outout file: " << endl;
  cin >> fileName;

  // make sure file name doesn't exist yet
  if (fileExists(fileName)){
    cout << "file exists, overwritting." << endl;
  }
  QFile data(fileName);
  data.open(QIODevice::WriteOnly);      /* Creates (or overwrites)
                                      a disk file for output. */
  QTextStream out(&data);               /* An output file stream. */
  out << str ;
  data.close();

  cout << "Read data from the file - watch for errors." << endl;
  if(data.open(QIODevice::ReadOnly)) {  /* Make sure the file exists before
                                         attempting to read.*/
    QTextStream in(&data);              /* An input file stream. */
    int lucky2;
    in >> newstr >> lucky2;
    if (lucky != lucky2)
      cerr << "ERROR! wrong " << newstr << lucky2  << endl;
    else
      cout << newstr << " OK" << endl;

    int pi2; // if the datatype is wrong, it affects how thing are being red (reading will stop at . in this case, pi2=3; and it affects subsequent readings
    in >> newstr >> pi2;
    if (pi2 != pi)
      cerr << "ERROR! Wrong " << newstr << pi2 << endl;
    else
      cout << newstr << " OK" << endl;

    double e2;
    in >> newstr >> e2;
    if (e2 != e)
      cerr << "ERROR: Wrong " << newstr << e2 <<  endl;
    else
      cout << newstr << " OK" << endl;
    data.close();
  }

  cout << "Read from file line-by-line" << endl;
  if(data.open(QIODevice::ReadOnly)) {
    QTextStream in(&data);              /* An input file stream. */
    while (not in.atEnd()) {
      newstr = in.readLine();
      cout << newstr << endl;
    }
    data.close();
  }
  return 0;
}
