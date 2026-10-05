#pragma once
#include"CommunityMember.h"
#include <fstream>

class Employee : public CommunityMember {
public:
 
    virtual void printToFile(std::fstream& ofs) const {

        ofs.write(reinterpret_cast<const char*>(this), sizeof(*this));
    }
    virtual void readFromFile(std::fstream& ifs) {
        ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
    }

    Employee(unsigned long long id1 = 0, unsigned long long phone1 = 0,
        const char firstname1[10] = "", const char lastname1[10] = "",
        const char address1[20] = "", double salary1 = 0) :CommunityMember(id1, phone1, firstname1, lastname1, address1) {
        
        salary = salary1;
    }

    virtual void readdata() {
        CommunityMember::readdata(); 
        char choice;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Choose action - (I) Increment / (D) Decrement / (N) None:\n";
        cin >> choice;
        if (choice == 'I' || choice == 'i') {
            ++(*this);
        }
        else if (choice == 'D' || choice == 'd') {
            --(*this);
        }
    }

    void setsalary(double salary1) {
        salary = salary1;
    }

    double getsalary() {
        return salary;
    }

    virtual void print() {
        CommunityMember::print();
        cout << "Salary: " << salary << endl;
    }

    Employee& operator++() {
        salary *= 1.05;
        return *this;
    }

    Employee& operator--() {
        salary *= 0.95;
        return *this;
    }

protected:
    double salary;
};
