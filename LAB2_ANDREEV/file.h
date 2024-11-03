#pragma once

void upload(int& i, int& j);
void save();
extern ofstream logFile;
void initLog(const string& logFileName);
void logMessage(const string& message);
void closeLog();
bool isInteger(string const& str);
