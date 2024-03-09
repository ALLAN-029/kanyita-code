#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string admissionNumber;
    string name;
    double marks[5];
};

void saveStudentDetailsToFile(const Student& student) {
    ofstream outFile("studentMarks.txt", ios::app);
    if (outFile.is_open()) {
        outFile << student.admissionNumber << " " << student.name << " ";
        for (int i = 0; i < 5; ++i) {
            outFile << student.marks[i] << " ";
        }
        outFile << endl;
        outFile.close();
        cout << "Student details saved successfully.\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void displayStudentDetailsFromFile() {
    ifstream inFile("studentMarks.txt");
    if (inFile.is_open()) {
        cout << "Admission Number\tName\tMath\tEnglish\tKiswahili\tScience\tGeography\n";
        cout << "-------------------------------------------------------------------------\n";
        while (!inFile.eof()) {
            Student student;
            inFile >> student.admissionNumber >> student.name;
            if (inFile.fail()) break; // Break loop if reading fails
            cout << student.admissionNumber << "\t\t" << student.name << "\t";
            for (int i = 0; i < 5; ++i) {
                inFile >> student.marks[i];
                cout << student.marks[i] << "\t\t";
            }
            cout << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

void editStudentDetailsFromFile() {
    string admissionNumber;
    cout << "Enter admission number to edit details: ";
    cin >> admissionNumber;

    ifstream inFile("studentMarks.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(admissionNumber) != string::npos) {
                cout << "Student Details:\n" << line << endl;
                inFile.close();
                return;
            }
        }
        cout << "Student with admission number " << admissionNumber << " not found.\n";
        inFile.close();
    } else {
        cout << "Error opening file for reading.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "1. Enter student details\n";
        cout << "2. Display student details\n";
        cout << "3. Exit\n";
        cout << "4. Edit student details\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                cout << "Enter admission number: ";
                cin >> student.admissionNumber;
                cout << "Enter name: ";
                cin >> student.name;
                cout << "Enter marks for 5 subjects: ";
                for (int i = 0; i < 5; ++i) {
                    cin >> student.marks[i];
                }
                saveStudentDetailsToFile(student);
                break;
            }
            case 2:
                displayStudentDetailsFromFile();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            case 4:
                editStudentDetailsFromFile();
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
