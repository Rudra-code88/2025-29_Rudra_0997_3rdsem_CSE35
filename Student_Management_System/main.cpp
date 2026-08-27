#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string course;
    string email;
};

vector<Student> students;

// Load students from file
void loadStudents()
{
    ifstream file("students.txt");

    Student s;

    while (file >> s.id)
    {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.course);
        getline(file, s.email);

        students.push_back(s);
    }

    file.close();
}

// Save students to file
void saveStudents()
{
    ofstream file("students.txt");

    for (Student s : students)
    {
        file << s.id << endl;
        file << s.name << endl;
        file << s.age << endl;
        file << s.course << endl;
        file << s.email << endl;
    }

    file.close();
}

// Add a student
void addStudent()
{
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    // Check if ID already exists
    for (Student student : students)
    {
        if (student.id == s.id)
        {
            cout << "This Student ID already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter Email: ";
    getline(cin, s.email);

    students.push_back(s);

    saveStudents();

    cout << "\nStudent added successfully!\n";
}

// Display all students
void displayStudents()
{
    if (students.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n----- Student Records -----\n";

    for (Student s : students)
    {
        cout << "\nStudent ID : " << s.id;
        cout << "\nName       : " << s.name;
        cout << "\nAge        : " << s.age;
        cout << "\nCourse     : " << s.course;
        cout << "\nEmail      : " << s.email;
        cout << "\n---------------------------\n";
    }
}

// Update student
void updateStudent()
{
    int id;

    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for (Student &s : students)
    {
        if (s.id == id)
        {
            cin.ignore();

            cout << "Enter new name: ";
            getline(cin, s.name);

            cout << "Enter new age: ";
            cin >> s.age;
            cin.ignore();

            cout << "Enter new course: ";
            getline(cin, s.course);

            cout << "Enter new email: ";
            getline(cin, s.email);

            saveStudents();

            cout << "\nStudent updated successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// Delete student
void deleteStudent()
{
    int id;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students.erase(students.begin() + i);

            saveStudents();

            cout << "\nStudent deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main()
{
    loadStudents();

    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n   STUDENT MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\n==============================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nProgram closed.\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
