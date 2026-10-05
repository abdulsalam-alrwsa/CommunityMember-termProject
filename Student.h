#pragma once
#include"CommunityMember.h"

class Student : public CommunityMember {

public:
	
	virtual void printToFile(std::fstream& ofs) const {

		ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
	}

	virtual void readFromFile(std::fstream& ifs) {
		ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
		Student::print();
		cout << endl;
	}

	
	Student(unsigned long long id1 = 0, unsigned long long phone1 = 0,
		const char firstname1[10] = "", const char lastname1[10] = "",
		const char address1[20] = "", double gpa1 = 0, unsigned int courseloadhours1 = 0)
		:CommunityMember(id1, phone1, firstname1, lastname1, address1) {
		gpa = gpa1;
		courseloadhours = courseloadhours1;
	}
	virtual void readdata() {
		CommunityMember::readdata();
		cout << "GPA  :" << endl;
		cin >> gpa;
		cout << "Course load hours : "<< endl;
		cin >> courseloadhours;
	}
	void setgpa(double gpa1) {
		gpa = gpa1;
	}
	double getgpa() {
		return gpa;
	}
	void setcourseloadhours(unsigned int courseloadhours1) {
		courseloadhours = courseloadhours1;
	}
	unsigned int getcourseloadhours() {
		return courseloadhours;
	}
	virtual void print() {
		cout << "Student:\n";
		CommunityMember::print();
		cout << "       GPA :\t" << gpa << endl;
		cout << " Course load hours : " << courseloadhours << endl;
	}	

private:
	double gpa;
	unsigned int courseloadhours;
	};
