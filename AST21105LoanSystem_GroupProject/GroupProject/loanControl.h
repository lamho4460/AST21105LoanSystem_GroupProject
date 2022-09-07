#ifndef LOANCONTROL_H
#define LOANCONTROL_H

#include <string>
#include <iostream>

using namespace std;

class LoanControl {
public:
	string* lendItem(int typeLimit, int& noOFBorrow);
};

#endif