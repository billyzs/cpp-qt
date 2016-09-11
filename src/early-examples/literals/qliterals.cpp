#include <QTextStream>
#include <QString>

int main() {
    const char* charstr = "GNU stands for \"GNU\'s Not UNIX\".";
    QTextStream cout(stdout);  
    QString str = charstr; /* C-style strings can be converted to QString. */
    cout << str << endl;
    cout << "Title 1\t\t" "\"Cat Clothing\""  << endl;
    cout << "Title 2\t\t" "\"Dog Dancing\"" << endl;
    return 0;
}

