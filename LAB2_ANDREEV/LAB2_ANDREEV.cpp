#include <iostream>
#include <fstream>
#include "pipe.h"
#include "cs.h"
using namespace std;

int main() {
    int i = 0;
    string input;
    //map<int, cs> Css;
    bool pipeExists = false;
    bool csExists = false;

    while (true) {
        cout << "1. Add a pipe\n2. Add CS\n3. View all objects\n4. Edit the pipe\n5. Edit the CS\n6. Save\n7. Upload\n0. Exit\n" << endl;
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
                //cout << "Add a pipe\n" << endl;
                //Pipe = createPipe(pipeExists, Pipe);
                i++;
                break;
            }
            case 2: {
                //cout << "Add a CS" << endl;
                //Cs = createCs(csExists, Cs);
                break;
            }
            case 3: {
                showPipes();
                //showCs(Cs, csExists);
                break;
            }
            case 4: {
                editPipe();
                //editPipe(Pipe, pipeExists);
                break;
            }
            case 5: {
                //cout << "Edit the compressor station" << endl;
                //editCs(Cs, csExists);
                break;
            }
            case 6: {
                //cout << "Save" << endl;
                //save(Pipe, Cs, pipeExists, csExists);
                break;
            }
            case 7: {
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
