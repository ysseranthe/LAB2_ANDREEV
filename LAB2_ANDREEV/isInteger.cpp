#include "isInteger.h"

bool isInteger(string const& str) {
	istringstream iss(str);
	int num;
	return (iss >> num) && iss.eof();
}