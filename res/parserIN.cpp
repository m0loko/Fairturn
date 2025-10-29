#include "parser.h"
void parserIN()
{
	cout << "Parser is running...\n";
	int parserInRes = system("python parserIN.py");
	if (parserInRes != 0) {
		cerr << "Cannot run parser script(check parserIN.py file)" << endl;
	}
	else {
		cout << "Parser stopped working...\n";
		system("cls");
	}
}