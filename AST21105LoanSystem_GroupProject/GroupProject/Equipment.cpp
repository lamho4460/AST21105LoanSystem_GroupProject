#include "Equipment.h"
#include "FileHandler.h"

//Equipment
void Equipment::setItemID(string itemID) {
	this->itemID = itemID;
}

void Equipment::setItemName(string itemName) {
	this->itemName = itemName;
}

void Equipment::setBrand(string brand) {
	this->brand = brand;
}

void Equipment::setItemType(string itemType) {
	this->itemType = itemType;
}

void Equipment::setDateOfPurchase(string dateOfPurchase) {
	this->dateOfPurchase = dateOfPurchase;
}

void Equipment::setCondition(string condition) {
	this->condition = condition;
}

void Equipment::setStatus(string status) {
	this->status = status;
}

string Equipment::getItemID() {
	return itemID;
}
string Equipment::getItemName() {
	return itemName;
}
string Equipment::getBrand() {
	return brand;
}
string Equipment::getItemType() {
	return itemType;
}
string Equipment::getDateOfPurchase() {
	return dateOfPurchase;
}
string Equipment::getCondition() {
	return condition;
}
string Equipment::getStatus() {
	return status;
}

//Tent
Tent::Tent() {
	flag = true;
}

void Tent::setTentSize(string tentSize) {
	this->tentSize = tentSize;
}

void Tent::setTentType(string tentType) {
	this->tentType = tentType;
}

void Tent::setNumberOfDoors(string numberOfDoors) {
	this->numberOfDoors = numberOfDoors;
}

void Tent::setDoubleLayer(string doubleLayer) {
	this->doubleLayer = doubleLayer;
}

void Tent::setColour(string colour) {
	this->colour = colour;
}

void Tent::setTent(string** tent) {
	this->tent = tent;
}

void Tent::setTentCount(int tentCount) {
	this->tentCount = tentCount;
}

string Tent::getTentSize() {
	return tentSize;
}

string Tent::getTentType() {
	return tentType;
}

string Tent::getNumberOfDoors() {
	return numberOfDoors;
}

string Tent::getDoubleLayer() {
	return doubleLayer;
}

string Tent::getColour() {
	return colour;
}

string** Tent::getTent() {
	if (flag == true)
		setAll();
	return tent;
}

int Tent::getTentCount() {
	if (flag == true)
		setAll();
	return tentCount;
}

void Tent::setAll() {
	int tentCount;
	FileHandler f;
	string** tent = f.tentFile(tentCount);
	Tent tempOfTent[100];
	for (int i = 0; i < tentCount; i++) {
		tempOfTent[i].setItemID(tent[i][0]);
		tempOfTent[i].setItemName(tent[i][1]);
		tempOfTent[i].setBrand(tent[i][2]);
		tempOfTent[i].setItemType(tent[i][3]);
		tempOfTent[i].setDateOfPurchase(tent[i][4]);
		tempOfTent[i].setCondition(tent[i][5]);
		tempOfTent[i].setStatus(tent[i][6]);
		tempOfTent[i].setTentSize(tent[i][7]);
		tempOfTent[i].setTentType(tent[i][8]);
		tempOfTent[i].setNumberOfDoors(tent[i][9]);
		tempOfTent[i].setDoubleLayer(tent[i][10]);
		tempOfTent[i].setColour(tent[i][11]);
	}
	setTent(tent);
	setTentCount(tentCount);
	flag = false;
}

void Tent::deleteAll() {
	for (int i = 0; i < tentCount; i++) {
		delete[] tent[i];
	}
	delete[] tent;
	tent = 0;
}

//Stove
Stove::Stove() {
	flag = true;
}

void Stove::setStoveType(string stoveType) {
	this->stoveType = stoveType;
}

void Stove::setFuelType(string fuelType) {
	this->fuelType = fuelType;
}

void Stove::setStove(string** stove) {
	this->stove = stove;
}

void Stove::setStoveCount(int stoveCount) {
	this->stoveCount = stoveCount;
}

string Stove::getStoveType() {
	return stoveType;
}
string Stove::getFuelType() {
	return fuelType;
}
string** Stove::getStove() {
	if (flag == true)
		setAll();
	return stove;
}
int Stove::getStoveCount() {
	if (flag == true)
		setAll();
	return stoveCount;
}
void Stove::setAll() {
	int stoveCount;
	FileHandler f;
	string** stove = f.stoveFile(stoveCount);
	Stove tempOfStove[100];
	for (int i = 0; i < stoveCount; i++) {
		tempOfStove[i].setItemID(stove[i][0]);
		tempOfStove[i].setItemName(stove[i][1]);
		tempOfStove[i].setBrand(stove[i][2]);
		tempOfStove[i].setItemType(stove[i][3]);
		tempOfStove[i].setDateOfPurchase(stove[i][4]);
		tempOfStove[i].setCondition(stove[i][5]);
		tempOfStove[i].setStatus(stove[i][6]);
		tempOfStove[i].setStoveType(stove[i][7]);
		tempOfStove[i].setFuelType(stove[i][8]);
	}
	setStove(stove);
	setStoveCount(stoveCount);
	flag = false;
}

void Stove::deleteAll() {
	for (int i = 0; i < stoveCount; i++) {
		delete[] stove[i];
	}
	delete[] stove;
	stove = 0;
}

//Lantern
Lantern::Lantern() {
	flag = true;
}

void Lantern::setLanternSize(string lanternSize) {
	this->lanternSize = lanternSize;
}

void Lantern::setLanternType(string lanternType) {
	this->lanternType = lanternType;
}

void Lantern::setFuelType(string fuelType) {
	this->fuelType = fuelType;
}

void Lantern::setLantern(string** lantern) {
	this->lantern = lantern;
}
void Lantern::setLanternCount(int lanternCount) {
	this->lanternCount = lanternCount;
}
string Lantern::getLanternSize() {
	return lanternSize;
}
string Lantern::getLanternType() {
	return lanternType;
}
string Lantern::getFuelType() {
	return fuelType;
}
string** Lantern::getLantern() {
	if (flag == true)
		setAll();
	return lantern;
}
int Lantern::getLanternCount() {
	if (flag == true)
		setAll();
	return lanternCount;
}
void Lantern::setAll() {
	int lanternCount;
	FileHandler f;
	string** lantern = f.lanternFile(lanternCount);
	Lantern tempOfLantern[100];
	for (int i = 0; i < lanternCount; i++) {
		tempOfLantern[i].setItemID(lantern[i][0]);
		tempOfLantern[i].setItemName(lantern[i][1]);
		tempOfLantern[i].setBrand(lantern[i][2]);
		tempOfLantern[i].setItemType(lantern[i][3]);
		tempOfLantern[i].setDateOfPurchase(lantern[i][4]);
		tempOfLantern[i].setCondition(lantern[i][5]);
		tempOfLantern[i].setStatus(lantern[i][6]);
		tempOfLantern[i].setLanternSize(lantern[i][7]);
		tempOfLantern[i].setLanternType(lantern[i][8]);
		tempOfLantern[i].setFuelType(lantern[i][9]);
	}
	setLantern(lantern);
	setLanternCount(lanternCount);
	flag = false;
}

void Lantern::deleteAll() {
	for (int i = 0; i < lanternCount; i++) {
		delete[] lantern[i];
	}
	delete[] lantern;
	lantern = 0;
}