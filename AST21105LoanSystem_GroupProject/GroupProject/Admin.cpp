#include "Admin.h"
#include "FileHandler.h"
#include "Equipment.h"
#include "LoanControl.h"

using namespace std;

void Admin::adminFunction() {
	int input;

	cout << "1) Inserting .\n";
	cout << "2) Output a .txt file .\n";
	cout << "3) Display all camp equipment.\n";
	cout << "4) Update equipment.\n";
	cout << "5) Loan records.\n";
	cout << "6) Exit.\n\n";
	cout << "Enter the number(1 - 6): \n";
	cin >> input;
	if (!cin) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "please input number(1 - 6)";
	}
	switch (input) {
	case 1:
		AdminFunctionA();
		break;
	case 2:
		AdminFunctionE();
		break;
	case 3:
		AdminFunctionC();
		break;
	case 4:
		AdminFunctionD();
		break;
	case 5:
		AdminFunctionB();
		break;
	case 6:
		AdminFunctionF();
		break;
	default:
		cout << "invalid input!";
		system("pause");
		system("cls");
		adminFunction();
	}
}

void Admin::AdminFunctionA() {
	cout << "users and camp equipment are aldready input.";
	system("pause");
	system("cls");
	adminFunction();
}

//Display loan records containing loan date.
void Admin::AdminFunctionB() {
	system("cls");
	FileHandler file;
	int recordCount = 0;
	string** loanRecord2d = 0;
	loanRecord2d = new string*[100];
	file.readLoanRecord(loanRecord2d, recordCount);
	for (int i = 0; i < recordCount; i++) {
		for (int j = 1; j < 5; j++) {
			switch (j) {
			case 1:
			case 2:
				cout << loanRecord2d[i][j] << "\t";
				break;
			case 3:
				cout << loanRecord2d[i][j] << "\t\t";
				break;
			case 4:
				cout << loanRecord2d[i][j] << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
	adminFunction();
}

//Display list of camp equipment
void Admin::AdminFunctionC() {
	system("cls");
	Tent adminTent;
	Stove adminStove;
	Lantern adminLantern;
	cout << "Tent\n";
	for (int i = 0; i < adminTent.getTentCount(); i++) {
		for (int j = 0; j < 12; j++) {
			cout << adminTent.getTent()[i][j];
			if (j < 11) {
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << "\nStove\n";
	for (int i = 0; i < adminStove.getStoveCount(); i++) {
		for (int j = 0; j < 9; j++) {
			cout << adminStove.getStove()[i][j];
			if (j < 8) {
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << "\nLantern\n";
	for (int i = 0; i < adminLantern.getLanternCount(); i++) {
		for (int j = 0; j < 10; j++) {
			cout << adminLantern.getLantern()[i][j];
			if (j < 9) {
				cout << "|";
			}
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	adminFunction();
}

//Update condition of equipment.
void Admin::AdminFunctionD() {
	system("cls");
	Tent adminTent;
	Stove adminStove;
	Lantern adminLantern;
	FileHandler adminF;
	cout << "Tent\n";
	for (int i = 0; i < adminTent.getTentCount(); i++) {
		for (int j = 0; j < 12; j++) {
			cout << adminTent.getTent()[i][j];
			if (j < 11) {
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << "\nStove\n";
	for (int i = 0; i < adminStove.getStoveCount(); i++) {
		for (int j = 0; j < 9; j++) {
			cout << adminStove.getStove()[i][j];
			if (j < 8) {
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << "\nLantern\n";
	for (int i = 0; i < adminLantern.getLanternCount(); i++) {
		for (int j = 0; j < 10; j++) {
			cout << adminLantern.getLantern()[i][j];
			if (j < 9) {
				cout << "|";
			}
		}
		cout << endl;
	}

	cout << "select which equipment condition to update by input Item code\n";
	string item;
	bool flag = false;
	string condition;
	cin >> item;
	for (int i = 0; i < adminTent.getTentCount(); i++) {
		if (item == adminTent.getTent()[i][0]) {
			flag = true;
			cout << "condition of " << adminTent.getTent()[i][0] << " want to change to :";
			cin >> condition;
			adminTent.getTent()[i][5] = condition;
			adminF.writecondition(adminTent, adminStove, adminLantern);
			system("pause");
			system("cls");
			adminFunction();
		}
	}
	for (int i = 0; i < adminStove.getStoveCount(); i++) {
		if (item == adminStove.getStove()[i][0]) {
			flag = true;
			cout << "condition of " << adminStove.getStove()[i][0] << " want to change to :";
			cin >> condition;
			adminStove.getStove()[i][5] = condition;
			adminF.writecondition(adminTent, adminStove, adminLantern);
			system("pause");
			system("cls");
			adminFunction();
		}
	}
	for (int i = 0; i < adminLantern.getLanternCount(); i++) {
		if (item == adminLantern.getLantern()[i][0]) {
			flag = true;
			cout << "condition of " << adminLantern.getLantern()[i][0] << " want to change to :";
			cin >> condition;
			adminLantern.getLantern()[i][5] = condition;
			adminF.writecondition(adminTent, adminStove, adminLantern);
			system("pause");
			system("cls");
			adminFunction();
		}
	}
	if (flag == false) {
		if (item == "exit") {
			system("cls");
			adminFunction();
		}
		else {
			cout << "wrong input please try again!\n";
			system("pause");
			system("cls");
			AdminFunctionD();
		}
	}
}

void Admin::AdminFunctionE() {

}

void Admin::AdminFunctionF() {
	cout << "thank you for using this system." << endl;
	// Hold the command window
	system("pause");

}