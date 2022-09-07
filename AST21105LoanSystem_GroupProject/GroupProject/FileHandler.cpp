#include "FileHandler.h"
#include "Equipment.h"

string** FileHandler::scoutFile(int& scoutCount) {
	ifstream myFile("user.txt");
	if (!myFile)
	{
		cout << ("No information was detected") << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	string Information;
	scoutCount = 0;
	string** ScoutArray = 0;
	ScoutArray = new string*[100];
	while (!myFile.eof()) {
		getline(myFile, Information, '|');
		if (Information.substr(0, 3) == "VEN" || Information.substr(0, 3) == "ROV") {
			ScoutArray[scoutCount] = new string[5];
			for (int j = 0; j < 5; j++) {
				if (j == 0)
					ScoutArray[scoutCount][j] = Information;
				else if (j >= 1 && j <= 3) {
					getline(myFile, Information, '|');
					ScoutArray[scoutCount][j] = Information;
				}
				else if (j > 3) {
					getline(myFile, Information);
					ScoutArray[scoutCount][j] = Information;
				}
			}
			scoutCount++;
		}
		else if (Information.substr(0, 3) == "SCT" || Information.substr(0, 3) == "SCM") {
			getline(myFile, Information);
		}
		getline(myFile, Information);
	}
	return ScoutArray;
}

string** FileHandler::scoutsFile(int& scoutsCount) {
	ifstream myFile("user.txt");
	if (!myFile)
	{
		cout << ("No information was detected") << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	string Information;
	scoutsCount = 0;
	string** Scout2Array = 0;
	Scout2Array = new string*[100];
	while (!myFile.eof()) {
		getline(myFile, Information, '|');
		if (Information.substr(0, 3) == "SCT") {
			Scout2Array[scoutsCount] = new string[6];
			for (int j = 0; j < 6; j++) {
				if (j == 0)
					Scout2Array[scoutsCount][j] = Information;
				else if (j >= 1 && j <= 4) {
					getline(myFile, Information, '|');
					Scout2Array[scoutsCount][j] = Information;
				}
				else if (j > 4) {
					getline(myFile, Information);
					Scout2Array[scoutsCount][j] = Information;
				}
			}
			scoutsCount++;
		}
		else if (Information.substr(0, 3) == "VEN" || Information.substr(0, 3) == "ROV") {
			getline(myFile, Information);
		}
		else if (Information.substr(0, 3) == "SCM") {
			getline(myFile, Information);
		}
		getline(myFile, Information);
	}
	return Scout2Array;
}

string** FileHandler::scoutersFile(int& scoutersCount) {
	ifstream myFile("user.txt");
	if (!myFile)
	{
		cout << ("No information was detected") << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	string Information;
	scoutersCount = 0;
	string** ScouterArray = 0;
	ScouterArray = new string*[100];
	while (!myFile.eof()) {
		getline(myFile, Information, '|');
		if (Information.substr(0, 3) == "SCM") {
			ScouterArray[scoutersCount] = new string[6];
			for (int j = 0; j < 6; j++) {
				if (j == 0)
					ScouterArray[scoutersCount][j] = Information;
				else if (j >= 1 && j <= 4) {
					getline(myFile, Information, '|');
					ScouterArray[scoutersCount][j] = Information;
				}
				else if (j > 4) {
					getline(myFile, Information);
					ScouterArray[scoutersCount][j] = Information;
				}
			}
			scoutersCount++;
		}
		else if (Information.substr(0, 3) == "VEN" || Information.substr(0, 3) == "ROV") {
			getline(myFile, Information);
		}
		else if (Information.substr(0, 3) == "SCT") {
			getline(myFile, Information);
		}
		getline(myFile, Information);
	}
	return ScouterArray;
}

string** FileHandler::tentFile(int& tentCount) {
	ifstream myFile("camp_equipment.txt");
	if (!myFile)
	{
		cout << ("No information was detected") << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	string Information;
	tentCount = 0;
	string** TentArray = 0;
	TentArray = new string*[100];
	while (!myFile.eof()) {
		getline(myFile, Information, '|');
		if (Information.substr(0, 1) == "T") {
			TentArray[tentCount] = new string[12];
			for (int j = 0; j < 12; j++) {
				if (j == 0)
					TentArray[tentCount][j] = Information;
				else if (j >= 1 && j <= 10) {
					getline(myFile, Information, '|');
					TentArray[tentCount][j] = Information;
				}
				else if (j > 10) {
					getline(myFile, Information);
					TentArray[tentCount][j] = Information;
				}
			}
			tentCount++;
		}
		else if (Information.substr(0, 1) == "S" || Information.substr(0, 1) == "L") {
			getline(myFile, Information);
		}
		getline(myFile, Information);
	}
	return TentArray;
}

string** FileHandler::stoveFile(int& stoveCount) {
	ifstream myFile("camp_equipment.txt");
	if (!myFile)
	{
		cout << ("No information was detected") << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	string Information;
	stoveCount = 0;
	string** stoveArray = 0;
	stoveArray = new string*[100];
	while (!myFile.eof()) {
		getline(myFile, Information, '|');
		if (Information.substr(0, 1) == "S") {
			stoveArray[stoveCount] = new string[9];
			for (int j = 0; j < 9; j++) {
				if (j == 0)
					stoveArray[stoveCount][j] = Information;
				else if (j >= 1 && j <= 7) {
					getline(myFile, Information, '|');
					stoveArray[stoveCount][j] = Information;
				}
				else if (j > 7) {
					getline(myFile, Information);
					stoveArray[stoveCount][j] = Information;
				}
			}
			stoveCount++;
		}
		else if (Information.substr(0, 1) == "T" || Information.substr(0, 1) == "L") {
			getline(myFile, Information);
		}
		getline(myFile, Information);
	}
	return stoveArray;
}

string** FileHandler::lanternFile(int& lanternCount) {
	ifstream myFile("camp_equipment.txt");
	if (!myFile)
	{
		cout << ("No information was detected") << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	string Information;
	lanternCount = 0;
	string** lanternArray = 0;
	lanternArray = new string*[100];
	while (!myFile.eof()) {
		getline(myFile, Information, '|');
		if (Information.substr(0, 1) == "L") {
			lanternArray[lanternCount] = new string[10];
			for (int j = 0; j < 10; j++) {
				if (j == 0)
					lanternArray[lanternCount][j] = Information;
				else if (j >= 1 && j <= 8) {
					getline(myFile, Information, '|');
					lanternArray[lanternCount][j] = Information;
				}
				else if (j > 8) {
					getline(myFile, Information);
					lanternArray[lanternCount][j] = Information;
				}
			}
			lanternCount++;
		}
		else if (Information.substr(0, 1) == "T" || Information.substr(0, 1) == "S") {
			getline(myFile, Information);
		}
		getline(myFile, Information);
	}
	return lanternArray;
}

string** FileHandler::readLoanRecord(string** loanRecord2d, int &recordCount) {
	ifstream file("loanRecord.txt");
	string data;
	if (!file) {
		ofstream createFile("loanRecord.txt");
		createFile.close();
		cout << "No data now.";
	}

	else {
		cout << "Loan Data: \n";
		cout << "Lent date\tItem code\tItem Name\tUser\tReturn date\tStatus\n";
		while (!file.eof()) {
			getline(file, data, '|');
			loanRecord2d[recordCount] = new string[6];
			for (int i = 0; i < 6; i++) {
				if (i == 0)
					loanRecord2d[recordCount][i] = data;
				else if (i >= 1 && i <= 4) {
					getline(file, data, '|');
					loanRecord2d[recordCount][i] = data;
				}
				else if (i > 4) {
					getline(file, data);
					loanRecord2d[recordCount][i] = data;
				}
			}
			getline(file, data);
			recordCount++;
		}
	}
	return loanRecord2d;
}

bool FileHandler::readLoanRecord(string rightUser) {
	ifstream loanRecord("loanRecord.txt");

	string Information;
	int recordCount = 0;
	string** record2d = 0;
	record2d = new string*[100];
	bool flag = true;
	if (!loanRecord) {
		ofstream createFile("loanRecord.txt");
		createFile.close();
		cout << "No data now.";
	}
	else {
		cout << "Your loan record: " << endl;
		cout << "loan date\titemID\titem name\t\treturn date" << endl;
		while (!loanRecord.eof()) {
			getline(loanRecord, Information, '|');
			record2d[recordCount] = new string[6];
			for (int j = 0; j < 6; j++) {
				if (j == 0)
					record2d[recordCount][j] = Information;
				else if (j >= 1 && j <= 4) {
					getline(loanRecord, Information, '|');
					record2d[recordCount][j] = Information;
				}
				else if (j > 4) {
					getline(loanRecord, Information);
					record2d[recordCount][j] = Information;
				}
			}
			getline(loanRecord, Information);
			recordCount++;
		}
		for (int i = 0; i < recordCount; i++) {
			if (record2d[i][0] == rightUser && record2d[i][5] == "out") {
				for (int j = 1; j < 5; j++) {
					if (j < 3)
						cout << record2d[i][j] << "\t";
					else if (j == 3)
						cout << record2d[i][j] << "\t\t";
					else if (j > 3)
						cout << record2d[i][j] << endl;
				}
				flag = false;
			}
		}
	}
	return flag;
}

void FileHandler::writeLoanRecord(string* arr, int& borrowCount, int noOfBorrow, string rightUser) {
	ifstream loanRecord("loanRecord.txt");
	string Information;
	Tent ten;
	Stove sto;
	Lantern lan;
	if (!loanRecord) {
		ofstream file("loanRecord.txt");
	}
	int dayOfToday, monthOfToday, yearOfToday, x, dayOfReturn, monthOfReturn, yearOfReturn;

	struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	dayOfToday = t.tm_mday;
	monthOfToday = t.tm_mon + 1;
	yearOfToday = t.tm_year + 1900;

	int MaxDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//leap year
	if ((yearOfToday % 4 == 0 && yearOfToday % 100 != 0) || (yearOfToday % 4 == 0 && yearOfToday % 100 == 0 && yearOfToday % 400 == 0))
		MaxDays[1] = 29;
	x = monthOfToday - 1;

	dayOfReturn = dayOfToday + 14, monthOfReturn = monthOfToday, yearOfReturn = yearOfToday; //Usually

	if (dayOfToday + 14 > MaxDays[x]) {
		dayOfReturn = dayOfToday + 14 - MaxDays[x], monthOfReturn = monthOfToday + 1;
		if (monthOfToday == 12) {
			yearOfReturn = yearOfToday + 1;
			monthOfReturn = 1;
		}
	}
	string date, day, month;
	string newDate, newDay, newMonth;
	if (dayOfToday > 0 && dayOfToday < 10)
		day = "0" + to_string(dayOfToday);
	else
		day = to_string(dayOfToday);
	if (monthOfToday > 0 && monthOfToday < 10)
		month = "0" + to_string(monthOfToday);
	else
		month = to_string(monthOfToday);
	if (dayOfReturn > 0 && dayOfReturn < 10)
		newDay = "0" + to_string(dayOfReturn);
	else
		newDay = to_string(dayOfReturn);
	if (monthOfReturn > 0 && monthOfReturn < 10)
		newMonth = "0" + to_string(monthOfReturn);
	else
		newMonth = to_string(monthOfReturn);
	date = day + "/" + month + "/" + to_string(yearOfToday);
	newDate = newDay + "/" + newMonth + "/" + to_string(yearOfReturn);





	borrowCount = 0;
	string** borrowArray = 0;
	borrowArray = new string*[100];
	while (!loanRecord.eof()) {
		getline(loanRecord, Information, '|');
		borrowArray[borrowCount] = new string[6];
		for (int j = 0; j < 6; j++) {
			if (j < 1)
				borrowArray[borrowCount][j] = Information;
			else if (j < 5) {
				getline(loanRecord, Information, '|');
				borrowArray[borrowCount][j] = Information;
			}
			else {
				getline(loanRecord, Information);
				borrowArray[borrowCount][j] = Information;
			}
		}
		borrowCount++;
		getline(loanRecord, Information);
	}
	for (int i = 0; i < noOfBorrow; i++) {
		borrowArray[borrowCount] = new string[6];
		borrowArray[borrowCount][0] = rightUser;
		borrowArray[borrowCount][1] = date;
		borrowArray[borrowCount][2] = arr[i];
		if (arr[i].substr(0, 1) == "T") {
			for (int k = 0; k < ten.getTentCount(); k++) {
				if (arr[i] == ten.getTent()[k][0]) {
					borrowArray[borrowCount][3] = ten.getTent()[k][1];
					ten.getTent()[k][6] = "out";
				}
			}
		}
		else if (arr[i].substr(0, 1) == "S") {
			for (int k = 0; k < sto.getStoveCount(); k++) {
				if (arr[i] == sto.getStove()[k][0]) {
					borrowArray[borrowCount][3] = sto.getStove()[k][1];
					sto.getStove()[k][6] = "out";
				}
			}
		}
		else if (arr[i].substr(0, 1) == "L") {
			for (int k = 0; k < lan.getLanternCount(); k++) {
				if (arr[i] == lan.getLantern()[k][0]) {
					borrowArray[borrowCount][3] = lan.getLantern()[k][1];
					lan.getLantern()[k][6] = "out";
				}
			}
		}
		borrowArray[borrowCount][4] = newDate;
		borrowArray[borrowCount][5] = "out";
		borrowCount++;
	}
	loanRecord.open("loanRecord.txt", ofstream::out | ofstream::trunc);
	loanRecord.close();
	ofstream newLoanRecord("loanRecord.txt");
	if (newLoanRecord.is_open())
	{
		for (int i = 1; i < borrowCount; i++) {
			if (i < borrowCount - 1) {
				for (int j = 0; j < 6; j++) {
					if (j != 5)
						newLoanRecord << borrowArray[i][j] << "|";
					else
						newLoanRecord << borrowArray[i][j];
				}
				newLoanRecord << "\n\n";
			}
			else if (i == borrowCount - 1) {
				for (int j = 0; j < 6; j++) {
					if (j != 5)
						newLoanRecord << borrowArray[i][j] << "|";
					else
						newLoanRecord << borrowArray[i][j];
				}
			}
		}
		newLoanRecord.close();
	}
	else
		cout << "Unable to open file";
	ifstream equipment;
	equipment.open("camp_equipment.txt", ofstream::out | ofstream::trunc);
	equipment.close();
	ofstream newEquipment("camp_equipment.txt");
	if (newEquipment.is_open())
	{
		for (int i = 0; i < ten.getTentCount(); i++) {
			for (int j = 0; j < 12; j++) {
				if (j != 11)
					newEquipment << ten.getTent()[i][j] << "|";
				else
					newEquipment << ten.getTent()[i][j];
			}
			newEquipment << "\n\n";
		}
		for (int i = 0; i < sto.getStoveCount(); i++) {
			for (int j = 0; j < 9; j++) {
				if (j != 8)
					newEquipment << sto.getStove()[i][j] << "|";
				else
					newEquipment << sto.getStove()[i][j];
			}
			newEquipment << "\n\n";
		}
		for (int i = 0; i < lan.getLanternCount(); i++) {
			for (int j = 0; j < 10; j++) {
				if (j != 9)
					newEquipment << lan.getLantern()[i][j] << "|";
				else
					newEquipment << lan.getLantern()[i][j];
			}
			newEquipment << "\n\n";
		}
		newEquipment.close();
	}
	else
		cout << "Unable to open file";
	for (int i = 0; i < borrowCount; i++) {
		delete[] borrowArray[i];
	}
	delete[] borrowArray;
	borrowArray = 0;
}

void FileHandler::updateLoanRecord(string rightUser) {
	ifstream loanRecord("loanRecord.txt");
	string Information;
	string update;
	int recordCount = 0;
	string** record2d = 0;
	record2d = new string*[100];
	bool flag = true;
	if (!loanRecord) {
		cout << "There are no any records." << endl;
	}
	else {
		cout << "Your loan record: " << endl;
		cout << "loan date\titemID\titem name\t\treturn date" << endl;
		while (!loanRecord.eof()) {
			getline(loanRecord, Information, '|');
			record2d[recordCount] = new string[6];
			for (int j = 0; j < 6; j++) {
				if (j == 0)
					record2d[recordCount][j] = Information;
				else if (j >= 1 && j <= 4) {
					getline(loanRecord, Information, '|');
					record2d[recordCount][j] = Information;
				}
				else if (j > 4) {
					getline(loanRecord, Information);
					record2d[recordCount][j] = Information;
				}
			}
			getline(loanRecord, Information);
			recordCount++;
		}
		for (int i = 0; i < recordCount; i++) {
			if (record2d[i][0] == rightUser && record2d[i][5] == "out") {
				for (int j = 1; j < 5; j++) {
					if (j < 3)
						cout << record2d[i][j] << "\t";
					else if (j == 3)
						cout << record2d[i][j] << "\t\t";
					else if (j > 3)
						cout << record2d[i][j] << endl;
				}
			}
		}
		cout << endl;
		cout << "Which item you would like to return? ";
		cin >> update;
		for (int i = 0; i < recordCount; i++) {
			if (record2d[i][0] == rightUser && record2d[i][5] == "out" && update == record2d[i][2]) {
				record2d[i][5] = "returned";
				flag = true;
				break;
			}
			else
				flag = false;
		}
		if (flag == true) {
			loanRecord.open("loanRecord.txt", ofstream::out | ofstream::trunc);
			loanRecord.close();
			ofstream newLoanRecord("loanRecord.txt");
			if (newLoanRecord.is_open())
			{
				for (int i = 0; i < recordCount; i++) {
					if (i < recordCount - 1) {
						for (int j = 0; j < 6; j++) {
							if (j != 5)
								newLoanRecord << record2d[i][j] << "|";
							else
								newLoanRecord << record2d[i][j];
						}
						newLoanRecord << "\n\n";
					}
					else if (i == recordCount - 1) {
						for (int j = 0; j < 6; j++) {
							if (j != 5)
								newLoanRecord << record2d[i][j] << "|";
							else
								newLoanRecord << record2d[i][j];
						}
					}
				}
				newLoanRecord.close();
			}
			Tent ten;
			Stove sto;
			Lantern lan;
			for (int i = 0; i < ten.getTentCount(); i++) {
				if (update == ten.getTent()[i][0]) {
					ten.getTent()[i][6] = "in";
				}
			}
			for (int i = 0; i < sto.getStoveCount(); i++) {
				if (update == sto.getStove()[i][0]) {
					sto.getStove()[i][6] = "in";
				}
			}
			for (int i = 0; i < lan.getLanternCount(); i++) {
				if (update == lan.getLantern()[i][0]) {
					lan.getLantern()[i][6] = "in";
				}
			}
			ifstream equipment;
			equipment.open("camp_equipment.txt", ofstream::out | ofstream::trunc);
			equipment.close();
			ofstream newEquipment("camp_equipment.txt");
			if (newEquipment.is_open())
			{
				for (int i = 0; i < ten.getTentCount(); i++) {
					for (int j = 0; j < 12; j++) {
						if (j != 11)
							newEquipment << ten.getTent()[i][j] << "|";
						else
							newEquipment << ten.getTent()[i][j];
					}
					newEquipment << "\n\n";
				}
				for (int i = 0; i < sto.getStoveCount(); i++) {
					for (int j = 0; j < 9; j++) {
						if (j != 8)
							newEquipment << sto.getStove()[i][j] << "|";
						else
							newEquipment << sto.getStove()[i][j];
					}
					newEquipment << "\n\n";
				}
				for (int i = 0; i < lan.getLanternCount(); i++) {
					for (int j = 0; j < 10; j++) {
						if (j != 9)
							newEquipment << lan.getLantern()[i][j] << "|";
						else
							newEquipment << lan.getLantern()[i][j];
					}
					newEquipment << "\n\n";
				}
				newEquipment.close();
			}
			cout << "Return Success!" << endl;
		}
		else
			cout << "No this item!" << endl;
		for (int i = 0; i < recordCount; i++) {
			delete[] record2d[i];
		}
		delete[] record2d;
		record2d = 0;
	}
}

void FileHandler::writecondition(Tent adminTent, Stove adminStove, Lantern adminLantern) {
	system("pause");
	ofstream file;
	file.open("camp_equipment.txt", ofstream::trunc);
	file.close();
	file.open("camp_equipment.txt", ofstream::out);
	if (file.is_open()) {
		for (int i = 0; i < adminTent.getTentCount(); i++) {
			for (int j = 0; j < 12; j++) {
				file << adminTent.getTent()[i][j];
				if (j < 11) {
					file << "|";
				}
			}
			file << "\n\n";
		}
		for (int i = 0; i < adminStove.getStoveCount(); i++) {
			for (int j = 0; j < 9; j++) {
				file << adminStove.getStove()[i][j];
				if (j < 8) {
					file << "|";
				}
			}
			file << "\n\n";
		}
		for (int i = 0; i < adminLantern.getLanternCount(); i++) {
			for (int j = 0; j < 10; j++) {
				file << adminLantern.getLantern()[i][j];
				if (j < 9) {
					file << "|";
				}
			}
			file << "\n\n";
		}
		file.close();
	}
	else
		cout << "File was open!";
}