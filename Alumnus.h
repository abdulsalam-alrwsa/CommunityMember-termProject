#pragma once
#include"CommunityMember.h"

class Alumnus : public CommunityMember {

public:
	
	virtual void printToFile(std::fstream& ofs) const {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}

	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
		Alumnus::print();
		cout << endl;

	}
	
	Alumnus(unsigned long long id1 = 0, unsigned long long phone1 = 0,
		const char firstname1[10] = "", const char lastname1[10] = "",
		const char address1[20] = "", unsigned int yearofgraduation1 = 0, const char currentjop1[10] ="")
		:CommunityMember(id1, phone1, firstname1, lastname1, address1) {

		yearofgraduation = yearofgraduation1;
		for (int i = 0; i < 10; i++)
		{
			currentjop[i] = currentjop1[i];

		}
	}
	
	virtual void readdata(){ 
		CommunityMember::readdata();
		cout << "year of gradution : " << endl;
		cin >> yearofgraduation;
		cout << "Current jop :" << endl;
		cin >> currentjop;
	}
	void setyearofgraduation(unsigned int yearofgraduation1) {
		yearofgraduation = yearofgraduation1;
	}
	unsigned int getyearofgraduation() {
		return yearofgraduation;
	}
	void setcurrentjop(char currentjop1[10]) {
		for (int i = 0; i < 10; i++)
		{
			currentjop[i] = currentjop1[i];

		}
	}
	char *getcurrentjop() {
		return currentjop;
	}
	virtual void print() {
		cout << "Alumnus:\n";
		CommunityMember::print();
		cout << "Current jop:\t" << currentjop << endl;
		cout << "Year Of graduation : \t" << yearofgraduation << endl;
		
	}
	

private:
	unsigned int yearofgraduation;
	char currentjop[10];


};
