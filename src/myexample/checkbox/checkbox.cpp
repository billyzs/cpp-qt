#include <QtGui>
#include <QCheckBox>
#include <QButtonGroup>
#include <QDialogButtonBox>

int main(int argc, char*argv[]){
  QApplication app(argc, argv);
  QTextStream cout(stdout);
    QString q1text = QString("The sky is blue in Boston.");
    QCheckBox *y = new QCheckBox("&yes");
    QCheckBox *n = new QCheckBox("&no");
    QDialogButtonBox *w = new QDialogButtonBox();
    QButtonGroup *g = new QButtonGroup(w);
  do{  
    g->setExclusive(true);
    g->addButton(y);
    g->addButton(n);
    if (y->checkState() == Qt::Checked){
      if (n->checkState() == Qt::Checked){
        cout << "You're kidding." << endl;
      }
      else {
        cout << "The weather must be good" << endl;
      }
    }

    else {
      cout << "Either the sky is gray in Boston, or you have a stroke." << endl;
    }
  } while (y->checkState() == Qt::Unchecked && n->checkState() == Qt::Unchecked);
}

