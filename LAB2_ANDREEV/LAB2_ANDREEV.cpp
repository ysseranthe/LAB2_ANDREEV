#include <iostream>
#include <fstream>
#include "pipe.h"
#include "cs.h"
using namespace std;

int main() {
    int i = 0;
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
                addNewPipe(i);
                break;
            }
            case 2: {
                //addNewCs(i);
                break;
            }
            case 3: {
                showPipes();
                //showCss();
                break;
            }
            case 4: {
                filterPipe();
                break;
            }
            case 5: {
                //filterCs();
                break;
            }
            case 6: {
                editPipe();
                //cout << "Save" << endl;
                //save(Pipe, Cs, pipeExists, csExists);
                break;
            }
            case 7: {
                //editCs();
                break;
            }
            case 8: {
                //cout << "Load" << endl;
                //load(Pipe, Cs, pipeExists, csExists);
                break;
            }
            case 9: {
                //cout << "Load" << endl;
                //load(Pipe, Cs, pipeExists, csExists);
                break;
            }
            default: {
                cout << "Enter number from 0 to 7." << endl;
                break;
            }
            }
        }
        else {
            cout << "Enter number from 0 to 7." << endl;
        }
        cout << endl;
    }
}
