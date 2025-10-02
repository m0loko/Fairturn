#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
using namespace std;

map<string, vector<int>> inputFromFile() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
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

        // --- ‘амили€ ---
        index = line.find_first_of(sym);
        if (index != string::npos) {
            surname = line.substr(0, index);
            line.erase(0, index + 1);
        }
        else {
            surname = line;
            line.clear();
        }

        if (surname.empty()) continue; // если фамили€ пуста€, пропускаем строку

        vector<int> data(4, -1); // используем -1 как "пустое" значение

        // --- ќстальные пол€ ---
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

            // »гнорируем пустое поле
            if (field.empty()) continue;

            if (i == 2) { // поле "да/нет"
                if (field == "да" || field == "ƒа" || field == "yes" || field == "Yes") {
                    data[i] = 10;
                }
                else if (field == "нет" || field == "Ќет" || field == "no" || field == "No") {
                    data[i] = 0;
                } // иначе оставл€ем -1
            }
            else { // числовое поле
                try {
                    data[i] = stoi(field);
                }
                catch (...) {
                    // пропускаем поле, оставл€ем -1
                }
            }
        }

        data[3] = currentLab; // текуща€ лабораторна€
        memberList[surname] = data;
    }

    in.close();
    cout << "File loaded successfully!" << endl;
    return memberList;
}
