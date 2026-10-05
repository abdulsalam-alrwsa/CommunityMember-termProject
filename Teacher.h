#pragma once
#include "Faculty.h"


class Teacher : public Faculty {
public:
	
	virtual void printToFile(std::fstream& ofs) const {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}

	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
		Teacher::print();
		cout << endl;
	}

	

	 Teacher(unsigned long long id1 = 0, unsigned long long phone1 = 0, 
            const char firstname1[10] = "", const char lastname1[10] = "",
            const char address1[20] = "", double salary1 = 0.0,
            const char specialty1[10] = "\0", const char academicrank1[10] = "\0",
            unsigned int hoursperweek1 = 0)
            : Faculty(id1, phone1, firstname1, lastname1, address1, salary1, specialty1, academicrank1) {
        hoursperweek = hoursperweek1;
    }


	virtual void readdata() {
		Faculty::readdata();
		cout << "hours in week:" << endl;
		cin >> hoursperweek;
	}
	void sethoursperweek(unsigned int hoursperweek1) {
		hoursperweek = hoursperweek1;
	}
	unsigned int gethoursperweek() {
		return hoursperweek;
	}
	virtual void print() {
		cout << "Teacher:\n";
		Faculty::print();
		cout << "Hours in week: " << hoursperweek << endl;
	}
	
private:
	unsigned int hoursperweek;
	

};
