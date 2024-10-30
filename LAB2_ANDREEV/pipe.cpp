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

void filterPipe()
{
    string choose, input;
    if (Pipes.empty()) {
        cout << "There are no pipes." << endl;
    }
    else {
        cout << "1. Filtration by name\n2. Filtration by repair status\n" << endl;

        while (true) {
            getline(cin, choose);

            if (isInteger(choose) && (stoi(choose) == 1 || stoi(choose) == 2)) {

                if (stoi(choose) == 1) {
                    cout << "Enter the text: " << endl;
                    getline(cin, input);

                    for (const auto& item : Pipes) {
                        int id = item.first;
                        const pipe p = item.second;

                        if (Pipes[id].getPipeName().find(input) != string::npos) {
                            pipeInfo(id, p);
                        }
                    }
                    break;
                }

                else {
                    cout << "Is a pipe being repaired?? (y/n):" << endl;
                    while (true) {
                        getline(cin, input);
                        if (input == "y") {
                            for (const auto& item : Pipes) {
                                int id = item.first;
                                const pipe p = item.second;
                                if (Pipes[id].isRepairing() == true) {
                                    pipeInfo(id, p);
                                }
                            }
                            break;
                        }
                        else if (input == "n") {
                            for (const auto& item : Pipes) {
                                int id = item.first;
                                const pipe p = item.second;
                                if (Pipes[id].isRepairing() == false) {
                                    pipeInfo(id, p);
                                }
                            }
                            break;
                        }
                        else {
                            cout << "(y/n)" << endl;
                        }
                    }
                    break;
                }
            }
            else {
                cout << "Enter 1 or 2." << endl;
            }
        }
    }
}

void addNewPipe(int& i)
{	
	string inputName, input;
    int length, diameter;
    bool repair;
 	//pipe newPipe;
    //Pipes[i] = pipe()
    cout << "Enter the name of the pipe:" << endl;
    getline(cin, inputName);

    cout << "Enter the length:" << endl;
    while (true) {
        getline(cin, input);
        if (isInteger(input) && stoi(input) > 0) {
            length = stoi(input);
            break;
        }
        else {
            cout << "Enter a positive number" << endl;
        }
    }

    cout << "Enter the diameter:" << endl;
    while (true) {
        getline(cin, input);
        if (isInteger(input) && stoi(input) > 0) {
            diameter = stoi(input);
            break;
        }
        else {
            cout << "Enter a positive number" << endl;
        }
    }

    cout << "Is the pipe under repair?(y/n):" << endl;
    while (true) {
        getline(cin, input);
        if (input == "y") {
            repair = true;
            break;
        }
        else if (input == "n") {
            repair = false;
            break;
        }
        else {
            cout << "(y/n)" << endl;
        }
    }
    Pipes[i] = pipe(inputName, length, diameter, repair);
    i++;
}

void showPipes() {
    if (Pipes.empty()) {
        cout << "There are no pipes." << endl;
    }
    for (const auto& item : Pipes) {
        int id = item.first;
        const pipe p = item.second;
        pipeInfo(id, p);
    }
}

void pipeInfo(int id, const pipe p) {
    cout << "Pipe ID: " << id << endl;
    cout << "Name: " << p.getPipeName() << endl;
    cout << "Length: " << p.getPipeLength() << endl;
    cout << "Diameter: " << p.getPipeDiameter() << endl;
    cout << "Repair status: " << (p.isRepairing() ? "Yes" : "No") << endl;
    cout << "-------------------------" << endl;
}

void editPipe() {
    string choose, input;
    if (!Pipes.empty()) {
        cout << "1. Change repair status of a pipe\n2. Delete a pipe\n" << endl;

        while (true) {
            getline(cin, choose);
            if (isInteger(choose) && (stoi(choose) == 1 || stoi(choose) == 2)) {
                if (stoi(choose) == 1) {
                    cout << "Enter pipe ID: " << endl;
                    while (true) {
                        getline(cin, input);
                        if (isInteger(input) && stoi(input) >= 0 && Pipes.find(stoi(input)) != Pipes.end()) {
                            cout << "Change the repair status of the pipe?(y/n): " << endl;
                            while (true) {
                                getline(cin, input);
                                if (input == "y") {
                                    Pipes[stoi(input)].setIsRepairing(!(Pipes[stoi(input)].isRepairing()));
                                    break;
                                }
                                else if (input == "n") {
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
                    break;
                }
                else {
                    cout << "Enter pipe ID to remove: " << endl;
                    while (true) {
                        getline(cin, input);
                        if (isInteger(input) && stoi(input) >= 0 && Pipes.find(stoi(input)) != Pipes.end()) {
                            Pipes.erase(stoi(input));
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
                cout << "Enter 1 or 2." << endl;
            }
        }
    }
    else {
        cout << "The pipes don't exist." << endl;
    }
}