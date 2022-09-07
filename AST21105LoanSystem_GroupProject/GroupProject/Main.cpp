#include <iostream>
#include <string>
#include "FileHandler.h"
#include "User.h"
#include "Equipment.h"
#include "Admin.h"

using namespace std;
//check User input(User Name) Correct or not//
bool checkName(string** ls, string username, int array) {
	bool flag = false;
	for (int i = 0; i < array; i++) {
		if (username == ls[i][0])
			flag = true;
	}
	if (flag == false)
		cout << "Username" << endl;
	return flag;
}
//search user name from the text file(user.txt)
string searchUserName(string** ls, string username, int array) {
	for (int i = 0; i < array; i++) {
		if (username == ls[i][0])
			return ls[i][0];
	}
}

bool checkPassword(string** ls, string rightUser, string password, int array) {
	bool flag = false;
	int passwordOfUser = 0;
	for (int i = 0; i < array; i++) {
		if (rightUser == ls[i][0]) {
			passwordOfUser = i;
			break;
		}
	}
	if (password == ls[passwordOfUser][1]) {
		flag = true;
	}
	else
		cout << "Password" << endl;
	return flag;
}
string checking(string** ls, int array) {
	bool loop;
	string rightUser = " ";
	do {
		string username;
		system("cls");
		loop = true;
		cout << "Username:";
		cin >> username;
		bool flag = checkName(ls, username, array);
		if (flag == true) {
			loop = false;
			rightUser = searchUserName(ls, username, array);
		}
		else
			system("pause");
	} while (loop);
	do {
		loop = true;
		string password;
		cout << "Password:";
		cin >> password;
		bool flag = checkPassword(ls, rightUser, password, array);
		if (flag == true)
			loop = false;
		else {
			system("pause");
			return checking(ls, array);
		}
	} while (loop);
	return rightUser;
}

int main() {
	Admin admin;
	Scout sct;
	Scouts scts;
	Scouters sctrs;
	Tent ten;
	Stove sto;
	Lantern lan;
	string** ls = 0;
	ls = new string*[300];
	int array = 0;
	for (int i = 0; i < sct.getScoutCount(); i++, array++) {
		ls[array] = new string[3];
		ls[array][0] = sct.getScout()[i][0];
		ls[array][1] = sct.getScout()[i][3];
		ls[array][2] = sct.getScout()[i][1];
	}
	for (int i = 0, j = 0; i < scts.getScoutsCount(); i++, j++, array++) {
		ls[array] = new string[3];
		ls[array][0] = scts.getScouts()[j][0];
		ls[array][1] = scts.getScouts()[j][3];
		ls[array][2] = scts.getScouts()[j][1];
	}
	for (int i = 0, j = 0; i < sctrs.getScoutersCount(); i++, j++, array++) {
		ls[array] = new string[3];
		ls[array][0] = sctrs.getScouters()[j][0];
		ls[array][1] = sctrs.getScouters()[j][3];
		ls[array][2] = sctrs.getScouters()[j][1];
	}
	for (int i = 0; i < 1; i++, array++) {
		ls[array] = new string[3];
		ls[array][0] = "admin";
		ls[array][1] = "admin";
		ls[array][2] = "admin";
	}

	string rightUser = checking(ls, array);
	system("pause");
	system("cls");

	if (rightUser == "admin")
		admin.adminFunction();
	else if (rightUser.substr(0, 3) == "VEN" || rightUser.substr(0, 3) == "ROV")
		sct.scoutMenu(rightUser);
	else if (rightUser.substr(0, 3) == "SCT")
		scts.scoutsMenu(rightUser);
	else if (rightUser.substr(0, 3) == "SCM")
		sctrs.scoutersMenu(rightUser);

	// avoid memory leakage
	sct.deleteAll();
	scts.deleteAll();
	sctrs.deleteAll();
	ten.deleteAll();
	sto.deleteAll();
	lan.deleteAll();


	for (int i = 0; i < array; i++) {
		delete[] ls[i];
	}
	delete[] ls;
	ls = 0;


	return 0;
}