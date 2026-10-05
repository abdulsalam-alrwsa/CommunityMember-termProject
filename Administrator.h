#pragma once
#include "Faculty.h"


class Administrator : public Faculty {
public : 
	
	
	virtual void printToFile(std::fstream& ofs) const {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}
	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
		Administrator::print();
		cout << endl;

	}

	Administrator(unsigned long long id1 = 0, unsigned long long phone1 = 0,
		const char firstname1[10] = "", const char lastname1[10] = "",
		const char address1[20] = "", double salary1 = 0, const char specialty1[10] = "\0", const char academicrank1[10] = "\0", const char position1[10] = "")
		:Faculty(id1, phone1, firstname1, lastname1, address1, salary1,specialty1, academicrank1) {

		
		for (int i = 0; i < 10; i++)
		{
			position[i] = position1[i];

		}

     }


	virtual void readdata() {
		Faculty::readdata();
		cout << "Position :" << endl;
		cin >> position;
	}
	void setposition(char position1[10]) {
		for (int i = 0; i < 10; i++)
		{
			position[i] = position1[i];

		}
	}
	char *getposition() {
		return position;
	}
	virtual void print() {
		cout << "Administrator:\n";
		Faculty::print();
		cout << " position :\t" << position << endl;
	}
	
private : 
	char position[10];
	

};
