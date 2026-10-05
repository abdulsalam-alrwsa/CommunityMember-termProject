#pragma once
#include"Employee.h"
#include <fstream>

class Staff : public Employee {

public : 
	
	

	Staff(unsigned long long id1 = 0, unsigned long long phone1 = 0,
		const char firstname1[10] = "",const char lastname1[10] = "",
		const char address1[20] = "", double salary1 = 0, const char department1[10] ="")
		:Employee(id1, phone1, firstname1,lastname1,address1,salary1) {
		for (int i = 0; i < 10; i++)
		{
			department[i] = department1[i];

		}
		
	}

	virtual void printToFile(std::fstream& ofs) const {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}
	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
		Staff::print();
		cout << endl;
	}

	void readdata() {
		Employee::readdata();
		cout << "department : " << endl;
		cin >> department;
	
	}
	void setdepartment(char department1[10]) {
		for (int i = 0; i < 10; i++)
		{
			department[i] = department1[i];

		}

	}

	char *getdepartment() {
		return department;
	}
	
	void print() {
		cout << "Staff:\n";
		Employee::print();
		cout << "Department :\t" << department << endl;
	}
	

private:
	char department[10];


};
