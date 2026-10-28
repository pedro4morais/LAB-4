
// Name: Pedro Henrique Morais
// Course: CIS-162
// Instructor: David Busch
// Lab 4 - Temperature Output
// Date: October 26, 2026

// Precondition: The input file contains temperatures.
// Postcondition: Valid temperatures are shown as star bars.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    ifstream inputFile("temperatures.txt");

    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    cout << "Temperature Bar Chart" << endl;
    cout << "Scale: 1 star = 3 degrees from -30" << endl;
    cout << "Range: -30 to 120" << endl << endl;

    string line;

    while (getline(inputFile, line)) {

        // Skip empty lines
        if (line.find_first_not_of(" \t\r\n") == string::npos) {
            continue;
        }

        stringstream lineInput(line);
        int temperature;
        string extra;

        // Check for invalid input
        if (!(lineInput >> temperature) ||
            (lineInput >> extra)) {
            cout << "Invalid input, skipped." << endl;
            continue;
        }

        // Check temperature range
        if (temperature < -30 || temperature > 120) {
            cout << "Invalid temperature: "
                << temperature << endl;
            continue;
        }

        // Calculate number of stars
        int stars = (temperature + 30) / 3;

        cout << temperature << " | ";

        int count = 0;

        while (count < stars) {
            cout << "*";
            count++;
        }

        cout << endl;
    }

    inputFile.close();

    return 0;
}
