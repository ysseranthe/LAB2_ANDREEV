#pragma once

void upload(int& i, int& j);
void save();
extern ofstream logFile;

void initLog(const std::string& logFileName);
void logMessage(const std::string& message);
void closeLog();