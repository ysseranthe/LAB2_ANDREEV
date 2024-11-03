#include <iostream>
#include <string>
#include <fstream>
#include "cs.h"
#include "pipe.h"
#include "file.h"
using namespace std;

void upload(int& i, int& j) {
    string input, line, name, pipeLength, pipeDiameter, pipeRepair, workSt, numInWork, eff;
    bool repair;

    cout << "Enter the filename with extension:" << endl;
    getline(cin, input);
    ifstream in(input);
    if (!in.is_open()) {
        cout << "Could not open file for reading." << endl;
        return;
    }

    while (getline(in, line)) {
        try {
            if (line == "=PIPE=") {
                if (!getline(in, name) || !getline(in, pipeLength) || !getline(in, pipeDiameter) || !getline(in, pipeRepair)) {
                    throw invalid_argument("Error reading pipe data");
                }
                if (pipeRepair == "1") repair = true;
                else if (pipeRepair == "0") repair = false;
                else throw invalid_argument("Invalid repair status");

                Pipes[i] = pipe(name, stoi(pipeLength), stoi(pipeDiameter), repair);
                i++;
            }
            else if (line == "=CS=") {
                if (!getline(in, name) || !getline(in, workSt) || !getline(in, numInWork) || !getline(in, eff)) {
                    throw invalid_argument("Error reading cs data");
                }
                if (stoi(workSt) > stoi(numInWork)) {
                    throw invalid_argument("workshops in operation cannot exceed total workshops");
                }
                if (stoi(eff) <= 0 || stoi(eff) > 100) {
                    throw invalid_argument("Efficiency must be in range (0, 100]");
                }

                Css[j] = cs(name, stoi(workSt), stoi(numInWork), stoi(eff));
                j++;
            }
            else {
                cout << "Unknown section: " << line << endl;
            }
        }
        catch (const exception& e) {
            cout << "\nReading error: " << e.what() << endl << endl;
            break;
        }
    }
    in.close();

    showPipes();
    showCss();
}


void save(int& i, int& j)
{
	string input;
}
