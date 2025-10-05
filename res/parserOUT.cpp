#include "parser.h"
void parserOUT()
{
    cout << "Parser is running...\n";
    int parserOutRes = system("python parserOUT.py");
    if (parserOutRes != 0) {
        cerr << "Cannot run parser script(check parserOUT.py file)" << endl;
    }
    else {
        cout << "Parser stopped working...\n";
        system("cls");
    }
}
