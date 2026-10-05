// PROJECT CS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"CommunityMember.h"
#include"Student.h"
#include "Alumnus.h"
#include"Employee.h"
#include"Staff.h"
#include"Faculty.h"
#include"Administrator.h"
#include"Teacher.h"
#include <vector>
#include <fstream>

// The Project has done by:
// Abdulslam abdulmohsen alrwsa - 441101285
// Ziad Othman Al-abduljabbar - 441100931
// abdulmohsen Aljomah – 441101258
// mohammed ahmad alghanam  – 441101802


int determineType(CommunityMember* ptr) {
   
    if (dynamic_cast<Student*>(ptr) != nullptr) {
        return 1;
    }
    else if (dynamic_cast<Alumnus*>(ptr) != nullptr) {
        return 2;
    }
    else if (dynamic_cast<Staff*>(ptr) != nullptr) {
        return 3;
    }
    else if (dynamic_cast<Administrator*>(ptr) != nullptr) {
        return 4;
    }
    else if (dynamic_cast<Teacher*>(ptr) != nullptr) {
        return 5;
    }
    else {
        return 0;
    }
}

int main() {
    int count, ch, choice=0;
    int typeMarker;

    CommunityMember* a_ptr[30]{};
    std::fstream Community("Community.dat", ios::out | ios::in| ios::binary | ios::app);
   
    while (choice != 3) {
        std::cout << "Select an option:\n";
        std::cout << "1. Store data to file\n";
        std::cout << "2. Retrieve data from file\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            Community.close();
            Community.open("Community.dat", std::ios::in | std::ios::binary | ios::app);
            if (!Community) {
                std::cerr << "Error opening file for writing!" << std::endl;
                return 0;
            }
            cout << "  Enter how many members you will add : ";
            cin >> count;


            for (int i = 0; i < count; i++) {
                cout << "Choose the type of member:\n"
                    << "1- Student\n"
                    << "2- Alumnus\n"
                    << "3- Staff\n"
                    << "4- Administrator\n"
                    << "5- Teacher\n";
                cin >> ch;
                cout << "Enter the data for member " << (i + 1) << ":\n";

                switch (ch) {
                case 1:
                    a_ptr[i] = new Student;
                    break;
                case 2:
                    a_ptr[i] = new Alumnus;
                    break;
                case 3:
                    a_ptr[i] = new Staff;
                    break;
                case 4:
                    a_ptr[i] = new Administrator;
                    break;
                case 5:
                    a_ptr[i] = new Teacher;
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    i--;
                    continue;
                }

                a_ptr[i]->readdata();
            }
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < count; j++) {
                    if (j != i) {
                        if (*a_ptr[i] == *a_ptr[j]) {
                            unsigned  long long re_ID;
                            cout << "the member " << i + 1 << " and " << j + 1 << " have the same ID." << endl;
                            cout << "Enter Another ID for member " << j + 1 << ":" << endl;
                            cin >> re_ID;
                            a_ptr[j]->setid(re_ID);
                        }
                    }
                }
            }


            for (int i = 0; i < count; i++) {
                if (a_ptr[i] != nullptr) {
                    int typeMarker = determineType(a_ptr[i]);
                    cout << "\n" << endl;
                    Community.write(reinterpret_cast<const char*>(&typeMarker), sizeof(int));
                    a_ptr[i]->printToFile(Community);
                }
            }
            Community.close();
    
            break;
        case 2:
            Community.close();
            Community.open("Community.dat", std::ios::in | std::ios::binary | ios::app);
            if (!Community) {
                std::cerr << "Error opening file for reading!" << std::endl;
                return 0;
            }
            
            while (Community.read(reinterpret_cast<char*>(&typeMarker), sizeof(int))) {
                switch (typeMarker) {
                case 1: {
                    Student* student_ptr = new Student;
                    student_ptr->readFromFile(Community);
                    delete student_ptr;
                    break;
                }
                case 2: {
                    Alumnus* alumnus_ptr = new Alumnus;
                    alumnus_ptr->readFromFile(Community);
                    delete alumnus_ptr;
                    break;
                }
                case 3: {
                    Staff* staff_ptr = new Staff;
                    staff_ptr->readFromFile(Community);
                    delete staff_ptr;
                    break;
                }
                case 4: {
                    Administrator* Administrator_ptr = new Administrator;
                    Administrator_ptr->readFromFile(Community);
                    delete Administrator_ptr;
                    break;
                }
                case 5: {
                    Teacher* Teacher_ptr = new Teacher;
                    Teacher_ptr->readFromFile(Community);
                    delete Teacher_ptr;
                    break;
                }

                default:
                    cout << "Error";
                    break;
                }
            }

       
            break;

        case 3:
           std::cout << "Exiting...\n";
           break;
        }
    } 
   
    for (int i = 0; i < 30; ++i) {
        if (a_ptr[i] != nullptr) {
            delete a_ptr[i];
            a_ptr[i] = nullptr;
        }
    }
}


	






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
