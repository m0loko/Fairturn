#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, vector<int>> inputFromFile() {
    setlocale(LC_ALL, "Russian");

    map<string, vector<int>> memberList;
    string path;

    cout << "Enter CSV file name (default 'output.csv', enter 'd'): ";
    cin >> path;
    if (path == "d") path = "output.csv";

    ifstream in(path);
    if (!in.is_open()) {
        cout << "Error opening file!" << endl;
        return memberList;
    }

    int currentLab;
    cout << "Enter current lab number: ";
    cin >> currentLab;

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        size_t index;
        string surname;
        wchar_t sym = L',';

        index = line.find_first_of(sym);
        if (index != string::npos) {
            surname = line.substr(0, index);
            line.erase(0, index + 1);
        }
        else {
            surname = line;
            line.clear();
        }

        if (surname.empty()) continue;

        vector<int> data(4, -1);

        for (int i = 0; i < 3; i++) {
            string field;
            index = line.find_first_of(sym);
            if (index != string::npos) {
                field = line.substr(0, index);
                line.erase(0, index + 1);
            }
            else {
                field = line;
                line.clear();
            }

            if (field.empty()) continue;

            if (i == 2) {
                if (field == "да" || field == "Да" || field == "yes" || field == "Yes") {
                    data[i] = 10;
                }
                else if (field == "нет" || field == "Нет" || field == "no" || field == "No") {
                    data[i] = 0;
                }
            }
            else {
                try {
                    data[i] = stoi(field);
                }
                catch (...) {
                    cerr << "Invalid input from file(maybe wrong data from table)!" << endl;
                }
            }
        }

        data[3] = currentLab;
        memberList[surname] = data;
    }

    in.close();
    cout << "File loaded successfully!" << endl;
    return memberList;
}
