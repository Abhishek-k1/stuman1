#include <iostream>
#include <string>
using namespace std;


class Person // Base class
{
protected:      // Accessible inside derived classes
    int id;
    string name;
    int age;

public:
    Person()   // Default constructor
    {
        id = 0;
        name = "Unknown";
        age = 0;
    }

    Person(int i, string n, int a) // parameterized constructor
    {
        id = i;
        name = n;
        age = a;
    }

 // pure virtual functions
    virtual void input() = 0;   
    virtual void display() = 0;

    virtual ~Person()  // virtual destructor
    {
        cout << "\nPerson Destructor Called";
    }
};

class Student : public Person    // Derived class- student
{
private:
    int marks;

public:
    static int totalStudents;  // static data member

    Student() : Person()     // default constructor
    {
        marks = 0;
       // count total students created
    }

    Student(int i, string n, int a, int m) // parameterized constructor
            : Person(i, n, a)
    {
        marks = m;
    
    }

    Student(const Student &s) // copy constructor
    {
        id = s.id;
        name = s.name;
        age = s.age;
        marks = s.marks;
    }

    friend void showMarks(Student s);

/* function overriding
  define input() for student class
*/
    void input()
    {
        cout << "\nEnter Student ID: "; // friend function
        cin >> id;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()   // display function
    {
        cout << "\n----- STUDENT DETAILS -----";
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nMarks: " << marks;
        cout << "\n";
    }

    ~Student()   // destructor
    {
        cout << "\nStudent Destructor Called";
    }
};

int Student::totalStudents = 0;   // static variable definition

void showMarks(Student s)   // friend function
{
    cout << "\nStudent Marks: " << s.marks; // Accessing private member marks
}

class Teacher : public Person    // derived class- teacher
{
private:
    string subject;
    float salary;

public:
    Teacher() : Person()     // default constructor
    {
        subject = "None";
        salary = 0;
    }

    Teacher(int i, string n, int a, string sub, float sal) // parameterized constructor
                : Person(i, n, a)
    {
        subject = sub;
        salary = sal;
    }

    void input()   // input function
    {
        cout << "\nEnter Teacher ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Teacher Name: ";
        getline(cin, name);

        cout << "Age";
        cin >> age;

        cin.ignore();

        cout << "Enter Subject: ";
        getline(cin, subject);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display()   // display function
    {
        cout << "\n------ TEACHER DETAILS ------";
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nSubject: " << subject;
        cout << "\nSalary: " << salary;
        cout << "\n";
    }

    ~Teacher()      // Destructor
    {
        cout << "\nTeacher Destructor Called";
    }
};

int main()     // Main function
{

// array of objects
    Student students[10];
    Teacher teachers[10];

    int studentCount = 0;
    int teacherCount = 0;

    int choice;

// Menu driven loop
    do
    {
        cout << "\n\n===== COLLEGE MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Add Teacher";
        cout << "\n4. Display Teachers";
        cout << "\n5. Show Total Students";
        cout << "\n6. Friend Function Demo";
        cout << "\n7. Dynamic Memory Demo";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Taking student input
            students[studentCount].input();
            studentCount++;
            Student::totalStudents++;
            break;
        }

        case 2:
        {
            // Displaying all students
            for (int i = 0; i < studentCount; i++)
            {
                students[i].display();
            }
            break;
        }

        case 3:
        {
            // taking teacher input
            teachers[teacherCount].input();
            teacherCount++;
            break;
        }

        case 4:
        {
            // Displaying all teachers
            for (int i = 0; i < teacherCount; i++)
            {
                teachers[i].display();
            }
            break;
        }

        case 5:
        {
        // Accessing static variable
            cout << "\nTotal Students: " 
                 << Student::totalStudents;
            break;
        }

        case 6:
        {  
            // friend function demo
            if (studentCount > 0)
            {
                showMarks(students[0]);
            }
            else
            {
                cout << "\nNo Student Available";
            }
            break;
        }

        case 7:
        {

        // Dynamic memory allocation
            Student *ptr = new Student;

            cout << "\nDynamic Object Created";

           // Accessing object using pointer
            ptr->input();
            ptr->display();

            delete ptr;   // Memory  dellocation

            break;
        }

        case 0:
        {
            cout << "\nProgram Exited";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice";
        }
        }

    } while (choice != 0);

    return 0;
}
