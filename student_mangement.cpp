#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold student data
struct Student {
    int id;
    string name;
    int age;
    float marks;
};

// Function to add a student record
void addStudent(vector<Student>& students) {
    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "\nStudent added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students found.\n";
        return;
    }
    cout << "\nStudent Records:\n";
    cout << "-----------------------------\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << "\n";
        cout << "Name: " << s.name << "\n";
        cout << "Age: " << s.age << "\n";
        cout << "Marks: " << s.marks << "\n";
        cout << "-----------------------------\n";
    }
}

// Function to search for a student by ID
void searchStudent(const vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;

    bool found = false;
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Age: " << s.age << "\n";
            cout << "Marks: " << s.marks << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent with ID " << id << " not found.\n";
    }
}

// Function to update student information
void updateStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;

    bool found = false;
    for (auto& s : students) {
        if (s.id == id) {
            cout << "\nEnter New Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter New Age: ";
            cin >> s.age;
            cout << "Enter New Marks: ";
            cin >> s.marks;
            cout << "\nStudent record updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent with ID " << id << " not found.\n";
    }
}

// Function to delete a student record
void deleteStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "\nStudent record deleted successfully!\n";
            return;
        }
    }

    cout << "\nStudent with ID " << id << " not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Info\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice(1 to 6): ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: deleteStudent(students); break;
            case 6: cout << "\nExiting the program. Goodbye!\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}