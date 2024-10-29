#include "pipe.h"
#pragma once

map<int, pipe> Pipes;

pipe::pipe()
{
    name = "Name";
    length = 1;
    diameter = 1;
    repair = true;
}

pipe::pipe(string n, int l, int d, bool r)
{
	name = n;
	length = l;
	diameter = d;
	repair = r;
}

string pipe::getPipeName() const
{
	return name;
}

void pipe::setName(string input)
{
	name = input;
}

void pipe::setLength(int input)
{
	length = input;
}

void pipe::setDiameter(int input)
{
	diameter = input;
}
 
int pipe::getPipeLength() const
{
	return length;
}

int pipe::getPipeDiameter() const
{
	return diameter;
}

bool pipe::isRepairing() const
{
	return repair;
}

void pipe::setIsRepairing(bool t)
{
	repair = t;
}

bool isInteger(string const& str) {
	istringstream iss(str);
	int num;
	return (iss >> num) && iss.eof();
}

void addNewPipe(int i)
{	
	string inputName, inputLength, inputDiameter, inputRepair;
    int length, diameter;
    bool repair;
 	//pipe newPipe;
    //Pipes[i] = pipe()
    cout << "Enter the name of the pipe:" << endl;
    getline(cin, inputName);

    cout << "Enter the length:" << endl;
    while (true) {
        getline(cin, inputLength);
        if (isInteger(inputLength) && stoi(inputLength) > 0) {
            length = stoi(inputLength);
            break;
        }
        else {
            cout << "Enter a positive number" << endl;
        }
    }

    cout << "Enter the diameter:" << endl;
    while (true) {
        getline(cin, inputDiameter);
        if (isInteger(inputDiameter) && stoi(inputDiameter) > 0) {
            diameter = stoi(inputDiameter);
            break;
        }
        else {
            cout << "Enter a positive number" << endl;
        }
    }

    cout << "Is the pipe under repair?(y/n):" << endl;
    while (true) {
        getline(cin, inputRepair);
        if (inputRepair == "y") {
            repair = true;
            break;
        }
        else if (inputRepair == "n") {
            repair = false;
            break;
        }
        else {
            cout << "(y/n)" << endl;
        }
    }
    Pipes[i] = pipe(inputName, length, diameter, repair);
}

void showPipes() {
    for (const auto& item : Pipes) {
        int id = item.first;
        const pipe p = item.second;

        cout << "Pipe ID: " << id << endl;
        cout << "Name: " << p.getPipeName() << endl;
        cout << "Length: " << p.getPipeLength() << endl;
        cout << "Diameter: " << p.getPipeDiameter() << endl;
        cout << "Repair status: " << (p.isRepairing() ? "Yes" : "No") << endl;
        cout << "-------------------------" << endl;
    }
}

void editPipe() {
    string choose, inputId, inputStatus;
    if (!Pipes.empty()) {
        cout << "1. Change repair status of a pipe\n2. Delete a pipe\n" << endl;
        getline(cin, choose);

        while (true) {
            if (isInteger(choose) && (stoi(choose) == 1 || stoi(choose) == 2)) {
                if (stoi(choose) == 1) {
                    cout << "Enter pipe ID: " << endl;
                    while (true) {
                        getline(cin, inputId);
                        if (isInteger(inputId) && stoi(inputId) >= 0 && Pipes.find(stoi(inputId)) != Pipes.end()) {
                            cout << "Change the repair status of the pipe?(y/n): " << endl;
                            while (true) {
                                getline(cin, inputStatus);
                                if (inputStatus == "y") {
                                    Pipes[stoi(inputId)].setIsRepairing(!(Pipes[stoi(inputId)].isRepairing()));
                                    break;
                                }
                                else if (inputStatus == "n") {
                                    break;
                                }
                                else {
                                    cout << "(y/n)" << endl;
                                }
                            }
                            break;
                        }
                        else {
                            cout << "The pipe does not exist." << endl;
                        }
                    }
                }
                else {
                    cout << "Enter pipe ID to remove: " << endl;
                    while (true) {
                        getline(cin, inputId);
                        if (isInteger(inputId) && stoi(inputId) >= 0 && Pipes.find(stoi(inputId)) != Pipes.end()) {
                            Pipes.erase(stoi(inputId));
                            break;
                        }
                        else {
                            cout << "The pipe does not exist." << endl;
                        }
                    }
                    break;
                }
            }
            else {
                cout << "(1/2)";
            }
        }
    }
    else {
        cout << "The pipes don't exist." << endl;
    }
}