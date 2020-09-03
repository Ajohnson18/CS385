/*******************************************************************************
 * Name    : Students.cpp
 * Author  : Alex Johnson
 * Version : 1.0
 * Date    : September 5th, 2019
 * Description : Creates a Student class.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Student {
public:
    // Constructor that uses an initializer list.
    Student(string first, string last, float gpa, int id) : first_{first}, last_{last}, id_{id}, gpa_{gpa} { }

    // Methods that do not modify member variables should be declared const.
    string full_name() const {
        return first_ + " " + last_;
    }

    int id() const {
        return id_;
    }

    float gpa() const {
        return gpa_;
    }

    void print_info() const {
        cout << full_name() << ", GPA: " << fixed
             << setprecision(2) << gpa() << ", ID: " << id() << endl;
    }

private:
    // Member variables (fields). Use the trailing _ for these variables.
    string first_, last_;
    int id_;
    float gpa_;
};

vector<Student> find_failing_students(const vector<Student> &students) {
    vector<Student> failing_students;

    for (const auto &student : students) {
        if (student.gpa() < 1.0) {
            failing_students.push_back(student);
        }
    }

    return failing_students;
}

void print_students(const vector<Student> &students) {
    for (const auto &student : students) {
        student.print_info();
    }
}

int main() {
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;
    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    cout << endl << "All students:" << endl;
    print_students(students);
    cout << endl << "Failing students:";
    // TODO
    // Print a space and the word 'None' on the same line if no students are
    // failing.
    // Otherwise, print each failing student on a separate line.
    if(find_failing_students(students).empty()) {
        cout << " None" << endl;
    } else {
        cout << "\n";
        print_students(find_failing_students(students));
    }
    return 0;
}
