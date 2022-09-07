#include "User.h"
#include "FileHandler.h"
#include "Equipment.h"
#include "LoanControl.h"

// User
void User::setUserID(string userID) {
	this->userID = userID;
}

void User::setName(string name) {
	this->name = name;
}

void User::setSection(string section) {
	this->section = section;
}

void User::setBirth(string birth) {
	this->birth = birth;
}

void User::setAddress(string address) {
	this->address = address;
}

string User::getUserID() {
	return userID;
}

string User::getName() {
	return name;
}

string User::getSection() {
	return section;
}

string User::getBirth() {
	return birth;
}

string User::getAddress() {
	return address;
}

// Scout
void Scout::setScout(string** scout) {
	this->scout = scout;
}

void Scout::setScoutCount(int scoutCount) {
	this->scoutCount = scoutCount;
}

string** Scout::getScout() {
	setAll();
	return scout;
}

int Scout::getScoutCount() {
	setAll();
	return scoutCount;
}

void Scout::setAll() {
	int scoutCount;
	FileHandler f;
	string** scout = f.scoutFile(scoutCount);
	Scout sct[100];
	for (int i = 0; i < scoutCount; i++) {
		sct[i].setUserID(scout[i][0]);
		sct[i].setName(scout[i][1]);
		sct[i].setSection(scout[i][2]);
		sct[i].setBirth(scout[i][3]);
		sct[i].setAddress(scout[i][4]);
	}
	setScout(scout);
	setScoutCount(scoutCount);
}

