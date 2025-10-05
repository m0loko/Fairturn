#include <thread>
#include "Header.h"
#include "input.h"
#include "logo.h"
#include "parser.h"
#include "ranging.h"
#include "menu.h"
#include <chrono>
using namespace std::chrono_literals;

int main() {
    //setConsoleSize(70, 50);
    setlocale(LC_CTYPE, "Russian");
    //setConsoleTitle("FAIRTURN");
    setlocale(LC_ALL, "Russian");
    cout << "Running an environment check" << endl;
    this_thread::sleep_for(1500ms);
    system("cls");
    int checkRes = system("forpython.bat");
    if (checkRes != 0) {
        cerr << "Cannot open environment check script! (Check forpython.bat)!" << endl;
    }
    else {
        system("cls");
    }

    startWelcomeAnimation(); // Welcome animation

    int choice;
    while (true) {
        mainMenu();  // Main menu
        string message = "Select action:";


        for (char c : message) {
            cout << c << flush;
            this_thread::sleep_for(20ms);  // Pause between characters
        }
        cin >> choice;
        system("cls");

        if (choice == 1) {
            map <string, vector<int>> members = dataEntry();  // Enter data manually
            vector<pair<string, vector<int>>> sortedMembers = ranging(members);
            printSortedData(sortedMembers);
            writeToFile(sortedMembers);
            system("cls");
        }
        else if (choice == 2) {
            parserIN();
            map <string, vector<int>> members = inputFromFile();
            vector<pair<string, vector<int>>> sortedMembers = ranging(members);
            writeToFile(sortedMembers);
            parserOUT();
            printSortedData(sortedMembers);
            cout << "Press Enter: ";
            getchar();
            getchar();
            system("cls");
        }
        else if (choice == 3) {


            string message = "Exit the program...";


            for (char c : message) {
                cout << c << flush;
                this_thread::sleep_for(20ms);  // Pause between characters
            }
            cout << endl;
            break;  // Exit the program
        }
        else {
            vector<string> error = { "Incorrect choice. Try again!" };
            drawBorderWithText(50, 10, error);  // Error during selection
            this_thread::sleep_for(500ms);
            for (int i = 0; i < 3; i++) {
                cout << ".";
                this_thread::sleep_for(500ms);
            }
            cout << endl << "Little easter egg!" << endl;
            system("cls");
            choice = 0;
        }
    }
    std::cin.get();
}