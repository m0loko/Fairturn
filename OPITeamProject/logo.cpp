#include "logo.h"

#include <thread>
// Function for text animation
void startWelcomeAnimation() {
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
        "",
        "Developed by artaka, m0loko, tmg24aqua, TimaEvchuk, artemdol12"
    };

    // Loop through each line of text
    for (const string& line : lines) {
        // Print each character in the line with a small delay
        for (char c : line) {
            cout << c << flush;  // Immediately output the character to the console
            this_thread::sleep_for(0.99ms);            // Delay between characters (in milliseconds)
        }
        cout << endl;
        this_thread::sleep_for(250ms);  // Delay between lines
    }
    this_thread::sleep_for(1000ms);  // Pause before clearing the screen
    // Clear the screen with a fade-out effect
    for (int i = 0; i < 5; ++i) {
        system("cls");  // Clear the console
        this_thread::sleep_for(30ms);
    }
    system("cls");
}