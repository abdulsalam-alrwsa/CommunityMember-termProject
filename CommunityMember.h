#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <cstring>
using namespace std;

class CommunityMember {
public:

	virtual void printToFile(std::fstream& ofs) const  {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}

	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
	}

	bool operator==(const CommunityMember& other) const {
		return (id == other.id);
	}
	
	CommunityMember(unsigned long long id1 = 0, unsigned long long phone1 = 0,
		const char firstname1[10] = "", const char lastname1[10] = "",
		const char address1[20] = "") {
		id = id1;
	   phone = phone1;
		
			for (int i = 0; i < 10; i++)
			{
				lastname[i] = lastname1[i];

			}
			for (int i = 0; i < 10; i++)
			{
				firstname[i] = firstname1[i];

			}
			for (int i = 0; i < 10; i++)
			{
				address[i] = address1[i];

			}
		

	}

 virtual void readdata() {


		cout << "ID : " << endl;
		cin >> id;
		cout << "Phone number :" << endl;
		cin >> phone;
		cout << "First Name   : " << endl;
		cin >> firstname;
		cout << "Last name    : " << endl;
		cin >> lastname;
		cout << "Address      :" << endl;
		cin >> address;
	}
	void setid(unsigned  long int id1) {
		id = id1;
	}
	unsigned  long int getid() {
		return id;
	}
	void setphone(unsigned  long int phone1) {
		phone = phone1;
	}
	unsigned  long int getphone() {
		return phone;
	}
	void setfirstname(char firstname1[10]) {
		for (int i = 0; i < 10; i++)
		{
			firstname[i] = firstname1[i];

		}
	}
	char * getfirstname() {
		return firstname;
	}
	void setlastname(char lastname1[10]) {
		for (int i = 0; i < 10; i++)
		{
			lastname[i] = lastname1[i];

		}
	}
	char * getlastname() {
		return lastname;
	}
	void setaddress(char address1[10]) {
		for (int i = 0; i < 10; i++)
		{
			address[i] = address1[i];

		}
	}
	char * getaddress() {
		return address;
	}

	 virtual void print() {
		cout << "First name :\t" << firstname << endl;
		cout << " Last name :\t" << lastname << endl;
		cout << "        ID :\t" << id << endl;
		cout << "     Phone :\t" << phone << endl;
		cout << "   Address :\t" << address << endl;
	}

protected:
	unsigned  long long id, phone;
     
	char  firstname[10];
	char lastname[10];
	char address[20];

};
