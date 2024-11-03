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

string filterByName(string input) {
    string foundId;

    for (const auto& item : Pipes) {
        int id = item.first;
        const pipe p = item.second;

        if (Pipes[id].getPipeName().find(input) != string::npos) {
            pipeInfo(id, p);
            foundId += to_string(id) + " ";
        }
    }
    return foundId;
}

string filterByRepair(string input) {
    string foundId;
    for (const auto& item : Pipes) {
        int id = item.first;
        const pipe p = item.second;
        if (Pipes[id].isRepairing() == (input == "y" ? true : false)) {
            pipeInfo(id, p);
            foundId += to_string(id) + " ";
        }
    }
    return foundId;
}

void filterPipe() {
    string choose, input, foundId, inputId;
    if (Pipes.empty()) {
        cout << "There are no pipes." << endl;
    }
    else {
        while (true) {
            cout << "1. Filtration by name\n2. Filtration by repair status\n" << endl;
            getline(cin, choose);

            if (isInteger(choose) && (stoi(choose) == 1 || stoi(choose) == 2)) {
                if (stoi(choose) == 1) {
                    cout << "Enter the text:" << endl;
                    getline(cin, input);
                    foundId = filterByName(input);
                }
                else {
                    while (true) {
                        cout << "Enter the repair status of the pipe (y/n):" << endl;
                        getline(cin, input);
                        if (input == "y" || input == "n") {
                            foundId = filterByRepair(input);
                            break;
                        }
                        else {
                            cout << "(y/n)" << endl;
                        }
                    }
                }
                cout << "1. Edit repair status." << endl << "2. Delete." << endl << "Any other key to exit" << endl;
                getline(cin, choose);
                if (isInteger(choose) && (stoi(choose) == 1 || stoi(choose) == 2)) {
                    if (stoi(choose) == 1) {
                        cout << "Enter the pipe(s) id by space or nothing to select the found ones:" << endl;
                        getline(cin, input);
                        istringstream iss(input.empty() ? foundId : input);
                        while (iss >> inputId) {
                            if (isInteger(inputId) && Pipes.find(stoi(inputId)) != Pipes.end()) {
                                Pipes[stoi(inputId)].setIsRepairing(!(Pipes[stoi(inputId)].isRepairing()));
                            }
                            else {
                                cout << "Skipped invalid input: " << inputId << endl;
                            }
                        }
                        break;
                    }
                    else if (stoi(choose) == 2) {
                        cout << "Enter the pipe(s) id by space or nothing to select the found ones:" << endl;
                        getline(cin, input);
                        istringstream iss(input.empty() ? foundId : input);
                        while (iss >> inputId) {
                            if (isInteger(inputId) && Pipes.find(stoi(inputId)) != Pipes.end()) {
                                Pipes.erase(stoi(inputId));
                            }
                            else {
                                cout << "Skipped invalid input: " << inputId << endl;
                            }
                        }
                        break;
                    }
                }
                else {
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
    cout << "Being repaired: " << (p.isRepairing() ? "Yes" : "No") << endl;
    cout << "-------------------------" << endl;
}

void editPipe() {
    string choose, inputId, input;
    if (Pipes.empty()) {
        cout << "There are no pipes." << endl;
    }
    else {
        while (true) {
            cout << "1. Change repair status of a pipe\n2. Delete a pipe\n" << endl;
            getline(cin, choose);
            if (isInteger(choose) && (stoi(choose) == 1 || stoi(choose) == 2)) {
                if (stoi(choose) == 1) {
                    cout << "Enter the pipe(s) by space:" << endl;
                    getline(cin, input);
                    istringstream iss(input);
                    while (iss >> inputId) {
                        if (isInteger(inputId) && Pipes.find(stoi(inputId)) != Pipes.end()) {
                            Pipes[stoi(inputId)].setIsRepairing(!(Pipes[stoi(inputId)].isRepairing()));
                        }
                        else {
                            cout << "Skipped invalid input: " << inputId << endl;
                        }
                    }
                }
                else {
                    cout << "Enter the pipe(s) by space:" << endl;
                    getline(cin, input);
                    istringstream iss(input);
                    while (iss >> inputId) {
                        if (isInteger(inputId) && Pipes.find(stoi(inputId)) != Pipes.end()) {
                            Pipes.erase(stoi(inputId));
                        }
                        else {
                            cout << "Skipped invalid input: " << inputId << endl;
                        }
                    }
                }
                break;
            }
            else {
                cout << "Enter 1 or 2." << endl;
            }
        }
    }
}