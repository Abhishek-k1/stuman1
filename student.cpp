#include <iostream>
using namespace std;
class student {
    private:
    string name;
    int marks[3];
    float average;
    void calculateAverage() {
        average =  (marks[0] + marks[1] + marks[2]) / 3.0;
    }
    public:
    int id;
    static int studentCount;
    student(string n, int m1, int m2, int m3, int i) {
     name = n;
     marks[0] = m1;
     marks[1] = m2;
     marks[2] = m3;
     id = i;
     studentCount++;
     calculateAverage();
    }
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Average Marks: " << average << endl;
        cout << "-------------------" << endl;
    }
    friend void showTopper(student s);
};
    int student::studentCount = 0;
    void showTopper(student s) {
        if (s.average > 80) {
            cout << s.name << " is a Topper!" << endl;
        }
    }
int main() {
    student s[3] = {
        student("Alice", 85, 90, 88, 1),
        student("Bob", 60, 70, 65, 2),
        student("Charlie", 95, 92, 93, 3)
    };
    for (int i = 0; i < 3; i++) {
        s[i].display();
        showTopper(s[i]);
    }
    cout << "Total students: " << student::studentCount << endl;
    return 0;
}