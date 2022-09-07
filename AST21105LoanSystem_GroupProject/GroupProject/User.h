#ifndef USER_H
#define USER_H

#include <string>
#include "FileHandler.h"

using namespace std;

class User {
protected:
	string userID;
	string name;
	string section;
	string birth;
	string address;
public:
	void setUserID(string userID);
	void setName(string name);
	void setSection(string section);
	void setBirth(string birth);
	void setAddress(string address);
	string getUserID();
	string getName();
	string getSection();
	string getBirth();
	string getAddress();

};

class Scout : public User {
private:
	string** scout;
	int scoutCount;
public:
	void setScout(string** scout);
	void setScoutCount(int scoutCount);
	string** getScout();
	int getScoutCount();
	void setAll();
	void scoutMenu(string rightUser);
	void deleteAll();
};

class Scouts : public User {
private:
	string rank;
	string** scouts;
	int scoutsCount;
public:
	void setRank(string rank);
	void setScouts(string** scouts);
	void setScoutsCount(int scoutsCount);
	string getRank();
	string** getScouts();
	int getScoutsCount();
	void setAll();
	void scoutsMenu(string rightUser);
	void deleteAll();
};

class Scouters : public User {
private:
	string rank;
	string** scouters;
	int scoutersCount;
public:
	void setRank(string rank);
	void setScouters(string** scouters);
	void setScoutersCount(int scoutersCount);
	string getRank();
	string** getScouters();
	int getScoutersCount();
	void setAll();
	void scoutersMenu(string rightUser);
	void deleteAll();
};

#endif