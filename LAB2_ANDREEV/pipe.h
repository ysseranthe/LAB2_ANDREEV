#include <sstream>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#pragma once

class pipe
{
private:
    string name;
    int length;
    int diameter;
    bool repair;

public:
    pipe();
    pipe(string n, int l, int d, bool r);

    int getPipeLength() const;
    int getPipeDiameter() const;
    bool isRepairing() const;
    string getPipeName() const;

    void setName(string input);
    void setLength(int input);
    void setDiameter(int input);
    void setIsRepairing(bool t);


};

extern map<int, pipe> Pipes;

void showPipes();
void editPipe();
void addNewPipe(int i);
bool isInteger(string const& str);