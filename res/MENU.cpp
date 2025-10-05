#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std::chrono_literals;

using namespace std;


// Function to draw a frame around text
void drawBorderWithText(int width, int height, const vector<string>& lines) {
    // Top border with animation
    for (int i = 0; i < width; i++) {
        cout << "*";
        this_thread::sleep_for(20ms);  // Delay
    }
    cout << endl;

    // Blank lines before text
    for (int i = 0; i < (height - lines.size()) / 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(20ms);  // Delay
    }

    // Outputting text with animation
    for (const auto& line : lines) {
        cout << "*";
        int paddingLeft = (width - 2 - line.size()) / 2;
        int paddingRight = width - 2 - line.size() - paddingLeft;

        for (int j = 0; j < paddingLeft; j++) cout << " ";

        for (char c : line) {
            cout << c << flush;
            this_thread::sleep_for(20ms);  // Per-character delay
        }

        for (int j = 0; j < paddingRight; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(20ms);  //Delay between lines of text
    }

    // Blank lines after text
    for (int i = 0; i < (height - lines.size() - 1) / 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << "*" << endl;
        this_thread::sleep_for(20ms);  // Delay
    }

    // Bottom border with animation
    for (int i = 0; i < width; i++) {
        cout << "*";
        this_thread::sleep_for(20ms);  // Delay
    }
    cout << endl;
}

// Welcome animation
void   welcomeAnimation() {
    // Array of strings to display as animated text
    string lines[] = {
        "  ______            __             __                                   ",
        " /      \\          |  \\           |  \\                                  ",
        "|  $$$$$$\\ ______   \\$$  ______  _| $$$_    __    __   ______   _______  ",
        "| $$_  \\$$|      \\ |  \\ /      \\|   $$ \\  |  \\  |  \\ /      \\ |       \\ ",
        "| $$ \\     \\$$$$$$\\| $$|  $$$$$$\\\\$$$$$$  | $$  | $$|  $$$$$$\\| $$$$$$$\\",
        "| $$$$    /      $$| $$| $$   \\$$ | $$ __ | $$  | $$| $$   \\$$| $$  | $$",
        "| $$     |  $$$$$$$| $$| $$       | $$|  \\| $$__/ $$| $$      | $$  | $$",
        "| $$      \\$$    $$| $$| $$        \\$$  $$ \\$$    $$| $$      | $$  | $$",
        " \\$$       \\$$$$$$$ \\$$ \\$$         \\$$$$   \\$$$$$$  \\$$       \\$$   \\$$",
    };
    // Loop through each line of text
    for (const string& line : lines) {
        // Print each character in the line with a small delay
        for (char c : line) {
            cout << c << flush;  // Immediately output the character to the console
            this_thread::sleep_for(0.99ms);            // Delay between characters (in milliseconds)
        }
        cout << endl;
        this_thread::sleep_for(500ms);  // Delay between lines
    }
    this_thread::sleep_for(800ms);  // Pause before clearing the screen
    // Clear the screen with a fade-out effect
    for (int i = 0; i < 5; ++i) {
        system("cls");  // Clear the console
        this_thread::sleep_for(50ms);
    }
    system("cls");
}



// Main menu
void mainMenu() {
    vector<string> menu = {
        "Fairnturn",
        "",
         "====== Main menu =======",
        "1. Enter data manually"   ,
        "2. Load data from Google Sheets"   ,
        "3. Exit the program   "   ,


    };
    drawBorderWithText(50, 12, menu);

}

// Function to change the window title
// void setConsoleTitle(const string& title) {
//     setlocale(LC_CTYPE, "Russian");
//     wstring wideTitle(title.begin(), title.end());
//     SetConsoleTitle(wideTitle.c_str());
// }
//
// // Function to set the console size
// void setConsoleSize(int width, int height) {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
//     COORD coord = { width, height };
//     SetConsoleScreenBufferSize(hConsole, coord);
//     SetConsoleWindowInfo(hConsole, TRUE, &rect);
// }