void Scout::scoutMenu(string rightUser) {
	for (;;) {
		system("cls");
		int action = 0;
		Tent ten;
		Stove sto;
		Lantern lan;
		cout << "1) Displaying camp equipment.\n";
		cout << "2) Return.\n";
		cout << "3) Loaning equipment. \n";
		cout << "4) Displaying loan record.\n";
		cout << "5) Exit.\n\n";
		cout << "Enter the number(1 - 5): ";
		cin >> action;

		if (action == 1) {
			system("cls");
			for (int i = 0; i < ten.getTentCount(); i++) {
				if (ten.getTent()[i][5] == "good" && ten.getTent()[i][6] == "in") {
					for (int j = 0; j < 12; j++) {
						cout << ten.getTent()[i][j] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
			for (int i = 0; i < sto.getStoveCount(); i++) {
				if (sto.getStove()[i][5] == "good" && sto.getStove()[i][6] == "in") {
					for (int j = 0; j < 9; j++) {
						cout << sto.getStove()[i][j] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
			for (int i = 0; i < lan.getLanternCount(); i++) {
				if (lan.getLantern()[i][5] == "good" && lan.getLantern()[i][6] == "in") {
					for (int j = 0; j < 10; j++) {
						cout << lan.getLantern()[i][j] << " ";
					}
					cout << endl;
				}
			}
			system("pause");
		}
		else if (action == 4) {
			system("cls");
			FileHandler f;
			f.readLoanRecord(rightUser);
			system("pause");
		}
		else if (action == 3) {
			system("cls");
			int typeLimit;
			FileHandler f;
			bool flag = f.readLoanRecord(rightUser);
			if (flag == true) {
				system("cls");
				string type;
				if (rightUser.substr(0, 3) == "VEN" || rightUser.substr(0, 3) == "ROV") {
					for (int i = 0; i < scoutCount; i++) {
						if (rightUser == scout[i][0]) {
							type = scout[i][2];
							break;
						}
					}
				}
				if (type == "Venture Scout") {
					cout << "You can borrow at most 3 item." << endl;
					typeLimit = 3;
				}
				else if (type == "Rover Scout") {
					cout << "You can borrow at most 5 item." << endl;
					typeLimit = 5;
				}
				int noOfBorrow;
				LoanControl l;
				string *arr = l.lendItem(typeLimit, noOfBorrow);
				int borrowCount;
				f.writeLoanRecord(arr, borrowCount, noOfBorrow, rightUser);

				delete[] arr;
				arr = 0;
			}
			else {
				cout << "You are not allow to lend.Please check your load record." << endl;
				cout << "Maybe your lending limit reached" << endl;
				cout << "Please require admin upgrade your permission or return the equipment first." << endl;
			}
			system("pause");
		}
		else if (action == 2) {
			system("cls");
			FileHandler f;
			f.updateLoanRecord(rightUser);
			system("pause");
		}
		else if (action == 5) {
			cout << "Login out succeed." << endl;
			cout << "Welcome for next time." << endl;
			system("pause");
			break;
		}
		else if (action != 1 && action != 2 && action != 3 && action != 4 && action != 5) {
			cout << "Please login again if you want to use this system." << endl;
			system("pause");
			break;
		}
	}
}

void Scout::deleteAll() {
	for (int i = 0; i < scoutCount; i++) {
		delete[] scout[i];
	}
	delete[] scout;
	scout = 0;
}

// Scouts
void Scouts::setRank(string rank) {
	this->rank = rank;
}

void Scouts::setScouts(string** scouts) {
	this->scouts = scouts;
}

void Scouts::setScoutsCount(int scoutsCount) {
	this->scoutsCount = scoutsCount;
}

string Scouts::getRank() {
	return rank;
}

string** Scouts::getScouts() {
	setAll();
	return scouts;
}

int Scouts::getScoutsCount() {
	setAll();
	return scoutsCount;
}

void Scouts::setAll() {
	int scoutsCount;
	FileHandler f;
	string** scouts = f.scoutsFile(scoutsCount);
	Scouts scts[100];
	for (int i = 0; i < scoutsCount; i++) {
		scts[i].setUserID(scouts[i][0]);
		scts[i].setName(scouts[i][1]);
		scts[i].setSection(scouts[i][2]);
		scts[i].setBirth(scouts[i][3]);
		scts[i].setAddress(scouts[i][4]);
		scts[i].setRank(scouts[i][5]);
	}
	setScouts(scouts);
	setScoutsCount(scoutsCount);
}

void Scouts::scoutsMenu(string rightUser) {
	for (;;) {
		system("cls");
		int action = 0;
		Tent ten;
		Stove sto;
		Lantern lan;
		cout << "1) Displaying camp equipment.\n";
		cout << "2) Return.\n";
		cout << "3) Loaning equipment. \n";
		cout << "4) Displaying loan record.\n";
		cout << "5) Exit.\n\n";
		cout << "Enter the number(1 - 5): ";
		cin >> action;

		if (action == 1) {
			system("cls");
			for (int i = 0; i < ten.getTentCount(); i++) {
				if (ten.getTent()[i][5] == "good" && ten.getTent()[i][6] == "in") {
					for (int j = 0; j < 12; j++) {
						cout << ten.getTent()[i][j] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
			for (int i = 0; i < sto.getStoveCount(); i++) {
				if (sto.getStove()[i][5] == "good" && sto.getStove()[i][6] == "in") {
					for (int j = 0; j < 9; j++) {
						cout << sto.getStove()[i][j] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
			for (int i = 0; i < lan.getLanternCount(); i++) {
				if (lan.getLantern()[i][5] == "good" && lan.getLantern()[i][6] == "in") {
					for (int j = 0; j < 10; j++) {
						cout << lan.getLantern()[i][j] << " ";
					}
					cout << endl;
				}
			}
			system("pause");
		}
		else if (action == 4) {
			system("cls");
			FileHandler f;
			f.readLoanRecord(rightUser);
			system("pause");
		}
		else if (action == 3) {
			system("cls");
			int typeLimit;
			FileHandler f;
			bool flag = f.readLoanRecord(rightUser);
			if (flag == true) {
				system("cls");
				string type;
				if (rightUser.substr(0, 3) == "SCT") {
					for (int i = 0; i < scoutsCount; i++) {
						if (rightUser == scouts[i][0]) {
							type = scouts[i][5];
							break;
						}
					}
				}
				if (type == "Member") {
					cout << "You can borrow at most 1 item." << endl;
					typeLimit = 1;
				}
				else if (type == "Patrol Leader" || type == "Assistant Patrol Leader") {
					cout << "You can borrow at most 3 item." << endl;
					typeLimit = 3;
				}
				int noOfBorrow;
				LoanControl l;
				string *arr = l.lendItem(typeLimit, noOfBorrow);
				int borrowCount;
				f.writeLoanRecord(arr, borrowCount, noOfBorrow, rightUser);

				delete[] arr;
				arr = 0;
			}
			else {
				cout << "You are not allow to lend.Please check your load record." << endl;
				cout << "Maybe your lending limit reached" << endl;
				cout << "Please require admin upgrade your permission or return the equipment first." << endl;
			}
			system("pause");
		}
		else if (action == 2) {
			system("cls");
			FileHandler f;
			f.updateLoanRecord(rightUser);
			system("pause");
		}
		else if (action == 5) {
			cout << "Login out succeed." << endl;
			cout << "Welcome for next time." << endl;
			system("pause");
			break;
		}
		else if (action != 1 && action != 2 && action != 3 && action != 4 && action != 5) {
			cout << "Login out succeed." << endl;
			cout << "Welcome for next time." << endl;
			system("pause");
			break;
		}
	}
}

void Scouts::deleteAll() {
	for (int i = 0; i < scoutsCount; i++) {
		delete[] scouts[i];
	}
	delete[] scouts;
	scouts = 0;
}


void Scouters::setRank(string rank) {
	this->rank = rank;
}

void Scouters::setScouters(string** scouters) {
	this->scouters = scouters;
}

void Scouters::setScoutersCount(int scoutersCount) {
	this->scoutersCount = scoutersCount;
}

string Scouters::getRank() {
	return rank;
}

string** Scouters::getScouters() {
	setAll();
	return scouters;
}

int Scouters::getScoutersCount() {
	setAll();
	return scoutersCount;
}

void Scouters::setAll() {
	int scoutersCount;
	FileHandler f;
	string** scouters = f.scoutersFile(scoutersCount);
	Scouters stcrs[100];
	for (int i = 0; i < scoutersCount; i++) {
		stcrs[i].setUserID(scouters[i][0]);
		stcrs[i].setName(scouters[i][1]);
		stcrs[i].setSection(scouters[i][2]);
		stcrs[i].setBirth(scouters[i][3]);
		stcrs[i].setAddress(scouters[i][4]);
		stcrs[i].setRank(scouters[i][5]);
	}
	setScouters(scouters);
	setScoutersCount(scoutersCount);
}

void Scouters::scoutersMenu(string rightUser) {
	for (;;) {//equal to infiinfinite loop, equivalent to while(true). //
		//When no termination condition is provid//the condition defaults to true.//
		system("cls");
		int action = 0;
		Tent ten;
		Stove sto;
		Lantern lan;
		cout << "1) Displaying camp equipment.\n";
		cout << "2) Return.\n";
		cout << "3) Loaning equipment. \n";
		cout << "4) Displaying loan record.\n";
		cout << "5) Exit.\n\n";
		cout << "Enter the number(1 - 5): ";
		cin >> action;

		if (action == 1) {
			system("cls");
			for (int i = 0; i < ten.getTentCount(); i++) {
				if (ten.getTent()[i][5] == "good" && ten.getTent()[i][6] == "in") {
					for (int j = 0; j < 12; j++) {
						cout << ten.getTent()[i][j] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
			for (int i = 0; i < sto.getStoveCount(); i++) {
				if (sto.getStove()[i][5] == "good" && sto.getStove()[i][6] == "in") {
					for (int j = 0; j < 9; j++) {
						cout << sto.getStove()[i][j] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
			for (int i = 0; i < lan.getLanternCount(); i++) {
				if (lan.getLantern()[i][5] == "good" && lan.getLantern()[i][6] == "in") {
					for (int j = 0; j < 10; j++) {
						cout << lan.getLantern()[i][j] << " ";
					}
					cout << endl;
				}
			}
			system("pause");
		}
		else if (action == 4) {
			system("cls");
			FileHandler f;
			f.readLoanRecord(rightUser);
			system("pause");
		}
		else if (action == 3) {
			system("cls");
			int typeLimit;
			FileHandler f;
			bool flag = f.readLoanRecord(rightUser);
			if (flag == true) {
				system("cls");
				string type;
				if (rightUser.substr(0, 3) == "SCM") {
					for (int i = 0; i < scoutersCount; i++) {
						if (rightUser == scouters[i][0]) {
							type = scouters[i][2];
							break;
						}
					}
				}
				if (type == "Scouter") {
					cout << "You can borrow at most 5 item." << endl;
					typeLimit = 5;
				}
				int noOfBorrow;
				LoanControl l;
				string *arr = l.lendItem(typeLimit, noOfBorrow);
				int borrowCount;
				f.writeLoanRecord(arr, borrowCount, noOfBorrow, rightUser);

				delete[] arr;
				arr = 0;
			}
			else {
				cout << endl;
				cout << "You are not allow to lend.Please check your load record." << endl;
				cout << "Maybe your lending limit reached" << endl;
				cout << "Please require admin upgrade your permission or return the equipment first." << endl;
			}
			system("pause");
		}
		else if (action == 2) {
			system("cls");
			FileHandler f;
			f.updateLoanRecord(rightUser);
			system("pause");
		}
		else if (action == 5) {
			cout << "Login out succeed." << endl;
			cout << "Welcome for next time." << endl;

			system("pause");
			break;
		}
		else if (action != 1 && action != 2 && action != 3 && action != 4 && action != 5) {
			cout << "Please login again if you want to use this system." << endl;
			system("pause");
			break;
		}
	}
}

void Scouters::deleteAll() {
	for (int i = 0; i < scoutersCount; i++) {
		delete[] scouters[i];
	}
	delete[] scouters;
	scouters = 0;
}