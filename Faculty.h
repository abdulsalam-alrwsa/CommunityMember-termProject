#pragma once
#include"Employee.h"

class Faculty : public Employee {

public:

	virtual void printToFile(std::fstream& ofs) const {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}

	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
	}



	Faculty(unsigned long long id1 = 0, unsigned long long phone1 = 0,
		const char firstname1[10] = "", const char lastname1[10] = "",
		const char address1[20] = "", double salary1 = 0, const char specialty1[10] = "\0",const char academicrank1[10] = "\0")
		:Employee(id1, phone1, firstname1, lastname1, address1, salary1) {

		for (int i = 0; i < 10; i++)
		{
			specialty[i] = specialty1[i];

		}
		for (int i = 0; i < 10; i++)
		{
			academicrank[i] = academicrank1[i];

		}


	}



	 virtual void readdata() {
		Employee::readdata();
		cout << "specialty :  " << endl;
    	cin >> specialty;
		cout << "acadmic rank : " << endl;
		cin >> academicrank;

	}
	void setspecialty(char specialty1[10]) {
		for (int i = 0; i < 10; i++)
		{
			specialty[i] = specialty1[i];

		}

	}

	char *getspecialty() {
		return specialty;
	}
	void setacademicrank(char academicrank1[10]) {
		for (int i = 0; i < 10; i++)
		{
			academicrank[i] = academicrank1[i];

		}
	}
	char *getacademicrank() {
		return academicrank;
	}
	virtual void print() {
		Employee::print();
		cout << "specialty     : " << specialty << endl;
		cout << "academic rank : " << academicrank << endl;
	}

protected:
	char specialty[10];
	char academicrank[10];

};
