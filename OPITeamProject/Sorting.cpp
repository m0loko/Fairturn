#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function for sorting and displaying data
void printSortedData(vector<pair<string, vector<int>>>& sortedMembers) {
    setlocale(LC_CTYPE, "Russian");

    // Line number for displaying
    int lineNumber = 1;

    // Display the sorted data with line numbers
    for (const auto& entry : sortedMembers) {
        const string& surname = entry.first;
        const vector<int>& data = entry.second;

        int labsPassed = data[0];       // Number of labs passed
        int labsToDo = data[1];         // Number of labs yet to be completed
        int attendedValue = data[2];    // 0 - not attended, 10 - attended
        int totalScore = data[3];       // Total score

        // Determine if attended the session
        string attended = (attendedValue == 10) ? "Yes" : "No";

        // Display the information with line number
        if (lineNumber<10)
        {
            cout << lineNumber++ << ".  " << surname << " "
                << labsPassed << " "
                << labsToDo << " "
                << attended << " "
                << totalScore << endl;
        }
        else
        {
            cout << lineNumber++ << ". " << surname << " "
                << labsPassed << " "
                << labsToDo << " "
                << attended << " "
                << totalScore << endl;
        }
    }
	cout << endl << endl;
}
