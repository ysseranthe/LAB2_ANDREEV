#include <iostream>
#include <fstream>
#include "pipe.h"
#include "cs.h"
#include "file.h"
using namespace std;

int main() {
    int pipeId = 0, csId = 0;
    string input;

    while (true) {
        cout << "1. Add a pipe\n2. Add CS\n3. View all objects\n4. Find a pipe\n5. Find a CS\n6. Edit a pipe\n7. Edit a CS\n8. Save\n9. Upload\n0. Exit\n" << endl;
        getline(cin, input);
        if (isInteger(input)) {
            int choose;
            choose = stoi(input);
            switch (choose) {
            case 0: {
                return 0;
            }
            case 1: {
                addNewPipe(pipeId);
                break;
            }
            case 2: {
                addNewCs(csId);
                break;
            }
            case 3: {
                showPipes();
                showCss();
                break;
            }
            case 4: {
                filterPipe();
                break;
            }
            case 5: {
                filterCs();
                break;
            }
            case 6: {
                editPipe();
                break;
            }
            case 7: {
                editCs();
                break;
            }
            case 8: {
                //load(Pipe, Cs, pipeExists, csExists);
                break;
            }
            case 9: {
                upload(pipeId, csId);
                break;
            }
            default: {
                cout << "Enter number from 0 to 9." << endl;
                break;
            }
            }
        }
        else {
            cout << "Enter number from 0 to 9." << endl;
        }
        cout << endl;
    }
}
