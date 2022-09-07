#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include "Equipment.h"
#include "Admin.h"
using namespace std;

class FileHandler {
public:
	string** scoutFile(int& scoutCount);
	string** scoutsFile(int& scoutsCount);
	string** scoutersFile(int& scoutersCount);

	string** tentFile(int& tentCount);
	string** stoveFile(int& stoveCount);
	string** lanternFile(int& lanternCount);

	string** readLoanRecord(string** loanRecord2d, int &recordCount);
	bool readLoanRecord(string rightUser);
	void writeLoanRecord(string* arr, int& borrowCount, int noOfBorrow, string rightUser);
	void updateLoanRecord(string rightUser);

	void writecondition(Tent adminTent, Stove adminStove, Lantern adminLantern);
};

#endif